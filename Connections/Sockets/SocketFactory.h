#pragma once

#ifndef _SOCKET_FACTORY_H_
#define _SOCKET_FACTORY_H_

#include "Socket.h"

namespace kowl
{

class SocketFactory
{
public:
    virtual Socket* make () = 0;
};

}

#endif // !_SOCKET_FACTORY_H_
