/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/
#ifdef _WIN32

#ifndef _WINSOCK_SOCKET_CLIENT_H_
#define _WINSOCK_SOCKET_CLIENT_H_

#include "WinsockSocket.h"

#include <string>

#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h> 
#include <ws2tcpip.h>

namespace connections
{

class WinsockSocketClient : public WinsockSocket
{
public:
    WinsockSocketClient ();
    WinsockSocketClient (uint16_t port, std::string address);
    WinsockSocketClient (uint16_t port); // localhost
    virtual ~WinsockSocketClient ();

    void connect ();
    int receive (char* buffer, int lenght);
    int send (char* buffer, int lenght);

    virtual void listen () override;
    virtual void accept () override;
    virtual void bind () override;

private:
    uint16_t port = 0;
    std::string host = "";
    SOCKET clientSocket = INVALID_SOCKET;
    addrinfo* addrResult = NULL;

    void setupAddressInfo ();
    void setupSocket ();
};

}

#endif // !_WINSOCK_SOCKET_H_

#endif
