
#include "TCPSending.h"

#ifdef _WIN32
#include "Winsock/WinsockSocketServer.h"
#include "Winsock/WinsockSocketClient.h"
#include "Winsock/WinsockSocketBuilder.h"
#endif

#include <iostream>

namespace connections
{

void TCPSending::execute ()
{
    WinsockSocketBuilder socketBuilder;
    WinsockSocket* ws = socketBuilder.addPort (50000)
        .addHost("127.0.0.1")
        .forType (WinsockSocket::Type::CLIENT)
        .forProtocol (WinsockSocket::Protocol::TCP)
        .buildSocket ();

    std::cout << "client built\n";

    char buffer[13] = "Hello world\n";

    ws->connect ();

    std::cout << sizeof (buffer) << std::endl;

    ws->send (buffer, sizeof (buffer));
}

}