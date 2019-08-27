
/*
 * Created by Jakub Hejwowski 2019
 * kubusabadi@yahoo.com
*/


#include "Connections.h"
#include "MainWindow.h"

#include <iostream>

#ifdef _WIN32
#include "Sockets/WinsockWrapper.h"
#endif

namespace connections
{

Connections::Connections (Mode mode)
{
    std::cout << " Picked mode: " << (int)mode << std::endl;
}

void Connections::setupMode (Mode mode)
{
    switch (mode)
    {
    case Mode::RECEIVE_TCP:
        break;
    case Mode::SEND_TCP:
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

#ifdef _WIN32
    WinsockWrapper ww;
#endif
    
	return 0;
}
