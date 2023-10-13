
import socket
import sys
 
HOST,PORT = "10.0.1.2",12000
 
def main():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((HOST, PORT)) # 目的地
    
    #包头标志
    arrBuf = bytearray(b'\xff\xaa\xff\xaa')
    
    #以二进制方式读取图片
    picData = open('/home/parallels/Downloads/people.jpeg', 'rb')
    picBytes = picData.read()
    
    #图片大小
    picSize = len(picBytes)
    
    #数据体长度 = guid大小(固定) + 图片大小
    datalen = 64 + picSize
    
    #组合数据包
    arrBuf += bytearray(datalen.to_bytes(4, byteorder='little'))
    guid = 23458283482894382928948
    arrBuf += bytearray(guid.to_bytes(64, byteorder='little'))
    arrBuf += picBytes
    
    sock.sendall(arrBuf)
    sock.close()
 
if __name__ == '__main__':
    main()