#pragma once

#ifndef _WINSOCK_SOCKET_H_
#define _WINSOCK_SOCKET_H_

#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h> 
#include <string>

namespace kowl
{

struct SocketException
{

};

class WinsockSocket
{
public:
    WinsockSocket (std::string address, uint16_t port);
    WinsockSocket (uint32_t address, uint16_t port);
    WinsockSocket (uint16_t port); // localhost
    ~WinsockSocket ();

    void shutdown ();
};

}

#endif // !_WINSOCK_SOCKET_H_

