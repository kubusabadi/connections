/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/

#ifdef _WIN32

#include "WinsockSocketBuilder.h"
#include "WinsockSocketClient.h"
#include "WinsockSocketServer.h"
#include "WinsockSocketServerTCP.h"
#include "WinsockSocketServerUDP.h"

#include "Error.h"

namespace connections
{

WinsockSocketBuilder::WinsockSocketBuilder ()
{
}

WinsockSocketBuilder& WinsockSocketBuilder::addPort (uint16_t port)
{
    this->port = port;
    return *this;
}

WinsockSocketBuilder& WinsockSocketBuilder::addHost (std::string host)
{
    this->host = host;
    return *this;
}

WinsockSocketBuilder& WinsockSocketBuilder::forType (WinsockSocket::Type sockType)
{
    type = sockType;
    return *this;
}

WinsockSocketBuilder& WinsockSocketBuilder::forProtocol (WinsockSocket::Protocol sockProtocol)
{
    protocol = sockProtocol;
    return *this;
}

WinsockSocket* WinsockSocketBuilder::buildSocket ()
{
    switch (type)
    {
    case WinsockSocket::Type::SERVER:
        return buildServer ();
    case WinsockSocket::Type::CLIENT:
        return buildClient ();
    default:
        throw new BadBuilding{ "Type unspecified" };
    }
}

WinsockSocket* WinsockSocketBuilder::buildClient ()
{
    if (!portSet ())
    {
        throw new BadBuilding{ "No port specified." };
    }

    if (!hostSet ())
    {
        throw new BadBuilding{ "No host specified" };
    }

    //switch (protocol)
    //{
    //case WinsockSocket::Protocol::TCP:
    //    return buildServer ();
    //case WinsockSocket::Protocol::UDP:
    //    return buildClient ();
    //default:
    //    throw new BadBuilding{ "Protocol unspecified" };
    //}

    return new WinsockSocketClient{ port, host };
}

WinsockSocket* WinsockSocketBuilder::buildServer ()
{
    if (!portSet ())
    {
        throw new BadBuilding{ "No port specified." };
    }

    switch (protocol)
    {
    case WinsockSocket::Protocol::TCP:
        return new WinsockSocketServerTCP{ port };
    case WinsockSocket::Protocol::UDP:
        return new WinsockSocketServerUDP{ port };
    default:
        throw new BadBuilding{ "Protocol unspecified" };
    }
}

}

#endif