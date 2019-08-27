
#ifdef _WIN32

#include "WinsockSocketClient.h"
#include "..//..//CommonUtils/Printer.h"
#include <iostream>
#include <string>
#include "Error.h"

namespace connections
{
static const Printer PRINTER (std::cout, "Sockets");

WinsockSocketClient::WinsockSocketClient ()
{
}

WinsockSocketClient::WinsockSocketClient (uint16_t port, std::string address) : port{ port }, host{ address }
{
    setupAddressInfo ();
    setupSocket ();
}

WinsockSocketClient::WinsockSocketClient (uint16_t port) : port{ port }
{
}

WinsockSocketClient::~WinsockSocketClient ()
{
}

void WinsockSocketClient::setupAddressInfo ()
{
    int result;
    struct addrinfo hints;

    ZeroMemory (&hints, sizeof (hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    result = getaddrinfo (host.c_str (), std::to_string (port).c_str (), &hints, &addrResult);

    if (result != 0)
    {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    PRINTER << "Resolve address " <<  port << Printer::endl;
}

void WinsockSocketClient::connect ()
{
    int iResult = ::connect (clientSocket, addrResult->ai_addr, (int)addrResult->ai_addrlen);
}

void WinsockSocketClient::setupSocket ()
{
    clientSocket = socket (addrResult->ai_family, addrResult->ai_socktype,
        addrResult->ai_protocol);

    if (clientSocket == INVALID_SOCKET)
    {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }
}

int WinsockSocketClient::receive (char* buffer, int lenght)
{
    int iResult = recv (clientSocket, buffer, lenght, 0);
    if (iResult == lenght)
    {
        buffer[iResult - 1] = '\0';
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

void WinsockSocketClient::listen ()
{
    throw new BadOperation{ "Attempting to perform server operation on client socket." };
}
void WinsockSocketClient::accept ()
{
    throw new BadOperation{ "Attempting to perform server operation on client socket." };
}

int WinsockSocketClient::send (char* buffer, int lenght)
{
    int iResult = ::send (clientSocket, buffer, lenght, 0);
    return iResult;
}
void WinsockSocketClient::bind ()
{
}

}

#endif