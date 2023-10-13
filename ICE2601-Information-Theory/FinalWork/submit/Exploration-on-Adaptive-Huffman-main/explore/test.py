# produce test.txt
def writeFile(fileName, data):
    file = open(fileName, 'wb')
    for ch in data:
        # print((ord(ch)))
        file.write((ord(ch)).to_bytes(1, byteorder='little'))
    file.close()


def readFile(fileName):
    with open(fileName, 'rb') as file:
        c = file.read(1)
        while c:
            # print(c)
            c = file.read(1)


if __name__ == '__main__':
    fileName = 'test.txt'
    data =  '''中文'''
    writeFile(fileName, data)
    readFile(fileName)
