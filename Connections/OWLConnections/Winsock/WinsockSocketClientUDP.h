/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/
#ifdef _WIN32

#ifndef _WINSOCK_SOCKET_CLIENT_UDP_H_
#define _WINSOCK_SOCKET_CLIENT_UDP_H_

#include "WinsockSocketClient.h"

namespace connections
{

class WinsockSocketClientUDP : public WinsockSocketClient
{
public:
    WinsockSocketClientUDP (uint16_t port, std::string address);
    virtual ~WinsockSocketClientUDP ();

    int sendto (char* buffer, int lenght) override;
    int recvfrom (char* buffer, int lenght) override;

    int send (char* buffer, int lenght) override;
    int recv (char* buffer, int lenght) override;
    void connect () override;

private:
    SOCKET clientSocket = INVALID_SOCKET;
    sockaddr_in sockAddr;

    void setupSocket ();
};

}

#endif
#endif