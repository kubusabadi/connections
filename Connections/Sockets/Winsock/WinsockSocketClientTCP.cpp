/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/
#ifdef _WIN32

#include <iostream>
#include "Printer.h"
#include "WinsockSocketClientTCP.h"
#include "Error.h"

namespace connections
{
static const Printer PRINTER (std::cout, "Sockets client TCP");


WinsockSocketClientTCP::WinsockSocketClientTCP ()
{

}

WinsockSocketClientTCP::WinsockSocketClientTCP (uint16_t port, std::string address) : WinsockSocketClient{ port, address }
{
    setupAddressInfo ();
    setupSocket ();
}

WinsockSocketClientTCP::WinsockSocketClientTCP (uint16_t port) : WinsockSocketClient{ port }
{

}

WinsockSocketClientTCP::~WinsockSocketClientTCP ()
{
}

void WinsockSocketClientTCP::setupAddressInfo ()
{
    int result;
    struct addrinfo hints;

    ZeroMemory (&hints, sizeof (hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    result = getaddrinfo (host.c_str (), std::to_string (port).c_str (), &hints, &addrResult);

    if (result != 0)
    {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    PRINTER << "Resolve address " << port << Printer::endl;
}

}

#endif