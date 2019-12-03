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

WinsockSocketClientTCP::WinsockSocketClientTCP (uint16_t port, std::string address) : WinsockSocketClient{ port, address }
{
    setupSocket ();
}

WinsockSocketClientTCP::~WinsockSocketClientTCP ()
{
}

void WinsockSocketClientTCP::setupSocket ()
{
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons (port);
    InetPton (AF_INET, host.c_str (), &sockAddr.sin_addr.s_addr);

    PRINTER << "Resolve address " << port << Printer::endl;

    clientSocket = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (clientSocket == INVALID_SOCKET)
    {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }
}

int WinsockSocketClientTCP::recvfrom (char* buffer, int lenght)
{
    throw new BadOperation{ "Attempting to perform udp operation on tcp socket." };
}

int WinsockSocketClientTCP::sendto (char* buffer, int lenght)
{
    throw new BadOperation{ "Attempting to perform udp operation on tcp socket." };
}

void WinsockSocketClientTCP::connect ()
{
    int iResult = ::connect (clientSocket, (SOCKADDR*)&sockAddr, sizeof (sockAddr));

    if (iResult == SOCKET_ERROR)
    {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }
}

int WinsockSocketClientTCP::recv (char* buffer, int lenght)
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
    
    PRINTER << "Bytes received " << iResult << Printer::endl;

    if (iResult > 0)
    {
        std::cout << "Bytes received: " << iResult << " : " << buffer << std::endl;
    }

    return iResult;
}

int WinsockSocketClientTCP::send (char* buffer, int lenght)
{
    int iResult = ::send (clientSocket, buffer, lenght, 0);

    if (iResult == SOCKET_ERROR)
    {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    return iResult;
}
}

#endif