#!/bin/bash

##option1
g++ -shared -Wall -std=c++11 -fPIC -I../include/ ../src/ConsoleGreeter.cpp -o consoleGreeter.so

##option2
# g++ -shared -Wall -std=c++11 -fPIC -I../include/ ../src/consoleGreeter.cpp -o consoleGreeter.so
