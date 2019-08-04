
#ifdef _WIN32
#include "WinsockSocket.h"
#include "..//..//CommonUtils/Printer.h"
#include <iostream>
#include <string>
#include "Error.h"

namespace connections
{

static const Printer PRINTER (std::cout, "Sockets");

WinsockSocket::WinsockSocket ()
{
}

WinsockSocket::WinsockSocket (uint16_t port, std::string address) : port{port}
{
    initWinSockAPI ();
    resolveAddress ();
}

WinsockSocket::WinsockSocket (uint16_t port, uint32_t address) : port{port}
{
}

WinsockSocket::WinsockSocket (uint16_t port) : port{port}
{
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
        throw new BadWinsock{getWSAError(WSAGetLastError())};
    }

    if (LOBYTE (wsadata.wVersion) != 2 || HIBYTE (wsadata.wVersion) != 2)
    {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    PRINTER << "Initializing WinSock API (2,2)" << Printer::endl;
}

void WinsockSocket::resolveAddress ()
{
    int result;
    struct addrinfo hints;
    
    ZeroMemory (&hints, sizeof (hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    result = getaddrinfo (NULL, std::to_string(port).c_str(), &hints, &adrResult);

    if (result != 0) {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    PRINTER << "Resolve address " << port << Printer::endl;
}

void WinsockSocket::shutdown ()
{
    WSACleanup ();
}

void WinsockSocket::listen ()
{
    int iResult;

    listenSocket = socket (adrResult->ai_family, adrResult->ai_socktype, adrResult->ai_protocol);
   
    if (listenSocket == INVALID_SOCKET) {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    iResult = bind (listenSocket, adrResult->ai_addr, (int)adrResult->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    freeaddrinfo (adrResult);

    iResult = ::listen (listenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }
}

void WinsockSocket::accept()
{
    if (listenSocket == INVALID_SOCKET)
    {
        return;
    }

    int iResult;

    clientSocket = ::accept (listenSocket, NULL, NULL);
    if (clientSocket == INVALID_SOCKET) {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }
}

void WinsockSocket::receive ()
{
    const int DEFAULT_BUFLEN = 1024;
    char recvbuf[DEFAULT_BUFLEN];
    int iResult;

    while (true)
    {
        iResult = recv (clientSocket, recvbuf, DEFAULT_BUFLEN, 0);
        recvbuf[iResult] = '\0';
        if(iResult > 0)
            std::cout << "Bytes received: " << iResult << " : " << recvbuf << std::endl;
    }
}

}

#endif