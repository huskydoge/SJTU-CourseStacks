import re


# 定义一个函数，用于处理文本
def processText(text):
    text = text.lower()
    remove_chars = '[·’!"\#$%&\'()＃！（）*+,-./:;<=>?\@，：?￥★、…．＞【】［］《》？“”‘’\[\\]^_`{|}~]+'  # 去除标点符号
    text = re.sub(remove_chars, "", text)
    text = text.split()
    return text


# 定义一个函数，把文本转换成索引的形式
def make_context_vector(context, word_to_ix):  # context是上下文单词列表，word_to_ix是单词到索引的映射
    idxs = [word_to_ix[w] for w in context]  # 将上下文单词转换成索引的形式
    return idxs  # 返回的是tensor

# 定义一个函数，用于生成训练数据
def get_batch(text):
    # text 是分词好的文本list
    train_data = []
    for i in range(2, len(text) - 2):
        context = [text[i - 2], text[i - 1],  # 根据上下文预测目标词汇，窗口大小为4
                   text[i + 1], text[i + 2]]
        target = text[i]
        train_data.append((context, target))
    return train_data

# 定义一个函数，用于加载数据
def data_loader(filepath):
    with open(filepath, 'r') as f:
        txt = f.read()
    return txt
