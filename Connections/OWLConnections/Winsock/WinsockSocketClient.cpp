
#ifdef _WIN32

#include "WinsockSocketClient.h"
#include "Printer.h"
#include <iostream>
#include <string>
#include "Error.h"

namespace connections
{
static const Printer PRINTER (std::cout, "Sockets");

WinsockSocketClient::WinsockSocketClient (uint16_t port, std::string address) : port{ port }, host{ address }
{
}

WinsockSocketClient::~WinsockSocketClient ()
{
}

void WinsockSocketClient::listen ()
{
    throw new BadOperation{ "Attempting to perform server operation on client socket." };
}

void WinsockSocketClient::accept ()
{
    throw new BadOperation{ "Attempting to perform server operation on client socket." };
}

void WinsockSocketClient::bind ()
{
    throw new BadOperation{ "Attempting to perform server operation on client socket." };
}

}

#endif