/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/

/*
 *              TCP                             UDP

 *       Server         Client
 *         |              |
 *       Socket         Socket
 *         |              |
 *     SetSockOpt         |
 *         |              |
 *        Bind            |
 *         |              |
 *       Listen  <---  Connect             Connectionless
 *         |              |
 *       Accept           |                   No accept
 *         |              |
 *     Send/Recv  <-> Send/Recv            Sendto/Recvfrom
 */

#pragma once

#ifndef _SOCKET_H_
#define _SOCKET_H_

namespace connections
{

class Socket
{
public:
    enum class Protocol
    {
        UNSPEC,
        TCP,
        UDP
    };

    enum class Type
    {
        UNSPEC,
        SERVER,
        CLIENT
    };

    // Server API
    virtual void listen () = 0;
    virtual void accept () = 0;
    virtual void bind () = 0;

    // Client API
    virtual void connect () = 0;

    // Common API
    virtual int send (char* buffer, int lenght) = 0;
    virtual int recv (char* buffer, int lenght) = 0;

    virtual int recvfrom (char* buffer, int lenght) = 0;
    virtual int sendto (char* buffer, int lenght) = 0;

    virtual int close () = 0;
};

}

#endif