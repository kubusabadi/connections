
#ifdef _WIN32
#include "WinsockSocket.h"
#include "..//..//CommonUtils/Printer.h"
#include <iostream>

namespace connections
{

static const Printer PRINTER (std::cout, "Sockets");

WinsockSocket::WinsockSocket ()
{
}

WinsockSocket::WinsockSocket (uint16_t port, std::string address) : port{port}
{
    //std::cout << "WinsockSocket" << std::endl;
    //WSADATA wsadata;
    //int result = WSAStartup (MAKEWORD (2, 2), &wsadata);
    //if (result != 0) //If winsock API failed to start up
    //{
    //    std::cout << "winsosck " << std::endl;
    //    // TODO: Throw exception
    //}

    //if (LOBYTE (wsadata.wVersion) != 2 || HIBYTE (wsadata.wVersion) != 2) //If version received does not match version requested (2.2)
    //{
    //    std::cout << "winsock" << std::endl;
    //    // TODO: Throw exception
    //}
 
    initWinSockAPI ();
    
    int result;
    struct addrinfo hints;
    ZeroMemory (&hints, sizeof (hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;
    // Resolve the server address and port
    result = getaddrinfo (NULL, "50000", &hints, &adrResult);
    
    if (result != 0) {
        std::cout << " error server address" << std::endl;
        // TODO : throw exception
    }
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
    //std::cout << "[Sockets] Initi" << std::endl;
    PRINTER << "Initializing WinSock API (2,2)";
    WSADATA wsadata;
    int result = WSAStartup (MAKEWORD (2, 2), &wsadata);
    if (result != 0) //If winsock API failed to start up
    {
        std::cout << "winsosck " << std::endl;
        // TODO: Throw exception
    }

    if (LOBYTE (wsadata.wVersion) != 2 || HIBYTE (wsadata.wVersion) != 2) //If version received does not match version requested (2.2)
    {
        std::cout << "winsock" << std::endl;
        // TODO: Throw exception
    }
}

void WinsockSocket::shutdown ()
{
    WSACleanup ();
}

void WinsockSocket::listen ()
{
    int iResult;
    // Create a SOCKET for connecting to server
    listenSocket = socket (adrResult->ai_family, adrResult->ai_socktype, adrResult->ai_protocol);
   
    if (listenSocket == INVALID_SOCKET) {
        std::cout << "error listen " << WSAGetLastError () << std::endl;
        //printf ("socket failed with error: %ld\n", WSAGetLastError ());
        //freeaddrinfo (result);
        //WSACleanup ();
        //return 1;
    }

    // Setup the TCP listening socket
    iResult = bind (listenSocket, adrResult->ai_addr, (int)adrResult->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        std::cout << "error bind " << std::endl;
        //printf ("bind failed with error: %d\n", WSAGetLastError ());
        //freeaddrinfo (result);
        //closesocket (ListenSocket);
        //WSACleanup ();
        //return 1;
    }

    freeaddrinfo (adrResult);

    iResult = ::listen (listenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        std::cout << "error listen " << std::endl;
        //printf ("listen failed with error: %d\n", WSAGetLastError ());
        //closesocket (ListenSocket);
        //WSACleanup ();
        //return 1;
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
        std::cout << "error accept " << std::endl;
        //printf ("accept failed: %d\n", WSAGetLastError ());
        //closesocket (ListenSocket);
        //WSACleanup ();
        //return 1;
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