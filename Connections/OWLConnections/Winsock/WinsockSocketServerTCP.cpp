
#ifdef _WIN32

#include "WinsockSocketServerTCP.h"
#include "Printer.h"
#include <iostream>
#include <string>
#include "Error.h"

namespace connections
{

static const Printer PRINTER (std::cout, "Sockets server TCP");

WinsockSocketServerTCP::WinsockSocketServerTCP ()
{

}

WinsockSocketServerTCP::WinsockSocketServerTCP (uint16_t srvPort) : WinsockSocketServer{ srvPort }
{
    setupAddressInfo ();
}

WinsockSocketServerTCP::~WinsockSocketServerTCP ()
{

}

void WinsockSocketServerTCP::setupAddressInfo ()
{
    listenSockAddr.sin_family = AF_INET;
    listenSockAddr.sin_addr.s_addr = inet_addr ("127.0.0.1");
    listenSockAddr.sin_port = htons (port);

    PRINTER << "Resolve address " << port << Printer::endl;
}

}

#endif