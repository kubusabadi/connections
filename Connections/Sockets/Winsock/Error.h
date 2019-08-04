
#ifdef _WIN32

#pragma once

#ifndef _ERROR_H_
#define _ERROR_H_

#include <string>

namespace connections
{

std::string getWSAError (int errorCode);

struct BadWinsock
{
    BadWinsock (std::string msg) : msg{ msg } { }
    std::string msg;
};

}

#endif
#endif