
#ifndef _CONNECTIONS_H_
#define _CONNECTIONS_H_

#include <map>
#include <string>

namespace connections 
{

enum class Mode 
{
    RECEIVE_TCP = 1,
    SEND_TCP,
    RECEIVE_UDP,
    SEND_UDP,
    TCP_ECHO_SERVER,
    TCP_ECHO_CLIENT,
    UDP_ECHO_SERVER,
    UDP_ECHO_CLIENT,
    EXIT
};

const std::map<Mode, std::string> modesStrings { 
    { Mode::RECEIVE_TCP, "receive tcp" },
    { Mode::SEND_TCP, "send tcp"},
    { Mode::RECEIVE_UDP, "receive udp" },
    { Mode::SEND_UDP, "send udp" },
    { Mode::TCP_ECHO_SERVER, "run tcp echo server" },
    { Mode::TCP_ECHO_CLIENT, "run tcp echo client" },
    { Mode::UDP_ECHO_SERVER, "run udp echo server" },
    { Mode::UDP_ECHO_CLIENT, "run udp echo client" },
    { Mode::EXIT, "exit program" },
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