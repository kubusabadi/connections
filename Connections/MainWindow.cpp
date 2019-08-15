
#include "MainWindow.h"

#include <iostream>
#include <cstdlib>

namespace connections
{
void MainWindow::printWelcome () const
{
    system ("cls");
    std::cout << R"(
   ____                            _   _                 
  / ___|___  _ __  _ __   ___  ___| |_(_) ___  _ __  ___ 
 | |   / _ \| '_ \| '_ \ / _ \/ __| __| |/ _ \| '_ \/ __|
 | |__| (_) | | | | | | |  __/ (__| |_| | (_) | | | \__ \
  \____\___/|_| |_|_| |_|\___|\___|\__|_|\___/|_| |_|___/
                                                       
___________________________________________________________

by Jakub Hejwowski <kubusabadi>
___________________________________________________________


)";
}

Mode  MainWindow::promptForMode () const
{
    for (auto const& [key, val] : modesStrings)
    {
        std::cout << (int)key << ". " <<  std::string(val) << std::endl;
    }

    std::cout << "\nrun Connections application: ";
    int x;
    std::cin >> x;

    return (Mode) x;
}

}