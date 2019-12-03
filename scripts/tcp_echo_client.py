import socket

MESSAGE = "Hello, World!"
MESSAGE2 = "Hi!"
MESSAGE3 = "Czesc"
MESSAGE_EXIT = "exit"

if __name__ == '__main__':
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    address = '127.0.0.1', 50000
    bytes_data = str.encode(MESSAGE)

    s.connect(address)

    s.sendall(bytes_data)

    data = s.recv(16)
    print("receiced: " + str(data))

    bytes_data2 = str.encode(MESSAGE2)

    s.sendall(bytes_data2)

    data = s.recv(16)
    print("receiced: " + str(data))

    bytes_data3 = str.encode(MESSAGE3)

    s.sendall(bytes_data3)

    data = s.recv(16)
    print("receiced: " + str(data))

    bytes_data_exit = str.encode(MESSAGE_EXIT)

    s.sendall(bytes_data_exit)

    data = s.recv(16)
    print("receiced: " + str(data))
