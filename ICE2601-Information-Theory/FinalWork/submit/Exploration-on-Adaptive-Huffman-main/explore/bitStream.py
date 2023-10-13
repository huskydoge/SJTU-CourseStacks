# bit <-> str
class BitStream:
    def __init__(self, fileName, mode):
        self.file = open(fileName, mode)
        self.word = 0
        if mode[0] == 'r':
            self.pos = -1
        elif mode[0] == 'w':
            self.pos = 7
        self.mode = mode

    def read(self, size):
        ret = ''
        for i in range(size):
            if self.pos == -1:
                self.word = self.file.read(1)
                if self.word == b'':
                    return ''
                else:
                    self.word = ord(self.word)
                    self.pos = 7

            if self.word & (1 << self.pos):
                ret += '1'
            else:
                ret += '0'
            self.pos -= 1
        return ret

    def write(self, string):
        for char in string:
            if char == '0':
                self.word <<= 1
                self.pos -= 1
            elif char == '1':
                self.word <<= 1
                self.word += 1
                self.pos -= 1
            else:
                continue

            if self.pos == -1:
                self.flush()

    def close(self):
        if self.mode[0] == 'w':
            self.flush()
        self.file.close()

    def flush(self):
        if self.pos != 7:
            while self.pos > -1:  # very important
                self.word <<= 1
                self.pos -= 1
            self.file.write(self.word.to_bytes(1, byteorder='little'))
        self.word = 0
        self.pos = 7


# test
if __name__ == '__main__':
    file = BitStream('./test.txt', 'rb')
    writeFile = BitStream('./temp.txt', 'wb')

    ch = file.read(1)
    i = 0
    while ch:
        print(ch, end='')
        i += 1
        if i % 8 == 0:
            print()
        writeFile.write(ch)
        ch = file.read(1)
    file.close()
    writeFile.close()
