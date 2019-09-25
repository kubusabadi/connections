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
    WinsockSocketClientUDP ();
    WinsockSocketClientUDP (uint16_t port, std::string address);
    WinsockSocketClientUDP (uint16_t port);
    virtual ~WinsockSocketClientUDP ();
};

}

#endif
#endif