
import socket

if __name__ == '__main__':
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    address = '127.0.0.1', 50000
    s.bind(address)

    data = s.recv(4097)
    print("hi" + str(data))