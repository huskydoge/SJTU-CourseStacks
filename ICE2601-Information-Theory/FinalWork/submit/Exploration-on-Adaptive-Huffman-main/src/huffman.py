import heapq
import torch
from tqdm import tqdm
import numpy as np

# Huffman tree node class
class HuffmanNode:
    def __init__(self, freq, token=None, left_child=None, right_child=None, embed_dim=0, wordsize=0):
        self.embed_dim = embed_dim  # 词向量维度
        self.code = None
        self.freq = freq
        self.token = token
        self.theta = torch.randn(self.embed_dim, 1)  # 每个节点都有对应wordsize个词向量的theta，theta的大小是 embed_dim * 1

        self.left_child = left_child
        self.right_child = right_child

    def __lt__(self, other):
        return self.freq < other.freq


# Huffman tree class
class HuffmanTree:
    def __init__(self, tokens_freqs, embed_dim, wordsize):
        self.codes = None # 用于存储每个token的Huffman编码
        self.shortestPathNode = None # 用于存储最短路径节点
        self.decoder = None
        self.encoder = None
        self.root = None
        self.embed_dim = embed_dim
        self.wordsize = wordsize
        self.all_nodes = []
        self.nodes = [] # 这个list是用作生成huffmancode的heap，一次性的！
        self.token2node = {}  # 单词到node的映射
        p = tqdm(tokens_freqs.items())
        p.set_description('Building Huffman Tree')
        for token, freq in p:
            node = HuffmanNode(freq, token, embed_dim=self.embed_dim, wordsize=self.wordsize)
            # heapq.heappush(self.nodes, node)  # Push the node into the heap
            self.nodes.append(node)
            self.token2node[token] = node
            self.all_nodes.append(node)

        while len(self.nodes) > 1:
            # node1 = heapq.heappop(self.nodes)
            # node2 = heapq.heappop(self.nodes)
            node1 = self.find_min_node()
            node2 = self.find_min_node()
            new_node = HuffmanNode(node1.freq + node2.freq, None, node1, node2, embed_dim=self.embed_dim,
                                   wordsize=self.wordsize)
            # heapq.heappush(self.nodes, new_node)
            self.nodes.append(new_node)
            self.all_nodes.append(new_node)
        self.root = self.nodes[-1]  # The last node in the heap is the root of the Huffman tree

    # Traversing the Huffman Tree and generating codes for each token
    def generate_codes(self, node=None, code=''):
        if node is None:
            node = heapq.heappop(self.nodes)

        if node.token is not None:
            self.token2node[node.token].code = code
            return [(node.token, code)]

        codes = []
        if node.left_child:
            codes.extend(self.generate_codes(node.left_child, code + '1'))
        if node.right_child:
            codes.extend(self.generate_codes(node.right_child, code + '0'))
        return codes

    def find_min_node(self):
        min_node = self.nodes[0]
        for node in self.nodes:
            if node.freq < min_node.freq:
                min_node = node
        self.nodes.remove(min_node)
        return min_node
    def get_shortest_path_node(self,update=False):
        if self.shortestPathNode is not None and update is False:
            return self.shortestPathNode
        else:
            m = np.Inf
            for key in self.token2node.keys():
                length = len(self.token2node[key].code)
                if length < m:
                    m = length
                    self.shortestPathNode = self.token2node[key]
            return self.shortestPathNode

    def from_token2node_generate_codes(self):
        codes = []
        for key in self.token2node.keys():
            codes.append((key, self.token2node[key].code))
        self.codes = codes
        return codes

    def update_word_size(self, new_word_size):
        self.wordsize = new_word_size
        for node in self.all_nodes:
            node.update_thetas(self.wordsize)
        return self.wordsize

