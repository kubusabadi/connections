
#ifdef _WIN32

#pragma once

#ifndef _WINSOCK_SOCKET_SERVER_H_
#define _WINSOCK_SOCKET_SERVER_H_

#include <string>

#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h> 
#include <ws2tcpip.h>

namespace connections
{

class WinsockSocketServer
{
public:
    WinsockSocketServer ();
    WinsockSocketServer (uint16_t port); // localhost
    ~WinsockSocketServer ();
    void shutdown ();

    void listen ();
    void accept ();
    int receive (char* buffer, int lenght);

private:
    uint16_t port = 0;
    SOCKET listenSocket = INVALID_SOCKET;
    SOCKET clientSocket = INVALID_SOCKET;
    addrinfo* adrResult = NULL;

    void initWinSockAPI ();
    void resolveAddress ();
};

}

#endif
#endif
