import torch
import torch.nn as nn
from huffman import HuffmanTree
from adahuffman import Ada_HuffmanTree
from collections import Counter
import time
from tqdm import tqdm
from utils import make_context_vector


# CBOW model with hierarchical softmax optimization

class CBOWHierarchicalSoftmax(nn.Module):
    def __init__(self, training_data, embedding_dim, device):
        super(CBOWHierarchicalSoftmax, self).__init__()

        tokens_freqs = Counter(training_data)  # 得到文章中每个单词出现的次数
        self.word_size = len(tokens_freqs)  # 词汇表大小
        self.huffman_tree = HuffmanTree(tokens_freqs, embedding_dim, self.word_size)
        self.huffman_codes = self.huffman_tree.generate_codes()
        self.training_data = training_data
        self.word_set = set(training_data)

        # 有了这两个映射，我们才能通过输出层预测结果
        self.word_to_ix = {word: ix for ix, word in enumerate(self.word_set)}
        self.ix_to_word = {ix: word for ix, word in enumerate(self.word_set)}


        self.decoder = {code: token for token, code in self.huffman_codes}
        self.embedding_dim = embedding_dim
        self.device = device
        self.embeddings = torch.randn(self.word_size, embedding_dim).to(self.device)  # 定义词向量矩阵
        self.thetas = []  # 定义当前word的所有theta
        self.x_w = torch.randn(embedding_dim, 1)  # 定义x_w, 也就是当前word的上下文词向量求和

        # 记录loss的列表，用于画图
        self.Words_Loss = [0 for i in range(self.word_size)]
        self.Words_Process_Loss = [[] for i in range(self.word_size)]

    def reinit(self,training_data,embedding_dim,device):
        tokens_freqs = Counter(training_data)  # 得到文章中每个单词出现的次数
        self.word_size = len(tokens_freqs)  # 词汇表大小
        self.huffman_tree = HuffmanTree(tokens_freqs, embedding_dim, self.word_size)
        self.huffman_codes = self.huffman_tree.generate_codes()
        self.training_data = training_data
        self.word_set = set(training_data)
        # 有了这两个映射，我们才能通过输出层预测结果
        self.word_to_ix = {word: ix for ix, word in enumerate(self.word_set)}
        self.ix_to_word = {ix: word for ix, word in enumerate(self.word_set)}
        self.decoder = {code: token for token, code in self.huffman_codes}
        self.embedding_dim = embedding_dim
        self.device = device
        self.embeddings = torch.randn(self.word_size, embedding_dim).to(self.device)  # 定义词向量矩阵
        self.thetas = []  # 定义当前word的所有theta
        self.x_w = torch.randn(embedding_dim, 1)  # 定义x_w, 也就是当前word的上下文词向量求和

        # 记录loss的列表，用于画图
        self.Words_Loss = [0 for i in range(self.word_size)]
        self.Words_Process_Loss = [[] for i in range(self.word_size)]


    def loss_f(self, context_vector, target):
        if target not in self.huffman_tree.token2node.keys():
            return False
        self.x_w = sum(self.embeddings[context_vector]).view(1, -1)  # 将上下文词向量求和，然后转换成1*V的形式

        self.x_w.to(self.device)  # 将x_w放到GPU上
        token = target
        code = self.huffman_tree.token2node[token].code
        node = self.huffman_tree.root
        if node is None:
            print("node is None")
        Loss = 0

        self.thetas = []

        for j, d in enumerate(code):

            self.thetas.append(node.theta)  # 将当前word的所有theta存储起来
            if d == '1':
                node = node.left_child
            else:
                node = node.right_child

        for j in range(len(code)):
            d_jw = torch.tensor(int(code[j]))  #
            t = torch.log(torch.sigmoid(self.x_w.matmul(self.thetas[j])))
            # print("在{}的loss_f函数的第{}轮中".format(target,j))
            #
            # print("d_jw is {} | torch.log is {}".format(d_jw,t))

            Loss += (1 - d_jw) * t + d_jw * (1 - t)

        return Loss

    def forward(self, context_vector):  # 预测的方式可能还有问题？
        x_w = sum(self.embeddings[context_vector]).view(1, -1)  # 将上下文词向量求和，然后转换成1*V的形式

        node = self.huffman_tree.root
        while node is not None:
            if node.left_child is None and node.right_child is None:  # 如果是叶子节点，就返回
                break
            else:
                if x_w.matmul(node.theta) < 0:  # 如果x_w * theta < 0, 就往左走
                    node = node.left_child
                else:
                    node = node.right_child
        code = node.code

        res_toke = self.decoder[code]
        res_ix = self.word_to_ix[res_toke]
        return res_ix, res_toke  # 返回的是预测的目标词的下标和词

    # 训练
    def train(self, text_data=None, epochs_num=5, lr=0.01,require_info = False):
        if (text_data == None):
            text_data = self.training_data
        epochs = tqdm(range(epochs_num))
        t0 = time.time()
        for _ in epochs:
            for context, target in text_data:
                # 这里的向量长度为4，因为我们的窗口就是上下2个单词
                context_vector = make_context_vector(context, self.word_to_ix)
                # 损失函数
                loss = self.loss_f(context_vector, target)
                if loss == False:
                    continue
                epochs.set_postfix(epoch=_, target=target, loss=loss)
                self.Words_Loss[self.word_to_ix[target]] = loss
                self.Words_Process_Loss[self.word_to_ix[target]].append(loss)

                code = self.huffman_tree.token2node[target].code
                self.x_w.to(self.device)  # 将x_w放到GPU上
                optimizer = MyOptimizer(self.thetas, self.x_w, self.embeddings, context_vector, code, lr=lr)
                optimizer.step()
                # prediction_ix, prediction_token = cbow_model(context_vector)
        t1 = time.time()
        if require_info:
            print(f'训练时间: {t1 - t0}s\n')
        return t1 - t0

    # 预测
    def predict(self, text_data,require_info = False):
        correct_rate = 0
        t0 = time.time()
        for context, target in text_data:
            # print(context, target)
            context_vector = make_context_vector(context, self.word_to_ix)
            prediction_ix, prediction_token = self.forward(context_vector)
            if prediction_token == target:
                correct_rate += 1
            # print(f'预测: {context}\n')
            # print(f'预测结果: {prediction_token}\n')
            # print(f'真实结果: {target}\n')
            # print('\n')

        t1 = time.time()
        if require_info:
            print(f'预测花费时间: {t1 - t0}s\n')
            print(f'正确率: {correct_rate / len(text_data) * 100}%\n')
        return t1 - t0, correct_rate / len(text_data) * 100

    def update_new_data(self, text_data):
        new_text_data = [x for x in text_data if x not in self.word_set]  # 更新文本
        new_word_set = set(new_text_data)  # 更新单词集合
        # 如果新的单词集合是原来单词集合的子集，就不更新
        if new_word_set.issubset(self.word_set):
            return
        new_word_size = len(new_word_set)

        self.word_set = new_word_set.union(self.word_set)  # 更新单词集合
        self.word_size = len(self.word_set)  # 更新单词集合大小

        new_words_freqs = Counter(new_text_data)  # 更新单词频率
        new_tree = HuffmanTree(new_words_freqs, self.embedding_dim, new_word_size)  # 为不在原来的单词集合里的单词生成新的Huffman树

        new_root = new_tree.root  # 得到不在原来单词集合里的单词的huffman树的根节点

        shortest_node = self.huffman_tree.get_shortest_path_node()  # 得到旧的Huffman树的最短路径节点
        shortest_node.left_child = new_root.left_child
        shortest_node.right_child = new_root.right_child
        new_tree.root = shortest_node  # 更新根节点
        new_tree.generate_codes()  # 生成不在原来单词集中的单词的编码

        # 不在原来单词集中的单词的最终编码要加上原huffman的最短路径节点的编码
        for token in new_tree.token2node.keys():
            new_tree.token2node[token].code = new_tree.root.code + new_tree.token2node[token].code

        self.huffman_tree.token2node.update(new_tree.token2node)  # 更新单词到节点的映射
        self.huffman_tree.token2node.pop(shortest_node.token)  # 删除最短路径节点
        self.huffman_tree.get_shortest_path_node(update=True)  # 更新最短路径节点

        self.huffman_codes = self.huffman_tree.from_token2node_generate_codes()  # 更新编码
        self.huffman_tree.all_nodes = list(set(self.huffman_tree.all_nodes).union(set(new_tree.all_nodes)))  # 更新所有节点
        # 更新decoder
        self.huffman_tree.decoder = {code: token for token, code in self.huffman_codes}
        self.decoder = self.huffman_tree.decoder
        # 更新单词集合大小
        self.huffman_tree.wordsize = self.word_size
        # 更新词向量映射
        origin_len = len(self.word_to_ix)
        new_word_list = list(new_word_set)
        for i in range(len(new_word_list)):
            self.word_to_ix[new_word_list[i]] = i + origin_len
            self.ix_to_word[i + origin_len] = new_word_list[i]

        # 更新loss,用于绘图
        self.Words_Loss = self.Words_Loss + [0 for i in range(new_word_size)]
        self.Words_Process_Loss = self.Words_Process_Loss + [[] for i in range(new_word_size)]

        # 更新词向量矩阵的行数，因为有新的单词加入
        self.embeddings = \
            nn.Parameter(
                torch.cat(
                    (self.embeddings, torch.randn(
                        new_word_size, self.embedding_dim)
                     ),
                    0
                )
            )

        return


class MyOptimizer():
    def __init__(self, thetas, x_w, embedding, context_vector, code, lr=0.01):
        # thetas就是当前单词的Huffman路径上每个节点的theta向量；embedding是词向量构成的矩阵；context_vector；code是这个单词的huffman编码；lr是学习率；context_vector是上下文单词的索引,长度为4
        self.lr = lr
        self.code = code
        self.thetas = thetas
        self.x_w = x_w
        self.context_vector = context_vector
        self.embedding = embedding  # 词向量矩阵

    def step(self):

        for i in range(len(self.thetas)):  # thetas[0]才是单层列表
            d_jw = torch.tensor(int(self.code[i]))  # 当前单词w的huffman路径上的第j个码字，也就是w对应的code里的第j位
            theta_grad = (1 - d_jw - torch.sigmoid(self.x_w.matmul(self.thetas[i]))) * self.x_w  # theta的梯度
            self.thetas[i] = self.thetas[i] + theta_grad.T * self.lr  # 更新 theta的梯度
        # 以下更新方式见下面的算法
        e = 0
        for i in range(len(self.thetas)):
            d_jw = torch.tensor(int(self.code[i]))
            q = torch.sigmoid(self.x_w.matmul(self.thetas[i]))
            g = self.lr * (1 - d_jw - q)
            e = e + g * self.thetas[i]
            self.thetas[i] = self.thetas[i] + g * self.x_w
        e = e.T

        with torch.no_grad():
            for k in self.context_vector:
                self.embedding[k] = self.embedding[k] + e


class Ada_CBOWHierarchicalSoftmax(nn.Module):
    def __init__(self, training_data, embedding_dim, device):
        super(Ada_CBOWHierarchicalSoftmax, self).__init__()

        tokens_freqs = Counter(training_data)  # 得到文章中每个单词出现的次数
        self.word_size = len(tokens_freqs)  # 词汇表大小
        self.word_set = set(training_data)
        self.huffman_tree = Ada_HuffmanTree(embedding_dim, self.word_size)  # 初始化树

        self.huffman_tree.addTokens(tokens_freqs)  # 创建树
        self.huffman_codes = self.huffman_tree.generate_codes()
        self.training_data = training_data

        # 有了这两个映射，我们才能通过输出层预测结果
        self.word_to_ix = {word: ix for ix, word in enumerate(self.word_set)}
        self.ix_to_word = {ix: word for ix, word in enumerate(self.word_set)}

        self.decoder = {code: token for token, code in self.huffman_codes}
        self.embedding_dim = embedding_dim
        self.device = device
        self.embeddings = torch.randn(self.word_size, embedding_dim).to(self.device)  # 定义词向量矩阵
        self.thetas = []  # 定义当前word的所有theta
        self.x_w = torch.randn(embedding_dim, 1)  # 定义x_w, 也就是当前word的上下文词向量求和

        # 记录loss的列表，用于画图
        self.Words_Loss = [0 for i in range(self.word_size)]
        self.Words_Process_Loss = [[] for i in range(self.word_size)]

    def update_new_data(self, add_train_data):  # 用于后续数据的添加
        new_text_data = [x for x in add_train_data if x not in self.word_set]  # 更新文本
        new_word_set = set(new_text_data)  # 更新单词集合
        # 如果新的单词集合是原来单词集合的子集，就不更新
        if new_word_set.issubset(self.word_set):
            return
        new_word_size = len(new_word_set)

        tokens_freqs = Counter(add_train_data)
        self.huffman_tree.addTokens(tokens_freqs)

        self.word_set = self.word_set.union(set(add_train_data))  # 更新单词集合
        self.word_size = len(self.word_set)  # 更新单词集合大小

        self.huffman_codes = self.huffman_tree.generate_codes()  # 更新codes ，更新树里面单词到节点的映射
        self.decoder = {code: token for token, code in self.huffman_codes}  # 更新deocder

        origin_len = len(self.word_to_ix)
        new_word_list = list(new_word_set)
        for i in range(len(new_word_list)):
            self.word_to_ix[new_word_list[i]] = i + origin_len
            self.ix_to_word[i + origin_len] = new_word_list[i]

        # 更新loss,用于绘图
        self.Words_Loss = self.Words_Loss + [0 for i in range(new_word_size)]
        self.Words_Process_Loss = self.Words_Process_Loss + [[] for i in range(new_word_size)]

        # 更新词向量矩阵的行数，因为有新的单词加入
        self.embeddings = \
            nn.Parameter(
                torch.cat(
                    (self.embeddings, torch.randn(
                        new_word_size, self.embedding_dim)
                     ),
                    0
                )
            )
        # print("word_size",self.word_size)
        # print("embeddings",self.embeddings.shape)
        # print("word_to_ix",len(self.word_to_ix))
        # print("ix_to_word",len(self.ix_to_word))
        # print("word_Set",len(self.word_set))

    def get_change_nodes(self):  # 用于获得修改位置过的node list
        return self.huffman_tree.change_nodes

    def clear_change_nodes(self):  # 用于清空记录位置修改的node list
        self.huffman_tree.clear_change_list()

    def loss_f(self, context_vector, target):
        self.x_w = sum(self.embeddings[context_vector]).view(1, -1)  # 将上下文词向量求和，然后转换成1*V的形式

        self.x_w.to(self.device)  # 将x_w放到GPU上
        token = target
        code = self.huffman_tree.token2node[token].code
        node = self.huffman_tree.root

        Loss = 0

        self.thetas = []

        for j, d in enumerate(code):

            self.thetas.append(node.theta)  # 将当前word的所有theta存储起来
            if d == '1':
                node = node.left_child
            else:
                node = node.right_child

        for j in range(len(code)):
            d_jw = torch.tensor(int(code[j]))  #
            t = torch.log(torch.sigmoid(self.x_w.matmul(self.thetas[j])))
            # print("在{}的loss_f函数的第{}轮中".format(target,j))
            #
            # print("d_jw is {} | torch.log is {}".format(d_jw,t))

            Loss += (1 - d_jw) * t + d_jw * (1 - t)

        return Loss

    def forward(self, context_vector):  # 预测的方式可能还有问题？
        x_w = sum(self.embeddings[context_vector]).view(1, -1)  # 将上下文词向量求和，然后转换成1*V的形式

        node = self.huffman_tree.root
        while node is not None:
            if node.left_child is None and node.right_child is None:  # 如果是叶子节点，就返回
                break
            else:
                if x_w.matmul(node.theta) < 0:  # 如果x_w * theta < 0, 就往左走
                    node = node.left_child
                else:
                    node = node.right_child
        code = node.code
        # 如果code不在字典里，说明这个节点是辅助节点，预测错误了！
        if code not in self.decoder.keys():
            return None, None
        res_toke = self.decoder[code]
        res_ix = self.word_to_ix[res_toke]
        return res_ix, res_toke  # 返回的是预测的目标词的下标和词

    def train(self, text_data=None, epochs_num=5, lr=0.01, require_info = False):
        if text_data is None:
            text_data = self.training_data
        epochs = tqdm(range(epochs_num))
        t0 = time.time()
        for _ in epochs:
            for context, target in text_data:
                # 这里的向量长度为4，因为我们的窗口就是上下2个单词
                context_vector = make_context_vector(context, self.word_to_ix)
                # 损失函数
                loss = self.loss_f(context_vector, target)
                epochs.set_postfix(target=target, loss=loss)
                self.Words_Loss[self.word_to_ix[target]] = loss
                self.Words_Process_Loss[self.word_to_ix[target]].append(loss)

                code = self.huffman_tree.token2node[target].code
                self.x_w.to(self.device)  # 将x_w放到GPU上
                optimizer = MyOptimizer(self.thetas, self.x_w, self.embeddings, context_vector, code, lr=lr)
                optimizer.step()
                # prediction_ix, prediction_token = cbow_model(context_vector)
        t1 = time.time()
        if require_info:
            print(f'训练时间: {t1 - t0}s\n')
        return t1 - t0

    def predict(self, text_data, require_info = False):
        # 预测
        correct_rate = 0
        t0 = time.time()
        for context, target in text_data:
            # print(context, target)
            context_vector = make_context_vector(context, self.word_to_ix)
            prediction_ix, prediction_token = self.forward(context_vector)
            if prediction_token == target:
                correct_rate += 1
            # print(f'预测: {context}\n')
            # print(f'预测结果: {prediction_token}\n')
            # print(f'真实结果: {target}\n')
            # print('\n')

        t1 = time.time()
        if require_info:
            print(f'预测时间: {t1 - t0}s\n')
            print(f'正确率: {correct_rate / len(text_data) * 100}%\n')
        return t1 - t0, correct_rate / len(text_data) * 100


