
#include "TCPSending.h"

#include "Socket.h"
#include "SocketBuilder.h"

#include <iostream>

namespace connections
{

void TCPSending::execute ()
{
    SocketBuilder socketBuilder;
    Socket* ws = socketBuilder.addPort (50000)
        .addHost("127.0.0.1")
        .forType (Socket::Type::CLIENT)
        .forProtocol (Socket::Protocol::TCP)
        .buildSocket ();

    std::cout << "client built\n";

    char buffer[13] = "Hello world\n";

    ws->connect ();

    std::cout << sizeof (buffer) << std::endl;

    ws->send (buffer, sizeof (buffer));

    ws->close ();

    delete ws;
}

}