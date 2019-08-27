/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/
#ifdef _WIN32

#include "WinsockSocketClientUDP.h"

namespace connections
{


WinsockSocketClientUDP::WinsockSocketClientUDP ()
{

}

WinsockSocketClientUDP::WinsockSocketClientUDP (uint16_t port, std::string address) : WinsockSocketClient{ port, address }
{

}

WinsockSocketClientUDP::WinsockSocketClientUDP (uint16_t port) : WinsockSocketClient{ port }
{

}

WinsockSocketClientUDP::~WinsockSocketClientUDP ()
{}
}

#endif