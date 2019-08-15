
#ifndef _CONNECTIONS_H_
#define _CONNECTIONS_H_

#include <map>
#include <string>

namespace connections 
{

enum class Mode 
{
    RECEIVE_TCP = 1,
    SEND_TCP
};

const std::map<Mode, std::string> modesStrings { 
    { Mode::RECEIVE_TCP, "receive tcp" },
    { Mode::SEND_TCP, "send tcp"}
};

class MainWindow;

class Connections
{
public:
    Connections (Mode mode);

private:
    void setupMode (Mode mode);

};

}

#endif