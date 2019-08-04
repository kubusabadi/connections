
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

struct SocketException
{
    SocketException (std::string msg) : msg (msg) {}
    std::string msg;
};

class WinsockSocket
{
public:
    WinsockSocket ();
    WinsockSocket (std::string address, uint16_t port);
    WinsockSocket (uint32_t address, uint16_t port);
    WinsockSocket (uint16_t port); // localhost
    ~WinsockSocket ();
    void shutdown ();

    void listen ();
    void accept ();

    void receive ();

private:
    SOCKET listenSocket = INVALID_SOCKET;
    SOCKET clientSocket = INVALID_SOCKET;

    addrinfo* adrResult = NULL;
};

}

#endif // !_WINSOCK_SOCKET_H_

#endif
