import socket

MESSAGE = "Hello, World!"
MESSAGE2 = "Hi!"
MESSAGE3 = "Czesc"
MESSAGE_EXIT = "exit"

if __name__ == '__main__':
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    address = '127.0.0.1', 50000

    bytes_data = str.encode(MESSAGE)
    s.sendto(bytes_data, address)

    data, addr = s.recvfrom(1024)  # buffer size is 1024 bytes
    print("received message: " + str(data))

    bytes_data2 = str.encode(MESSAGE2)
    s.sendto(bytes_data2, address)

    data, addr = s.recvfrom(1024)  # buffer size is 1024 bytes
    print("received message: " + str(data))

    bytes_data3 = str.encode(MESSAGE3)
    s.sendto(bytes_data3, address)

    data, addr = s.recvfrom(1024)  # buffer size is 1024 bytes
    print("received message: " + str(data))

    bytes_data_exit = str.encode(MESSAGE_EXIT)
    s.sendto(bytes_data_exit, address)

    print("exit")