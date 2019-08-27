/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/
#ifdef _WIN32

#include "WinsockSocketServer.h"
#include "..//..//CommonUtils/Printer.h"
#include <iostream>
#include <string>
#include "Error.h"

namespace connections
{

static const Printer PRINTER (std::cout, "Sockets");

WinsockSocketServer::WinsockSocketServer ()
{
}

WinsockSocketServer::WinsockSocketServer (uint16_t srvPort) : WinsockSocketServer{}
{
    port = srvPort;
}

WinsockSocketServer::~WinsockSocketServer ()
{
}

void WinsockSocketServer::listen ()
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

void WinsockSocketServer::accept()
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

int WinsockSocketServer::receive (char* buffer, int lenght)
{
    int iResult = recv (clientSocket, buffer, lenght, 0);
    if (iResult == lenght)
    {
        buffer[iResult-1] = '\0';
    }
    else
    {
        buffer[iResult] = '\0';
    }
    if (iResult > 0)
    {
        std::cout << "Bytes received: " << iResult << " : " << buffer << std::endl;
    }

    return iResult;
}

void WinsockSocketServer::connect ()
{
    throw new BadOperation{ "Attempting to perform client operation on server socket." };
}

void WinsockSocketServer::bind ()
{
    if (!addressInfo)
    {
        throw new BadWinsock{ "address info didn't setup" };
    }
    int iResult;

    listenSocket = socket (addressInfo->ai_family, addressInfo->ai_socktype, addressInfo->ai_protocol);

    if (listenSocket == INVALID_SOCKET) {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    iResult = ::bind (listenSocket, addressInfo->ai_addr, (int)addressInfo->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    freeaddrinfo (addressInfo);
}

}

#endif