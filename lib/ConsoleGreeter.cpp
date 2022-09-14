#include <ConsoleGreeter.hpp>

ConsoleGreeter::ConsoleGreeter()
{

}

ConsoleGreeter::~ConsoleGreeter()
{

}
void ConsoleGreeter::greet(string message) 
{
    cout << "I am the console greeter and the message is: " << message << endl;    
}

instance = new ConsoleGreeter(); 

ConsoleGreeter* getInstance()
{
    return instance;
}