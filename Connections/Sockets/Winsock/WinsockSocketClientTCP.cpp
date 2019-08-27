/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/
#ifdef _WIN32

#include "WinsockSocketClientTCP.h"

namespace connections
{


WinsockSocketClientTCP::WinsockSocketClientTCP ()
{

}

WinsockSocketClientTCP::WinsockSocketClientTCP (uint16_t port, std::string address) : WinsockSocketClient{ port, address }
{

}

WinsockSocketClientTCP::WinsockSocketClientTCP (uint16_t port) : WinsockSocketClient{ port }
{

}

WinsockSocketClientTCP::~WinsockSocketClientTCP ()
{}
}

#endif