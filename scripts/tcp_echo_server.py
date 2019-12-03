import socket

if __name__ == '__main__':
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    address = '127.0.0.1', 50000

    s.bind(address)
    s.listen(1)

    connection, client_address = s.accept()

    data = ""
    while data != "exit":
        data = connection.recv(16)
        print("received message: " + str(data))
        connection.sendall(data)