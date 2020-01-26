import socket

if __name__ == '__main__':
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    address = '127.0.0.1', 50000
    s.bind(address)

    data = ""
    while str(data) != "exit":
        data, addr = s.recvfrom(1024)  # buffer size is 1024 bytes
        print("received message: " + str(data))
        sent = s.sendto(data, addr)
        print("sent "  + str(sent))