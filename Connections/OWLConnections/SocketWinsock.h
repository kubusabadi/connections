/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/

#ifdef _WIN32

#include "Socket.h"

#include "Winsock/WinsockSocket.h"

namespace connections
{

class SocketWinsock : public Socket
{
public:
    SocketWinsock (WinsockSocket*);

    // Server API
    void listen () override;
    void accept () override;
    void bind () override;

    // Client API
    void connect () override;

    // Common API
    int send (char* buffer, int lenght) override;
    int recv (char* buffer, int lenght) override;

    int recvfrom (char* buffer, int lenght) override;
    int sendto (char* buffer, int lenght) override;

    int close () override;

private:
    WinsockSocket* winsockSocket;
};

}

#endif