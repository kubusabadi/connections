#ifdef _WIN32

#pragma once

#ifndef _WINSOCK_SOCKET_CLIENT_H_
#define _WINSOCK_SOCKET_CLIENT_H_

#include <string>

#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h> 
#include <ws2tcpip.h>

namespace connections
{

class WinsockSocketClient
{
public:
    WinsockSocketClient ();
    WinsockSocketClient (uint16_t port, std::string address);
    WinsockSocketClient (uint16_t port, uint32_t address);
    WinsockSocketClient (uint16_t port); // localhost
    ~WinsockSocketClient ();
    void shutdown ();

    void connect ();
    int receive (char* buffer, int lenght);
    int send (char* buffer, int lenght);

private:
    uint16_t port = 0;
    std::string host = "";
    SOCKET clientSocket = INVALID_SOCKET;
    addrinfo* addrResult = NULL;

    void initWinSockAPI ();
    void resolveAddress ();
    void setupSocket ();
};

}

#endif // !_WINSOCK_SOCKET_H_

#endif
