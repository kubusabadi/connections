

#ifdef _WIN32
#ifndef _WINSOCK_SOCKET_SERVER_UDP_H_
#define _WINSOCK_SOCKET_SERVER_UDP_H_

#include "WinsockSocketServer.h"

namespace connections
{
class WinsockSocketServerUDP : public WinsockSocketServer
{
public:
    WinsockSocketServerUDP ();
    WinsockSocketServerUDP (uint16_t srvPort);
    ~WinsockSocketServerUDP ();

protected:
    void setupAddressInfo () override;
};

}

#endif
#endif