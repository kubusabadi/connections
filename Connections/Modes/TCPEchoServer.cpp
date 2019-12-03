
#include "TCPEchoServer.h"

#include <iostream>

#ifdef _WIN32
#include "Winsock/WinsockSocketServer.h"
#include "Winsock/WinsockSocketClient.h"
#include "Winsock/WinsockSocketBuilder.h"
#endif

namespace connections
{

void TCPEchoServer::execute ()
{
    WinsockSocketBuilder socketBuilder;
    WinsockSocket* ws = socketBuilder.addPort (50000)
        .forType (WinsockSocket::Type::SERVER)
        .forProtocol (WinsockSocket::Protocol::TCP)
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

    delete ws;
}
}