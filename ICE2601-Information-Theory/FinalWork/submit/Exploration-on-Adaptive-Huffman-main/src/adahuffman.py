import heapq
import torch
from queue import Queue


# Adaptive Huffman tree node class

class Ada_Node:
    def __init__(self, freq=1, token=None, left_child=None, right_child=None, embed_dim=0, wordsize=0):

        self.weight = 0
        self.code = None

        self.embed_dim = embed_dim
        self.theta = torch.randn(self.embed_dim, 1)  # 每个节点都有对应wordsize个词向量的theta，theta的大小是 embed_dim * 1

        self.parent = None
        self.right_child = left_child
        self.left_child = right_child

        self.level = 0
        if token is None:
            self.token = b'*'
        else:
            self.token = token

    # 设置该节点的左孩子为node
    def setLeft(self, node):
        self.left_child = node
        node.parent = self
        node.updateLevel()

    # 设置该节点的右孩子为node
    def setRight(self, node):
        self.right_child = node
        node.parent = self
        node.updateLevel()

    # 把该节点为child的孩子节点换成node
    def replaceChild(self, child, node):
        if self.left_child == child:
            self.setLeft(node)
        elif self.right_child == child:
            self.setRight(node)

    # 更新该节点所在子树的level
    def updateLevel(self):
        self.level = self.parent.level + 1
        if self.right_child:
            self.right_child.updateLevel()
        if self.left_child:
            self.left_child.updateLevel()

    # 该节点没有孩子
    def hasNoChild(self):
        return self.left_child is None and self.right_child is None

    # node是该节点的祖先
    def isAncestor(self, node):
        ancestor = self.parent
        while ancestor:
            if ancestor == node:
                return True
            ancestor = ancestor.parent
        return False

    # 交换该节点与node的位置
    def swap(self, node, change_nodes):
        if self == node or node.isAncestor(self) or self.isAncestor(node):
            return
        change_nodes.append(node)
        change_nodes.append(self)
        parent1 = self.parent
        parent2 = node.parent
        parent2.replaceChild(node, self)
        parent1.replaceChild(self, node)


class Ada_HuffmanTree:
    def __init__(self, embed_dim, word_size):
        self.root = Ada_Node(embed_dim=embed_dim, wordsize=word_size)
        self.token2node = {}
        self.emptyNode = self.root
        self.nodes = []
        self.decoder = None
        self.embed_dim = embed_dim
        self.word_size = word_size
        self.change_nodes = []
        self.nodes.append(self.root)
        self.counter = 0

    def clear_change_list(self):  # 清空标注交换node的列表
        self.change_nodes = []

    def exist(self, token):
        return token in self.token2node

    def addChar(self, token):
        node = Ada_Node(token=token, embed_dim=self.embed_dim, wordsize=self.word_size)
        self.token2node[token] = node
        self.nodes.append(node)
        self.emptyNode.setLeft(Ada_Node(embed_dim=self.embed_dim, wordsize=self.word_size))
        self.emptyNode.setRight(node)
        self.emptyNode = self.emptyNode.left_child

    def addTokens(self, tokens_freqs):
        for token, freq in tokens_freqs.items():
            for i in range(freq):
                if not self.exist(token):
                    self.addChar(token)
                self.updateTree(self.token2node[token])

    def generate_codes(self):
        codes = []
        for token in self.token2node.keys():
            codes.append((token, self.huffmanCode(self.token2node[token])))
            self.token2node[token].code = self.huffmanCode(self.token2node[token])
        # print(codes)
        return codes

    def endOfFile(self):
        return self.huffmanCode(self.emptyNode)

    def huffmanCode(self, node):
        code = ''
        if node == self.root:
            return '0'
        parent = node.parent
        while parent:
            if parent.left_child == node:
                code += '1'
            else:
                code += '0'
            node = parent
            parent = node.parent

        return code[::-1]  # reverse

    # 找到权重为weight最远的节点（即最右边的，也就是最小的，因为我们这里是以右边为0），用于替换
    def findFarthestNode(self, weight):
        q = Queue()
        q.put(self.root)
        while not q.empty():
            node = q.get()
            if node.weight == weight:
                return node
            if node.right_child:
                q.put(node.right_child)
            if node.left_child:
                q.put(node.left_child)

    def updateTree(self, node):
        while node:
            node.swap(self.findFarthestNode(node.weight), self.change_nodes)
            node.weight += 1
            node = node.parent

    def reHuffmanCode(self, file):
        if self.root.hasNoChild():
            file.read(1)
            return self.root

        node = self.root
        while not node.hasNoChild():
            ch = file.read(1)
            if ch == '1':
                node = node.right_child
            elif ch == '0':
                node = node.left_child
            else:
                return self.emptyNode

        return node

    def printTree(self):
        print('------tree------')
        q = Queue()
        q.put(self.root)
        level = 0
        while not q.empty():
            node = q.get()
            if node.level > level:
                level = node.level
                print()
            print('%s:%s' % (node.weight, str(node.token)), end=' ')
            if node.left:
                q.put(node.left_child)
            if node.right:
                q.put(node.right_child)
        print('\n')
