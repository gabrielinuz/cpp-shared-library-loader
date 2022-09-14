/**
 *  Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**/

// #ifndef __DEBUG__
//     #define __DEBUG__
// #endif

#include <Greeter.hpp>
#include <iostream>
#include <string>

using namespace std;

class ConsoleGreeter : public Greeter
{
    public:
        ConsoleGreeter()
        {
            #ifdef __DEBUG__
                cout << "create ConsoleGreeter from shared library..." << endl;
            #endif // __DEBUG__
        }
        virtual ~ConsoleGreeter()
        {
            #ifdef __DEBUG__
                cout << "delete ConsoleGreeter from shared library..." << endl;
            #endif // __DEBUG__
        }
        void greet(string message)
        {
            cout << "  Hi, I am the console greeter and the message is: " << message << endl;
        }
};

extern "C" ConsoleGreeter* getInstance()
{
    return new ConsoleGreeter();
}
