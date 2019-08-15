
#ifdef _WIN32

#include "WinsockSocketClient.h"
#include "..//..//CommonUtils/Printer.h"
#include <iostream>
#include <string>
#include "Error.h"

namespace connections
{

WinsockSocketClient::WinsockSocketClient ()
{
}

WinsockSocketClient::WinsockSocketClient (uint16_t port, std::string address) : port{ port }, address{address}
{
    initWinSockAPI ();
    resolveAddress ();
    setupSocket (); 
}

WinsockSocketClient::WinsockSocketClient (uint16_t port, uint32_t address) : port {port}
{
    struct sockaddr_in sa;
    sa.sin_addr = address;
    char str[INET_ADDRSTRLEN];
    inet_ntop (AF_INET, &(sa.sin_addr), str, INET_ADDRSTRLEN);
    
    WinsockSocketClient(port, std::string(str)); 
}

WinsockSocketClient::WinsockSocketClient (uint16_t port) : port{port}
{
}

WinsockSocketClient::~WinsockSocketClient ()
{
}

void WinsockSocketClient::initWinSockAPI ()
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

void WinsockSocketClient::resolveAddress ()
{
    int result;
    struct addrinfo hints;

    ZeroMemory (&hints, sizeof (hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    result = getaddrinfo (address.c_str(), std::to_string (port).c_str (), &hints, &addrResult);

    if (result != 0) 
    {
        throw new BadWinsock{ getWSAError (WSAGetLastError ()) };
    }

    PRINTER << "Resolve address " << port << Printer::endl;
}

void WinsockSocketClient::shutdown ()
{
    WSACleanup ();
}

void WinsockSocketClient::connect ()
{
    int iResult = connect(clientSocket, addrResult->ai_addr, (int)addrResult->ai_addrlen);
}

void WinsockSocketClient::setupSocket ()
{
   clientSocket = socket(addrResult->ai_family, addrResult->ai_socktype, 
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

int send (char* buffer, int lenght)
{
    iResult = send( ConnectSocket, sendbuf, (int)strlen(sendbuf), 0 );
}
#endif