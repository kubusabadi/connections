
#ifndef _PRINTER_H_
#define _PRINTER_H_

#include <iostream>
#include <string>

namespace connections
{
class Printer
{
public:
    Printer (std::ostream& out, std::string tag) : out{out}, tag{tag} { };

    const Printer& operator<<(std::string msg) const
    {
        out << "[" << tag << "] "  << msg << std::endl;
        return *this;
    }

private:
    std::ostream& out;
    std::string tag;
};
}

#endif