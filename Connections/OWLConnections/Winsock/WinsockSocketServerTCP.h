
#ifdef _WIN32

#ifndef _WINSOCK_SOCKET_SERVER_TCP_H_
#define _WINSOCK_SOCKET_SERVER_TCP_H_

#include "WinsockSocketServer.h"

namespace connections
{

class WinsockSocketServerTCP : public WinsockSocketServer
{
public:
    WinsockSocketServerTCP (uint16_t srvPort); // localhost
    ~WinsockSocketServerTCP ();

    void listen () override;
    void accept () override;
    void bind () override;

    int send (char* buffer, int lenght) override;
    int recv (char* buffer, int lenght) override;

    int recvfrom (char* buffer, int lenght) override;
    int sendto (char* buffer, int lenght) override;

private:
    SOCKET listenSocket = INVALID_SOCKET;
    SOCKET clientSocket = INVALID_SOCKET;

    sockaddr_in sockAddr;

    void setupSocket ();
};

}
#endif
#endif