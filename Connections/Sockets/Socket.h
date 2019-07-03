#pragma once

#ifndef _SOCKET_H_
#define _SOCKET_H_

#include <stdint.h>

namespace kowl
{

class SocketListener
{
public:
    virtual void onReceive (uint8_t* buffer, size_t size ) = 0;
};

class Socket
{
public:
    virtual void send (uint8_t* buffer, size_t size) = 0;
    virtual ~Socket () = default;
};

class SocketClient : public Socket
{
      
};

class SocketServer
{

};
}

#endif // !_SOCKET_H_
