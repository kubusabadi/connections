#ifdef _WIN32

#include "WinsockWrapper.h"
#include <iostream>
namespace connections
{

WinsockWrapper::WinsockWrapper ()
{
    WinsockSocket* ws = socketBuilder.addPort (50000)
        .forType (WinsockSocket::Type::SERVER)
        .forProtocol(WinsockSocket::Protocol::TCP)
        .buildSocket ();
    
    ws->bind ();
    ws->listen ();
    ws->accept ();

    const int BUFF_LEN = 1024;
    char* buffer = new char[BUFF_LEN];
    int i = ws->recv (buffer, BUFF_LEN);
    
    if (i > 0)
    {
        std::cout << buffer << std::endl;
    }

    delete ws;
}

WinsockWrapper::~WinsockWrapper ()
{

}

}

#endif