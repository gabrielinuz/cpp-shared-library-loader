#!/bin/bash
# g++ -shared -Wall -std=c++11 -fPIC -I../include/ consoleGreeter.cpp -o consoleGreeter.so

##option2
# g++ -shared -Wall -std=c++11 -fPIC -I../include/ ConsoleGreeter.cpp -o consoleGreeter.o
# g++ -shared -Wall -std=c++11 -fPIC -I../include/ consoleGreeter.o -o consoleGreeter.so

##option3
g++ -shared -Wall -std=c++11 -fPIC -I../include/ consoleGreeter.cpp -o consoleGreeter.so

## Limpio los códigos objeto
##rm ./*.o