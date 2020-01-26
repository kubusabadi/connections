/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/
#ifdef _WIN32

#include <iostream>
#include "Printer.h"
#include "WinsockSocketClientUDP.h"
#include "Error.h"

namespace connections
{

static const Printer PRINTER (std::cout, "Sockets client UDP");

WinsockSocketClientUDP::WinsockSocketClientUDP (uint16_t port, std::string address) : WinsockSocketClient{ port, address }
{
    setupSocket ();
}

WinsockSocketClientUDP::~WinsockSocketClientUDP ()
{
}

void WinsockSocketClientUDP::setupSocket ()
{
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons (port);
    InetPton (AF_INET, host.c_str (), &sockAddr.sin_addr.s_addr);

    PRINTER << "Resolve address " << port << Printer::endl;

    clientSocket = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (clientSocket == INVALID_SOCKET)
    {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }
}

int WinsockSocketClientUDP::recvfrom (char* buffer, int lenght)
{
    int sockAddrSize = sizeof (sockAddr);
    int iResult = ::recvfrom (clientSocket, buffer, lenght, 0, (sockaddr*)&sockAddr, &sockAddrSize);

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

int WinsockSocketClientUDP::sendto (char* buffer, int lenght)
{
    int iResult = ::sendto (clientSocket, buffer, lenght, 0, (SOCKADDR*)&sockAddr, sizeof (sockAddr));

    if (iResult == SOCKET_ERROR)
    {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    return iResult;
}

int WinsockSocketClientUDP::close ()
{
    return closesocket (clientSocket);
}


int WinsockSocketClientUDP::recv (char* buffer, int lenght)
{
    throw new BadOperation{ "Attempting to perform tcp operation on udp socket." };
}

int WinsockSocketClientUDP::send (char* buffer, int lenght)
{
    throw new BadOperation{ "Attempting to perform udp operation on tcp socket." };
}

void WinsockSocketClientUDP::connect ()
{
    throw new BadOperation{ "Attempting to perform tcp operation on udp socket." };
}

}

#endif