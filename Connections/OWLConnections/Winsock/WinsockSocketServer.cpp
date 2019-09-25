/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/
#ifdef _WIN32

#include "WinsockSocketServer.h"
#include "Printer.h"
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

int WinsockSocketServer::recv (char* buffer, int lenght)
{
    int iResult = ::recv (clientSocket, buffer, lenght, 0);
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
    int iResult;

    listenSocket = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (listenSocket == INVALID_SOCKET) {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    iResult = ::bind (listenSocket, (SOCKADDR*) &listenSockAddr, sizeof(listenSockAddr));
    if (iResult == SOCKET_ERROR) {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }
}

int WinsockSocketServer::send (char* buffer, int lenght)
{
    return 0;
}

}

#endif