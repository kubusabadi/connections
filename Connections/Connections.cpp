
/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/

#include "Connections.h"
#include "MainWindow.h"
#include "Modes/TCPReceiving.h"
#include "Modes/TCPSending.h"

#include <iostream>

#ifdef _WIN32
#include "Sockets/WinsockWrapper.h"
#endif

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
    }
}

}

using namespace connections;

int main()
{
    MainWindow mw;
    mw.printWelcome ();
    
    Mode mode = mw.promptForMode ();

    mw.printWelcome ();
    Connections connections{ mode };
	return 0;
}
