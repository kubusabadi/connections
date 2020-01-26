

#ifdef _WIN32
#ifndef _WINSOCK_SOCKET_SERVER_UDP_H_
#define _WINSOCK_SOCKET_SERVER_UDP_H_

#include "WinsockSocketServer.h"

namespace connections
{
class WinsockSocketServerUDP : public WinsockSocketServer
{
public:
    WinsockSocketServerUDP (uint16_t srvPort);
    ~WinsockSocketServerUDP ();

    void listen () override;
    void accept () override;
    void bind () override;

    int recvfrom (char* buffer, int lenght) override;
    int sendto (char* buffer, int lenght) override;

    int send (char* buffer, int lenght) override;
    int recv (char* buffer, int lenght) override;
    int close () override;

private:
    SOCKET listenSocket = INVALID_SOCKET;

    sockaddr_in sockAddr;

    void setupSocket ();
};

}

#endif
#endif