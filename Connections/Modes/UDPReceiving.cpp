
#include "UDPReceiving.h"

#include <iostream>

#ifdef _WIN32
#include "Winsock/WinsockSocketServer.h"
#include "Winsock/WinsockSocketClient.h"
#include "Winsock/WinsockSocketBuilder.h"
#endif

namespace connections
{

void UDPReceiving::execute ()
{
    WinsockSocketBuilder socketBuilder;
    WinsockSocket* ws = socketBuilder.addPort (50000)
        .forType (WinsockSocket::Type::SERVER)
        .forProtocol (WinsockSocket::Protocol::UDP)
        .buildSocket ();

    ws->bind ();

    const int BUFF_LEN = 1024;
    char* buffer = new char[BUFF_LEN];
    int i = ws->recvfrom (buffer, BUFF_LEN);

    if (i > 0)
    {
        std::cout << buffer << std::endl;
    }

    delete ws;
}

}