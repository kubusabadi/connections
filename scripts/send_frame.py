import socket

MESSAGE = "Hello, World!"

if __name__ == '__main__':
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    address = '127.0.0.1', 50000
    bytes_data = str.encode(MESSAGE)
    s.sendto(bytes_data, address)