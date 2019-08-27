
#ifdef _WIN32

#pragma once

#ifndef _WINSOCK_WRAPPER_H_
#define _WINSOCK_WRAPPER_H_

#include "Winsock/WinsockSocketServer.h"
#include "Winsock/WinsockSocketClient.h"
#include "Winsock/WinsockSocketBuilder.h"

namespace connections
{

class WinsockWrapper
{
public:
    WinsockWrapper ();
    ~WinsockWrapper ();

private:
    WinsockSocketBuilder socketBuilder;
};

}
#endif
#endif
