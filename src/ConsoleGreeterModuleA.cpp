#include <ConsoleGreeterModuleA.hpp>

ConsoleGreeterModuleA::ConsoleGreeterModuleA()
{
    #ifdef __DEBUG__
        cout << "create ConsoleGreeterModuleA from shared library..." << endl;
    #endif // __DEBUG__
}

ConsoleGreeterModuleA::~ConsoleGreeterModuleA()
{
    #ifdef __DEBUG__
        cout << "delete ConsoleGreeterModuleA from shared library..." << endl << endl;
    #endif // __DEBUG__
}
void ConsoleGreeterModuleA::greet(string message) 
{
    cout << "Hi, I am the console greeter module A and the message is: " << message << endl; 
}

ConsoleGreeterModuleA* getInstance()
{
    return new ConsoleGreeterModuleA();
}