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
    WinsockSocketClientTCP ();
    WinsockSocketClientTCP (uint16_t port, std::string address);
    WinsockSocketClientTCP (uint16_t port);
    virtual ~WinsockSocketClientTCP ();

};

}

#endif
#endif