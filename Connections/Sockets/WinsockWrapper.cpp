#ifdef _WIN32

#include "WinsockWrapper.h"

namespace kowl
{

WinsockWrapper::WinsockWrapper () : ws("", 50000)
{
    ws.listen ();
    ws.accept ();
    ws.receive ();
}

WinsockWrapper::~WinsockWrapper ()
{

}

}

#endif