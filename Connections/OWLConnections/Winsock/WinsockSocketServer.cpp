/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/
#ifdef _WIN32

#include "WinsockSocketServer.h"
#include "Printer.h"
#include <iostream>
#include <string>
#include "Error.h"

namespace connections
{

static const Printer PRINTER (std::cout, "Sockets");

WinsockSocketServer::WinsockSocketServer (uint16_t srvPort)
{
    port = srvPort;
}

WinsockSocketServer::~WinsockSocketServer ()
{
}

void WinsockSocketServer::connect ()
{
    throw new BadOperation{ "Attempting to perform client operation on server socket." };
}

}

#endif