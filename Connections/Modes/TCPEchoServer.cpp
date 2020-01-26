
#include "TCPEchoServer.h"

#include <iostream>
#include "Socket.h"
#include "SocketBuilder.h"

namespace connections
{

void TCPEchoServer::execute ()
{
    SocketBuilder socketBuilder;
    Socket* ws = socketBuilder.addPort (50000)
        .forType (Socket::Type::SERVER)
        .forProtocol (Socket::Protocol::TCP)
        .buildSocket ();

    ws->bind ();
    ws->listen ();
    ws->accept ();

    const int BUFF_LEN = 1024;
    char* buffer = new char[BUFF_LEN];

    int i = 0;

    bool exit = false;

    do
    {
        int i = ws->recv (buffer, BUFF_LEN);

        if (i > 0)
        {
            std::cout << buffer << std::endl;
            ws->send (buffer, i);
            exit = strcmp (buffer, "exit") == 0;
        }

    } while (!exit);


    ws->close ();
    delete ws;
}
}