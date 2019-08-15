#ifdef _WIN32

#include "WinsockWrapper.h"
#include <iostream>
namespace connections
{

WinsockWrapper::WinsockWrapper () : ws(50000)
{
    ws.listen ();
    ws.accept ();

    const int BUFF_LEN = 1024;
    char* buffer = new char[BUFF_LEN];
    int i = ws.receive (buffer, BUFF_LEN);
    
    if (i > 0)
    {
        std::cout << buffer << std::endl;
    }
}

WinsockWrapper::~WinsockWrapper ()
{

}

}

#endif