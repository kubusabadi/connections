
#include "WinsockSocket.h"

namespace kowl
{

WinsockSocket::WinsockSocket (std::string address, uint16_t port)
{
    WSADATA wsadata;
    int result = WSAStartup (MAKEWORD (2, 2), &wsadata);
    if (result != 0) //If winsock API failed to start up
    {
        // TODO: Throw exception
    }

    if (LOBYTE (wsadata.wVersion) != 2 || HIBYTE (wsadata.wVersion) != 2) //If version received does not match version requested (2.2)
    {
        // TODO: Throw exception
    }
}

WinsockSocket::WinsockSocket (uint32_t address, uint16_t port)
{
}

WinsockSocket::WinsockSocket (uint16_t port)
{
}

WinsockSocket::~WinsockSocket ()
{
    shutdown ();
}

void WinsockSocket::shutdown ()
{
    WSACleanup ();
}
}