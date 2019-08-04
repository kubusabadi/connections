
#include "Connections.h"

#ifdef _WIN32
#include "Sockets/WinsockWrapper.h"
#endif

using namespace connections;

void MainWindow::printWelcome () const
{
    std::cout << R"(
   ____                            _   _                 
  / ___|___  _ __  _ __   ___  ___| |_(_) ___  _ __  ___ 
 | |   / _ \| '_ \| '_ \ / _ \/ __| __| |/ _ \| '_ \/ __|
 | |__| (_) | | | | | | |  __/ (__| |_| | (_) | | | \__ \
  \____\___/|_| |_|_| |_|\___|\___|\__|_|\___/|_| |_|___/
                                                       
)";
}

int main()
{
    MainWindow mw;
    mw.printWelcome ();
#ifdef _WIN32
    WinsockWrapper ww;
#endif

	return 0;
}
