/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/

#ifdef _WIN32

#include "WinsockSocket.h"

#include <string>

#include "Printer.h"
#include "Error.h"

#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h> 
#include <ws2tcpip.h>

namespace connections
{

static const Printer PRINTER (std::cout, "Sockets");

WinsockSocket::WinsockSocket ()
{
    initWinSockAPI ();
}

WinsockSocket::~WinsockSocket ()
{
    shutdown ();
}

void WinsockSocket::initWinSockAPI ()
{
    WSADATA wsadata;
    int result = WSAStartup (MAKEWORD (2, 2), &wsadata);

    if (result != 0)
    {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    if (LOBYTE (wsadata.wVersion) != 2 || HIBYTE (wsadata.wVersion) != 2)
    {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    PRINTER << "Initializing WinSock API (2,2)" << Printer::endl;
}

void WinsockSocket::shutdown ()
{
    PRINTER << "Shuting down WinSock API" << Printer::endl;
    WSACleanup ();
}

}

#endif