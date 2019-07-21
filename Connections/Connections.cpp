// Connections.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "Connections.h"
#include "Sockets/TCPConnection.h"

using namespace kowl;

void printWelcome ();

int main()
{
    printWelcome ();

    TCPConnection tpcConn;
	return 0;
}

void printWelcome ()
{
    std::cout << R"(
   ____                            _   _                 
  / ___|___  _ __  _ __   ___  ___| |_(_) ___  _ __  ___ 
 | |   / _ \| '_ \| '_ \ / _ \/ __| __| |/ _ \| '_ \/ __|
 | |__| (_) | | | | | | |  __/ (__| |_| | (_) | | | \__ \
  \____\___/|_| |_|_| |_|\___|\___|\__|_|\___/|_| |_|___/
                                                       
)";
                         
    std::cout << "___________________________________________________________\n";
}
