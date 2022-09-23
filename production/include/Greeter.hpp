#ifndef GREETER_HPP
#define GREETER_HPP

#include <string>
using namespace std;

class Greeter
{
    public:
        virtual ~Greeter() {}
        virtual void greet(string message) = 0;
};

#endif // GREETER_HPP