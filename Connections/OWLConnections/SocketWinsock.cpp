/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/

#ifdef _WIN32

#include "SocketWinsock.h"

namespace connections
{

SocketWinsock::SocketWinsock (WinsockSocket* ws) : winsockSocket(ws)
{
}

void SocketWinsock::listen ()
{
    winsockSocket->listen();
}

void SocketWinsock::accept ()
{
    winsockSocket->accept ();
}

void SocketWinsock::bind ()
{
    winsockSocket->bind ();
}

void SocketWinsock::connect ()
{
    winsockSocket->connect ();
}

int SocketWinsock::send (char* buffer, int lenght)
{
    return winsockSocket->send (buffer, lenght);
}

int SocketWinsock::recv (char* buffer, int lenght)
{
    return winsockSocket->recv (buffer, lenght);
}

int SocketWinsock::recvfrom (char* buffer, int lenght)
{
    return winsockSocket->recvfrom (buffer, lenght);
}

int SocketWinsock::sendto (char* buffer, int lenght)
{
    return winsockSocket->sendto (buffer, lenght);
}

int SocketWinsock::close ()
{
    return winsockSocket->close ();
}

}

#endif