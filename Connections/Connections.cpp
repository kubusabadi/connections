
/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/

#include "Connections.h"
#include "MainWindow.h"
#include "Modes/TCPEchoServer.h"
#include "Modes/TCPEchoClient.h"
#include "Modes/TCPReceiving.h"
#include "Modes/TCPSending.h"
#include "Modes/UDPReceiving.h"
#include "Modes/UDPSending.h"
#include "Modes/UDPEchoServer.h"
#include "Modes/UDPEchoClient.h"

#include <iostream>

namespace connections
{

Connections::Connections (Mode mode)
{
    std::cout << " Picked mode: " << (int)mode << std::endl;
    setupMode (mode);
}

void Connections::setupMode (Mode mode)
{
    switch (mode)
    {
    case Mode::RECEIVE_TCP:
#ifdef _WIN32
        TCPReceiving tcpRecvMode;
        tcpRecvMode.execute ();
#endif
        break;
    case Mode::SEND_TCP:
#ifdef _WIN32
        TCPSending tcpSendMode;
        tcpSendMode.execute ();
#endif
        break;
    case Mode::RECEIVE_UDP:
#ifdef _WIN32
        UDPReceiving udpReceivingMode;
        udpReceivingMode.execute ();
#endif
        break;
    case Mode::SEND_UDP:
#ifdef _WIN32
        UDPSending udpSendingMode;
        udpSendingMode.execute ();
#endif
        break;
    case Mode::TCP_ECHO_SERVER:
#ifdef _WIN32
        TCPEchoServer echoServer;
        echoServer.execute ();
#endif
        break;
    case Mode::TCP_ECHO_CLIENT:
#ifdef _WIN32
        TCPEchoClient echoClient;
        echoClient.execute ();
#endif
        break;
    case Mode::UDP_ECHO_SERVER:
#ifdef _WIN32
        UDPEchoServer udpEchoServer;
        udpEchoServer.execute ();
#endif
        break;
    case Mode::UDP_ECHO_CLIENT:
#ifdef _WIN32
        UDPEchoClient udpEchoClient;
        udpEchoClient.execute ();
#endif
        break;
    }
}

}

using namespace connections;

int main()
{
    MainWindow mw;
    mw.printWelcome ();
    
    while (true)
    {
        Mode mode = mw.promptForMode ();
        
        if (mode == Mode::EXIT)
        {
            break;
        }

        mw.printWelcome ();
        Connections connections{ mode };
    }

	return 0;
}
