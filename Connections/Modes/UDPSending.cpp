
#include "UDPSending.h"

#ifdef _WIN32
#include "Winsock/WinsockSocketServer.h"
#include "Winsock/WinsockSocketClient.h"
#include "Winsock/WinsockSocketBuilder.h"
#endif

#include <iostream>

namespace connections
{

void UDPSending::execute ()
{
    WinsockSocketBuilder socketBuilder;
    WinsockSocket* ws = socketBuilder.addPort (50000)
        .addHost ("127.0.0.1")
        .forType (WinsockSocket::Type::CLIENT)
        .forProtocol (WinsockSocket::Protocol::UDP)
        .buildSocket ();

    char buffer[13] = "Hello world\n";

    ws->sendto (buffer, sizeof (buffer));

    delete ws;
}

}