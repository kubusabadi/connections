
#ifdef _WIN32

#ifndef _WINSOCK_SOCKET_SERVER_TCP_H_
#define _WINSOCK_SOCKET_SERVER_TCP_H_

#include "WinsockSocketServer.h"

namespace connections
{

class WinsockSocketServerTCP : public WinsockSocketServer
{
public:
    WinsockSocketServerTCP ();
    WinsockSocketServerTCP (uint16_t srvPort); // localhost
    ~WinsockSocketServerTCP ();

protected:
    void setupAddressInfo () override;
};

}
#endif
#endif