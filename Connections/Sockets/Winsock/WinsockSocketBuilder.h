/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/
#ifdef _WIN32

#pragma once

#ifndef _WINSOCK_SOCKET_BUILDER_H_
#define _WINSOCK_SOCKET_BUILDER_H_

#include <string>
#include "WinsockSocket.h"

namespace connections
{

class WinsockSocketBuilder
{
public:
    WinsockSocketBuilder ();
   
    WinsockSocketBuilder& addPort (uint16_t port);
    WinsockSocketBuilder& addHost (std::string host);

    WinsockSocketBuilder& forType (WinsockSocket::Type sockType);
    WinsockSocketBuilder& forProtocol(WinsockSocket::Protocol sockProtocol);
    WinsockSocket* buildSocket ();

private:
    WinsockSocket* buildClient ();
    WinsockSocket* buildServer ();

    bool portSet () { return port != 0; }
    bool hostSet () { return !host.empty (); }
    
    uint16_t port = 0;
    std::string host = "";
    WinsockSocket::Type type = WinsockSocket::Type::UNSPEC;
    WinsockSocket::Protocol protocol = WinsockSocket::Protocol::UNSPEC;
};

}

#endif
#endif