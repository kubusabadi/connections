
#ifdef _WIN32

#include "WinsockSocketServerUDP.h"

namespace connections
{

WinsockSocketServerUDP::WinsockSocketServerUDP ()
{

}

WinsockSocketServerUDP::WinsockSocketServerUDP (uint16_t srvPort) : WinsockSocketServer{ srvPort }
{
}

WinsockSocketServerUDP::~WinsockSocketServerUDP ()
{

}

void WinsockSocketServerUDP::setupAddressInfo ()
{
    /*int result;
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

    PRINTER << "Resolve address " << port << Printer::endl;*/
}

}

#endif