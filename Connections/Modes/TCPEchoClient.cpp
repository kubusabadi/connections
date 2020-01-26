#include "TCPEchoClient.h"

#include <iostream>
#include <vector>
#include <string>

#include "Socket.h"
#include "SocketBuilder.h"

namespace connections
{

static const std::vector<char*> messages = {
    "Hello World!",
    "Czesc!",
    "Hi!",
    "exit"
};

void TCPEchoClient::execute ()
{
    SocketBuilder socketBuilder;
    Socket* ws = socketBuilder.addPort (50000)
        .addHost ("127.0.0.1")
        .forType (Socket::Type::CLIENT)
        .forProtocol (Socket::Protocol::TCP)
        .buildSocket ();

    ws->connect ();

    const int BUFF_LEN = 1024;

    for (const auto& s : messages)
    {
        ws->send (s, strlen(s));

        char buffer[BUFF_LEN];
        int i = ws->recv (buffer, BUFF_LEN);
        if (i > 0)
        {
            std::cout << "received: " << buffer << std::endl;
        }
    }
    ws->close ();
    delete ws;
}
}
