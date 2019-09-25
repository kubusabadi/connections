
#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include "Connections.h"

namespace connections
{
class MainWindow
{
public:
    void printWelcome () const;
    Mode promptForMode () const;
};
}

#endif