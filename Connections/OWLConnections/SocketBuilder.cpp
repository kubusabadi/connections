
#include "SocketBuilder.h"
#include "SocketWinsock.h"

namespace connections
{

SocketBuilder::SocketBuilder ()
{

}

SocketBuilder& SocketBuilder::addPort (uint16_t port)
{
    this->port = port;
    return *this;
}

SocketBuilder& SocketBuilder::addHost (std::string host)
{
    this->host = host;
    return *this;
}

SocketBuilder& SocketBuilder::forType (Socket::Type sockType)
{
    type = sockType;
    return *this;
}

SocketBuilder& SocketBuilder::forProtocol (Socket::Protocol sockProtocol)
{
    protocol = sockProtocol;
    return *this;
}

Socket* SocketBuilder::buildSocket ()
{
#ifdef WIN32
    WinsockSocket::Type wtype = (type == Socket::Type::CLIENT) ?
        WinsockSocket::Type::CLIENT : WinsockSocket::Type::SERVER;

    WinsockSocket::Protocol wprotocol = (protocol == Socket::Protocol::TCP) ?
        WinsockSocket::Protocol::TCP : WinsockSocket::Protocol::UDP;

    WinsockSocket* ws = buildWinsock (wtype, wprotocol);

    return new SocketWinsock (ws);
#endif
    return nullptr;
}

#ifdef WIN32
WinsockSocket* SocketBuilder::buildWinsock (WinsockSocket::Type type, WinsockSocket::Protocol protocol)
{
    WinsockSocketBuilder socketBuilder;
    return socketBuilder.addHost (host)
        .addPort (port)
        .forType (type)
        .forProtocol (protocol)
        .buildSocket();
}
#endif


}