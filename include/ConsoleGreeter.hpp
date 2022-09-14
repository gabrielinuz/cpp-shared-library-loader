#ifndef CONSOLEGREETER_HPP
#define CONSOLEGREETER_HPP

#include <iostream>
#include <string>
#include <Greeter.hpp>

using namespace std;

class ConsoleGreeter : public Greeter
{
    public:
        ConsoleGreeter();
        ~ConsoleGreeter();
        void greet(string message);
};

extern "C" ConsoleGreeter* instance;
extern "C" ConsoleGreeter* getInstance();

#endif