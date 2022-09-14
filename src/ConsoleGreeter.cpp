#include <ConsoleGreeter.hpp>

ConsoleGreeter::ConsoleGreeter()
{
    #ifdef __DEBUG__
        cout << "create ConsoleGreeter module from shared library..." << endl;
    #endif // __DEBUG__
}

ConsoleGreeter::~ConsoleGreeter()
{
    #ifdef __DEBUG__
        cout << "delete ConsoleGreeter module from shared library..." << endl << endl;
    #endif // __DEBUG__
}
void ConsoleGreeter::greet(string message) 
{
    cout << "  I am the console greeter and the message is: " << message << endl; 
}

ConsoleGreeter* getInstance()
{
    return new ConsoleGreeter();
}