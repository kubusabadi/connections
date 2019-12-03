/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/
#ifdef _WIN32

#ifndef _WINSOCK_SOCKET_CLIENT_TCP_H_
#define _WINSOCK_SOCKET_CLIENT_TCP_H_

#include "WinsockSocketClient.h"

namespace connections
{

class WinsockSocketClientTCP : public WinsockSocketClient
{
public:
    WinsockSocketClientTCP (uint16_t port, std::string address);
    virtual ~WinsockSocketClientTCP ();

    int recv (char* buffer, int lenght) override;
    int send (char* buffer, int lenght) override;
    void connect () override;

    int recvfrom (char* buffer, int lenght) override;
    int sendto (char* buffer, int lenght) override;

private:
    SOCKET clientSocket = INVALID_SOCKET;
    sockaddr_in sockAddr;

    void setupSocket ();
};

}

#endif
#endif