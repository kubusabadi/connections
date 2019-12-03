
#ifdef _WIN32

#include "WinsockSocketServerTCP.h"
#include "Printer.h"
#include <iostream>
#include <string>
#include "Error.h"

namespace connections
{

static const Printer PRINTER (std::cout, "Sockets server TCP");

WinsockSocketServerTCP::WinsockSocketServerTCP (uint16_t srvPort) : WinsockSocketServer{ srvPort }
{
    setupSocket ();
}

WinsockSocketServerTCP::~WinsockSocketServerTCP ()
{
}

void WinsockSocketServerTCP::setupSocket() 
{
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons (port);
    InetPton (AF_INET, "127.0.0.1", &sockAddr.sin_addr.s_addr);

    PRINTER << "Resolve address " << port << Printer::endl;

}

void WinsockSocketServerTCP::bind ()
{
    int iResult;

    listenSocket = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (listenSocket == INVALID_SOCKET) {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    iResult = ::bind (listenSocket, (SOCKADDR*)& sockAddr, sizeof (sockAddr));
    if (iResult == SOCKET_ERROR) {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }
}

void WinsockSocketServerTCP::listen ()
{
    if (listenSocket == INVALID_SOCKET)
    {
        throw new BadWinsock{ "listen socket not initialized" };
    }

    int iResult = ::listen (listenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }
}

void WinsockSocketServerTCP::accept ()
{
    if (listenSocket == INVALID_SOCKET)
    {
        throw new BadWinsock{ "address info didn't setup" };
    }

    clientSocket = ::accept (listenSocket, NULL, NULL);
    if (clientSocket == INVALID_SOCKET) {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }
}

int WinsockSocketServerTCP::send (char* buffer, int lenght)
{
    int iResult = ::send (clientSocket, buffer, lenght, 0);
    
    if (iResult == SOCKET_ERROR) {

        return -1;
    }
}

int WinsockSocketServerTCP::recv (char* buffer, int lenght)
{
    int iResult = ::recv (clientSocket, buffer, lenght, 0);
    if (iResult == lenght)
    {
        buffer[iResult - 1] = '\0';
    }
    else
    {
        buffer[iResult] = '\0';
    }

    //PRINTER << "Received: " << iResult << Printer::endl;

    if (iResult > 0)
    {
        //std::cout << "Bytes received: " << iResult << " : " << buffer << std::endl;
    }

    return iResult;
}

int WinsockSocketServerTCP::recvfrom (char* buffer, int lenght)
{
    throw new BadOperation{ "Attempting to perform udp operation on tcp socket." };
}

int WinsockSocketServerTCP::sendto (char* buffer, int lenght)
{
    throw new BadOperation{ "Attempting to perform udp operation on tcp socket." };
}

}

#endif