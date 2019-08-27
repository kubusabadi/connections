/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/
#ifdef _WIN32

#pragma once

#ifndef _WINSOCK_SOCKET_SERVER_H_
#define _WINSOCK_SOCKET_SERVER_H_


#include "WinsockSocket.h"

#include <string>

#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h> 
#include <ws2tcpip.h>

namespace connections
{

class WinsockSocketServer : public WinsockSocket
{
public:
    WinsockSocketServer ();
    WinsockSocketServer (uint16_t srvPort); // localhost
    virtual ~WinsockSocketServer ();

    void listen () override;
    void accept () override;
    void bind () override;
    void connect () override;

    int receive (char* buffer, int lenght) override;

protected:
    uint16_t port = 0;
    SOCKET listenSocket = INVALID_SOCKET;
    SOCKET clientSocket = INVALID_SOCKET;
    addrinfo* addressInfo = NULL;

    virtual void setupAddressInfo () = 0;
};

}

#endif
#endif
