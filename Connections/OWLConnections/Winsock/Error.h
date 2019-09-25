
#ifdef _WIN32

#pragma once

#ifndef _ERROR_H_
#define _ERROR_H_

#include <string>

namespace connections
{

std::string getWSAError (int errorCode);

/// Base struct for exception during work with WinsockException
struct WinsockError
{
    WinsockError (int code) : code{ code } { }
    WinsockError (std::string msg) : msg{ msg } { }
    std::string msg;
    int code = 0;
};

/// Exceptions from Winsock itself
struct BadWinsock : WinsockError
{
    BadWinsock (int code) : WinsockError{ code } { }
    BadWinsock (std::string msg) : WinsockError{ msg } { }
};

/// Exception with wrong operation for given type of socket
struct BadOperation : WinsockError
{
    BadOperation (int code) : WinsockError{ code } { }
    BadOperation (std::string msg) : WinsockError{ msg } { }
};

/// Exception with error while building socket
struct BadBuilding : WinsockError
{
    BadBuilding (int code) : WinsockError{ code } { }
    BadBuilding (std::string msg) : WinsockError{ msg } { }
};

}

#endif
#endif