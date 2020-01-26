
#include "UDPSending.h"

#include "Socket.h"
#include "SocketBuilder.h"

#include <iostream>

namespace connections
{

void UDPSending::execute ()
{
    SocketBuilder socketBuilder;
    Socket* ws = socketBuilder.addPort (50000)
        .addHost ("127.0.0.1")
        .forType (Socket::Type::CLIENT)
        .forProtocol (Socket::Protocol::UDP)
        .buildSocket ();

    char buffer[13] = "Hello world\n";

    ws->sendto (buffer, sizeof (buffer));
    ws->close ();
    delete ws;
}

}