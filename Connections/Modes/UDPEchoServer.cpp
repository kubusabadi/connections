
#include "UDPEchoServer.h"

#include <iostream>

#include "Socket.h"
#include "SocketBuilder.h"

namespace connections
{

void UDPEchoServer::execute ()
{
    SocketBuilder socketBuilder;
    Socket* ws = socketBuilder.addPort (50000)
        .forType (Socket::Type::SERVER)
        .forProtocol (Socket::Protocol::UDP)
        .buildSocket ();

    ws->bind ();

    const int BUFF_LEN = 1024;
    char* buffer = new char[BUFF_LEN];

    int i = 0;

    bool exit = false;

    do
    {
        int i = ws->recvfrom (buffer, BUFF_LEN);

        if (i > 0)
        {
            std::cout << buffer << std::endl;
            ws->sendto (buffer, i);
            exit = strcmp (buffer, "exit") == 0;
        }

    } while (!exit);

    ws->close ();
    delete ws;
}
}