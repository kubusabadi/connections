/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/

#pragma once

#ifndef _SOCKET_BUILDER_H_
#define _SOCKET_BUILDER_H_

#include "Socket.h"

#include <string>

namespace connections
{

class SocketBuilder
{
public:
    SocketBuilder ();

    SocketBuilder& addPort (uint16_t port);
    SocketBuilder& addHost (std::string host);

    SocketBuilder& forType (Socket::Type sockType);
    SocketBuilder& forProtocol (Socket::Protocol sockProtocol);
    Socket* buildSocket ();

private:
    Socket* buildClient ();
    Socket* buildServer ();

    bool portSet () { return port != 0; }
    bool hostSet () { return !host.empty (); }

    uint16_t port = 0;
    std::string host = "";
    Socket::Type type = Socket::Type::UNSPEC;
    Socket::Protocol protocol = Socket::Protocol::UNSPEC;
};

}

#endif