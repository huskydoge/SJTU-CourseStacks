import os
from bitStream import BitStream


class Viewer:
    def __init__(self):
        pass

    def view(self, fileName):
        if not os.path.exists(fileName):
            print('File doesnt exist.')
            return
        readFile = BitStream(fileName, 'rb')
        for i in range(100):
            c = readFile.read(8)
            if not c:
                break
            print(c)
        readFile.close()


if __name__ == '__main__':
    viewer = Viewer()
    viewer.view('./code.txt')
