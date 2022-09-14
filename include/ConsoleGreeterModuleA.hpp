#ifndef CONSOLE_GREETER_MODULE_A_HPP
#define CONSOLE_GREETER_MODULE_A_HPP

// #ifndef __DEBUG__
//     #define __DEBUG__
// #endif

#include <iostream>
#include <string>
#include <Greeter.hpp>

using namespace std;

class ConsoleGreeterModuleA : public Greeter
{
    public:
        ConsoleGreeterModuleA();
        ~ConsoleGreeterModuleA();
        void greet(string message);
};

extern "C" ConsoleGreeterModuleA* getInstance();

#endif // CONSOLE_GREETER_MODULE_A_HPP