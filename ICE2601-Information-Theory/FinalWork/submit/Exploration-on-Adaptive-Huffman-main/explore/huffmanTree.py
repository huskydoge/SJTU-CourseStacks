# from node import Node
# from queue import Queue


# class HuffmanTree:
#     def __init__(self, buffer_size=1,fenci = False):
#         self.root = Node()
#         self.bytes = {}
#         self.emptyNode = self.root
#         self.buffer_size = buffer_size
#         self.counter = 0
#         self.fenci = fenci
        


#     def exist(self, char):
#         return char in self.bytes

#     def addChar(self, char):
#         node = Node(char)
#         self.bytes[char] = node
#         self.emptyNode.setLeft(Node())
#         self.emptyNode.setRight(node)
#         self.emptyNode = self.emptyNode.left

# # encode
#     def encode(self, file):
#         char_buffer = b''
#         char = b''
#         code_output = ''

#         for i in range(self.buffer_size):

#             char = file.read(self.buffer_size)
#             if char == b'':
#                 return b''
            
            
#             if not self.exist(char):
#                 code = self.huffmanCode(self.emptyNode)
#                 for i in range(len(char)):
#                     code += '{0:08b}'.format(char[i])  # binary
#                 self.addChar(char)
#             else:
#                 node = self.bytes[char]
#                 code = self.huffmanCode(node)

#             self.updateTree(self.bytes[char])

#             char_buffer += char
#         for i in range(self.buffer_size):
#             node = self.bytes[char]
#             code = self.huffmanCode(node)
#             code_output += code

#         return code_output

#     def endOfFile(self):
#         return self.huffmanCode(self.emptyNode)

#     def huffmanCode(self, node):
#         code = ''
#         if node == self.root:
#             return '0'
#         parent = node.parent
#         while parent:
#             if parent.left == node:
#                 code += '0'
#             else:
#                 code += '1'
#             node = parent
#             parent = node.parent

#         return code[::-1]  # reverse

#     def findFarthestNode(self, weight):
#         q = Queue()
#         q.put(self.root)
#         while not q.empty():
#             node = q.get()
#             if node.weight == weight:
#                 return node
#             if node.right:
#                 q.put(node.right)
#             if node.left:
#                 q.put(node.left)

#     def updateTree(self, node):
#         while node:
#             node.swap(self.findFarthestNode(node.weight))
#             node.weight += 1
#             node = node.parent


# # decode
#     def decode(self, file):
#         if self.counter <= 0:
#             return ''
#         node = self.reHuffmanCode(file)
#         if node == self.emptyNode:
#             code = ''
#             for i in range(self.order):
#                 code += file.read(8)

#             char = b''
#             for i in range(int(len(code)/8)):
#                 ch = int(code[i*8:i*8+8], 2)
#                 char += ch.to_bytes(1, byteorder='little')
#             self.addChar(char)
#         else:
#             char = node.char
#         self.updateTree(self.bytes[char])
#         self.counter -= len(char)
#         return char

#     def reHuffmanCode(self, file):
#         if self.root.hasNoChild():
#             file.read(1)
#             return self.root

#         node = self.root
#         while not node.hasNoChild():
#             ch = file.read(1)
#             if ch == '1':
#                 node = node.right
#             elif ch == '0':
#                 node = node.left
#             else:
#                 return self.emptyNode

#         return node

#     def printTree(self):
#         print('------tree------')
#         q = Queue()
#         q.put(self.root)
#         level = 0
#         while not q.empty():
#             node = q.get()
#             if node.level > level:
#                 level = node.level
#                 print()
#             print('%s:%s' % (node.weight, str(node.char)), end=' ')
#             if node.left:
#                 q.put(node.left)
#             if node.right:
#                 q.put(node.right)
#         print('\n')


from node import Node



from queue import Queue



class HuffmanTree:
    def __init__(self, order=1):
        self.root = Node()
        self.bytes = {}
        self.emptyNode = self.root
        self.order = order
        self.counter = 0

    def exist(self, char):
        return char in self.bytes

    def addChar(self, char):
        node = Node(char)
        self.bytes[char] = node
        self.emptyNode.setLeft(Node())
        self.emptyNode.setRight(node)
        self.emptyNode = self.emptyNode.left

# encode
    def encode(self, file):
        char = b''
        char = file.read(self.order)
        if char == b'':
            return b''

        if not self.exist(char):
            code = self.huffmanCode(self.emptyNode)
            for i in range(len(char)):
                code += '{0:08b}'.format(char[i])  # binary
            self.addChar(char)
        else:
            node = self.bytes[char]
            code = self.huffmanCode(node)

        self.updateTree(self.bytes[char])
        return code

    def endOfFile(self):
        return self.huffmanCode(self.emptyNode)

    def huffmanCode(self, node):
        code = ''
        if node == self.root:
            return '0'
        parent = node.parent
        while parent:
            if parent.left == node:
                code += '0'
            else:
                code += '1'
            node = parent
            parent = node.parent

        return code[::-1]  # reverse

    def findFarthestNode(self, weight):
        q = Queue()
        q.put(self.root)
        while not q.empty():
            node = q.get()
            if node.weight == weight:
                return node
            if node.right:
                q.put(node.right)
            if node.left:
                q.put(node.left)

    def updateTree(self, node):
        while node:
            node.swap(self.findFarthestNode(node.weight))
            node.weight += 1
            node = node.parent


# decode
    def decode(self, file):
        if self.counter <= 0:
            return ''
        node = self.reHuffmanCode(file)
        if node == self.emptyNode:
            code = ''
            for i in range(self.order):
                code += file.read(8)

            char = b''
            for i in range(int(len(code)/8)):
                ch = int(code[i*8:i*8+8], 2)
                char += ch.to_bytes(1, byteorder='little')
            self.addChar(char)
        else:
            char = node.char
        self.updateTree(self.bytes[char])
        self.counter -= len(char)
        return char

    def reHuffmanCode(self, file):
        if self.root.hasNoChild():
            file.read(1)
            return self.root

        node = self.root
        while not node.hasNoChild():
            ch = file.read(1)
            if ch == '1':
                node = node.right
            elif ch == '0':
                node = node.left
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
            print('%s:%s' % (node.weight, str(node.char)), end=' ')
            if node.left:
                q.put(node.left)
            if node.right:
                q.put(node.right)
        print('\n')

class HuffmanTree_Buffer:
    def __init__(self, order=64):
        self.root = Node()
        self.bytes = {}
        self.emptyNode = self.root
        self.order = order
        self.counter = 0
        self.First= {}

    def exist(self, char):
        return char in self.bytes

    def addChar(self, char):
        node = Node(char)
        self.bytes[char] = node
        self.emptyNode.setLeft(Node())
        self.emptyNode.setRight(node)
        self.emptyNode = self.emptyNode.left

# encode
    def encode(self, file):
        char_buffer = []
        
        for p in range(self.order):
                
            char = b''
            char = file.read(1)
            if char == b'':
                break
                # return b''

            if not self.exist(char):
                code = self.huffmanCode(self.emptyNode)
                self.First[char] = True
                for i in range(len(char)):
                    code += '{0:08b}'.format(char[i])  # binary
                self.addChar(char)
            else:
                node = self.bytes[char]
                code = self.huffmanCode(node)

            self.updateTree(self.bytes[char])
            char_buffer.append(char)
        code = ''

        for char in (char_buffer):
            if char == b'':
                continue
            if self.First[char] == True:
                for m in range(len(char)):

                    code += '{0:08b}'.format(char[i])
                    self.First[char] = False
            else:
                node = self.bytes[char]
                code += self.huffmanCode(node)
        if len(char_buffer) == 0:
            return b''

        return code

    def endOfFile(self):
        return self.huffmanCode(self.emptyNode)

    def huffmanCode(self, node):
        code = ''
        if node == self.root:
            return '0'
        parent = node.parent
        while parent:
            if parent.left == node:
                code += '0'
            else:
                code += '1'
            node = parent
            parent = node.parent

        return code[::-1]  # reverse

    def findFarthestNode(self, weight):
        q = Queue()
        q.put(self.root)
        while not q.empty():
            node = q.get()
            if node.weight == weight:
                return node
            if node.right:
                q.put(node.right)
            if node.left:
                q.put(node.left)

    def updateTree(self, node):
        while node:
            node.swap(self.findFarthestNode(node.weight))
            node.weight += 1
            node = node.parent


# decode
    def decode(self, file):
        if self.counter <= 0:
            return ''
        node = self.reHuffmanCode(file)
        if node == self.emptyNode:
            code = ''
            for i in range(self.order):
                code += file.read(8)

            char = b''
            for i in range(int(len(code)/8)):
                ch = int(code[i*8:i*8+8], 2)
                char += ch.to_bytes(1, byteorder='little')
            self.addChar(char)
        else:
            char = node.char
        self.updateTree(self.bytes[char])
        self.counter -= len(char)
        return char

    def reHuffmanCode(self, file):
        if self.root.hasNoChild():
            file.read(1)
            return self.root

        node = self.root
        while not node.hasNoChild():
            ch = file.read(1)
            if ch == '1':
                node = node.right
            elif ch == '0':
                node = node.left
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
            print('%s:%s' % (node.weight, str(node.char)), end=' ')
            if node.left:
                q.put(node.left)
            if node.right:
                q.put(node.right)
        print('\n')

