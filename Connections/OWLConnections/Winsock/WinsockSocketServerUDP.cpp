
#ifdef _WIN32

#include "WinsockSocketServerUDP.h"
#include "Printer.h"
#include <iostream>
#include <string>
#include "Error.h"

namespace connections
{

static const Printer PRINTER (std::cout, "Sockets server UDP");


WinsockSocketServerUDP::WinsockSocketServerUDP (uint16_t srvPort) : WinsockSocketServer{ srvPort }
{
    setupSocket ();
}

WinsockSocketServerUDP::~WinsockSocketServerUDP ()
{
}

void WinsockSocketServerUDP::setupSocket ()
{
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_addr.s_addr = INADDR_ANY;
    sockAddr.sin_port = htons (port);
    //InetPton (AF_INET, "127.0.0.1", &sockAddr.sin_addr.s_addr);

    PRINTER << "Resolve address " << port << Printer::endl;
}

void WinsockSocketServerUDP::bind ()
{
    int iResult;

    listenSocket = socket (AF_INET, SOCK_DGRAM, 0);

    if (listenSocket == INVALID_SOCKET) {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    iResult = ::bind (listenSocket, (SOCKADDR*)& sockAddr, sizeof (sockAddr));
    if (iResult == SOCKET_ERROR) {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }
}

int WinsockSocketServerUDP::recvfrom (char* buffer, int lenght)
{
    int sockAddrSize = sizeof (sockAddr);
    int iResult = ::recvfrom (listenSocket, buffer, lenght, 0, (sockaddr*)& sockAddr, &sockAddrSize);
   
    if (iResult == SOCKET_ERROR)
    {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    if (iResult == lenght)
    {
        buffer[iResult - 1] = '\0';
    }
    else
    {
        buffer[iResult] = '\0';
    }
   
    return iResult;
}

int WinsockSocketServerUDP::sendto (char* buffer, int lenght)
{
    int iResult = ::sendto (listenSocket, buffer, lenght, 0, (SOCKADDR*)&sockAddr, sizeof (sockAddr));

    if (iResult == SOCKET_ERROR)
    {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    return iResult;
}

int WinsockSocketServerUDP::close ()
{
    return closesocket (listenSocket);
}

int WinsockSocketServerUDP::send (char* buffer, int lenght)
{
    throw new BadOperation{ "Attempting to perform udp operation on tcp socket." };
}

int WinsockSocketServerUDP::recv (char* buffer, int lenght)
{
    throw new BadOperation{ "Attempting to perform udp operation on tcp socket." };
}

void WinsockSocketServerUDP::listen ()
{
    throw new BadOperation{ "Attempting to perform udp operation on tcp socket." };
}

void WinsockSocketServerUDP::accept ()
{
    throw new BadOperation{ "Attempting to perform udp operation on tcp socket." };
}

}

#endif