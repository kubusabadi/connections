
#include "Error.h"
#include <map>

namespace connections
{

static std::map<int, std::string> wsaErrors = {
    {}
};

std::string getWSAError (int errorCode)
{
    if (wsaErrors.find(errorCode) != wsaErrors.end())
    {
        return wsaErrors[errorCode];
    }

    return "WinSock error " + errorCode;
}

}