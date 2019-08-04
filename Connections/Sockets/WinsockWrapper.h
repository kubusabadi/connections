
#ifdef _WIN32

#pragma once

#ifndef _WINSOCK_WRAPPER_H_
#define _WINSOCK_WRAPPER_H_

#include "Winsock/WinsockSocket.h"

namespace connections
{

class WinsockWrapper
{
public:
    WinsockWrapper ();
    ~WinsockWrapper ();

private:
    WinsockSocket ws;
};

}
#endif
#endif
