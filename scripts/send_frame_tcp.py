import socket

MESSAGE = "Hello, World!"

if __name__ == '__main__':
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    address = '127.0.0.1', 50000
    bytes_data = str.encode(MESSAGE)
    s.connect(address)
    s.sendall(bytes_data)