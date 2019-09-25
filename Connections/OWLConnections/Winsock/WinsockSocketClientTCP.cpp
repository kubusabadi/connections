/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/
#ifdef _WIN32

#include <iostream>
#include "Printer.h"
#include "WinsockSocketClientTCP.h"
#include "Error.h"

namespace connections
{
static const Printer PRINTER (std::cout, "Sockets client TCP");


WinsockSocketClientTCP::WinsockSocketClientTCP ()
{

}

WinsockSocketClientTCP::WinsockSocketClientTCP (uint16_t port, std::string address) : WinsockSocketClient{ port, address }
{
    setupAddressInfo ();
    setupSocket ();
}

WinsockSocketClientTCP::WinsockSocketClientTCP (uint16_t port) : WinsockSocketClient{ port }
{

}

WinsockSocketClientTCP::~WinsockSocketClientTCP ()
{
}

void WinsockSocketClientTCP::setupAddressInfo ()
{
    int result;
    struct addrinfo hints;

    sockAddr.sin_family = AF_INET;
    sockAddr.sin_addr.s_addr = inet_addr (host.c_str ());
    sockAddr.sin_port = htons (port);

    PRINTER << "Resolve address " << port << Printer::endl;
}

}

#endif