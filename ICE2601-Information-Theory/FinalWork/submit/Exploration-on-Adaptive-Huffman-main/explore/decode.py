import os
from bitStream import BitStream
from huffmanTree import HuffmanTree


class Decoder:
    def __init__(self):
        self.tree = HuffmanTree(1)

    def decodeFile(self, fileName, outFileName):
        if not os.path.exists(fileName):
            print('File doesnt exist.')
            return
        readFile = BitStream(fileName, 'rb')
        writeFile = open(outFileName, 'wb')
        self.tree.counter = int(readFile.read(32), 2)
        while True:
            char = self.tree.decode(readFile)
            if not char:
                break
            writeFile.write(char)
            # writeFile.flush()
            # self.tree.printTree()

        readFile.close()
        writeFile.close()





if __name__ == '__main__':
    decoder = Decoder()
    decoder.decodeFile('./code_test.txt', './decode_test.txt')
