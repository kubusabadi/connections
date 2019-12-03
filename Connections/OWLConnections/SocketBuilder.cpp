
#include "SocketBuilder.h"

#ifdef WIN32
#include "Winsock/WinsockSocketBuilder.h"
#endif


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
    switch (type)
    {
    case Socket::Type::SERVER:
        return buildServer ();
    case Socket::Type::CLIENT:
        return buildClient ();
    }
}

Socket* SocketBuilder::buildClient ()
{
    return nullptr;
}

Socket* SocketBuilder::buildServer ()
{
    return nullptr;
}

}