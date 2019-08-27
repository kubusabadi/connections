
#ifdef _WIN32

#include "WinsockSocketServerUDP.h"

namespace connections
{

WinsockSocketServerUDP::WinsockSocketServerUDP ()
{

}

WinsockSocketServerUDP::WinsockSocketServerUDP (uint16_t srvPort) : WinsockSocketServer{ srvPort }
{
}

WinsockSocketServerUDP::~WinsockSocketServerUDP ()
{

}

void WinsockSocketServerUDP::setupAddressInfo ()
{
}

}

#endif