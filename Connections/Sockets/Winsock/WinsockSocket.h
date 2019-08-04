
#ifdef _WIN32

#pragma once

#ifndef _WINSOCK_SOCKET_H_
#define _WINSOCK_SOCKET_H_

#include <string>

#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h> 
#include <ws2tcpip.h>

namespace connections
{

class WinsockSocket
{
public:
    WinsockSocket ();
    WinsockSocket (uint16_t port, std::string address);
    WinsockSocket (uint16_t port, uint32_t address);
    WinsockSocket (uint16_t port); // localhost
    ~WinsockSocket ();
    void shutdown ();

    void listen ();
    void accept ();
    void receive ();

private:
    uint16_t port = 0;
    SOCKET listenSocket = INVALID_SOCKET;
    SOCKET clientSocket = INVALID_SOCKET;
    addrinfo* adrResult = NULL;

    void initWinSockAPI ();
    void resolveAddress ();
};

}

#endif // !_WINSOCK_SOCKET_H_

#endif
