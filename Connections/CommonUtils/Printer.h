
#ifndef _PRINTER_H_
#define _PRINTER_H_

#include <iostream>
#include <string>

namespace connections
{
class Printer
{
public:
    struct Endl {};
    static Endl endl;

    Printer (std::ostream& out, std::string tag) : out{out}, tag{tag} { };

    template<typename T>
    const Printer& operator<<(T msg) const
    {
        if (startLine)
        {
            out << "[" << tag << "] ";
            startLine = false;
        }
        out << msg;
        return *this;
    }

    const Printer& operator<<(std::string msg) const
    {
        if (startLine)
        {
            out << "[" << tag << "] ";
            startLine = false;
        }
        out << msg;

        if (msg.back () == '\n')
        {
            startLine = true;
        }

        return *this;
    }

    const Printer& operator<<(Endl e) const
    {
        out << std::endl;
        startLine = true;
        return *this;
    }

private:
    mutable bool startLine = true;
    std::ostream& out;
    std::string tag;
};
}

#endif