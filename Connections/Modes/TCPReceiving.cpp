
#include "TCPReceiving.h"

#include <iostream>

#include "Socket.h"
#include "SocketBuilder.h"

namespace connections
{

void TCPReceiving::execute ()
{
    SocketBuilder sb;
    Socket* socket = sb.addPort (50000)
        .forType (Socket::Type::SERVER)
        .forProtocol (Socket::Protocol::TCP)
        .buildSocket ();

    socket->bind ();
    socket->listen ();
    socket->accept ();

    const int BUFF_LEN = 1024;
    char* buffer = new char[BUFF_LEN];
    int i = socket->recv (buffer, BUFF_LEN);

    if (i > 0)
    {
        std::cout << buffer << std::endl;
    }
    socket->close ();
    delete socket;
}

}