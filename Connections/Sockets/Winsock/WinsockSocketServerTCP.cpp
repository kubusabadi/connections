
#ifdef _WIN32

#include "WinsockSocketServerTCP.h"
#include "..//..//CommonUtils/Printer.h"
#include <iostream>
#include <string>
#include "Error.h"

namespace connections
{

static const Printer PRINTER (std::cout, "Sockets TCP");

WinsockSocketServerTCP::WinsockSocketServerTCP ()
{

}

WinsockSocketServerTCP::WinsockSocketServerTCP (uint16_t srvPort) : WinsockSocketServer{ srvPort }
{
    setupAddressInfo ();
}

WinsockSocketServerTCP::~WinsockSocketServerTCP ()
{

}

void WinsockSocketServerTCP::setupAddressInfo ()
{
    int result;
    struct addrinfo hints;

    ZeroMemory (&hints, sizeof (hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    result = getaddrinfo (NULL, std::to_string (port).c_str (), &hints, &addressInfo);

    if (result != 0) {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    PRINTER << "Resolve address " << port << Printer::endl;
}

}

#endif