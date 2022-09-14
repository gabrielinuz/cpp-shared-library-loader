#!/bin/bash
g++ -shared -Wall -std=c++11 -fPIC -I../include/ ../src/ConsoleGreeterModuleA.cpp -o ConsoleGreeterModuleA.so
g++ -shared -Wall -std=c++11 -fPIC -I../include/ ../src/ConsoleGreeterModuleB.cpp -o ConsoleGreeterModuleB.so

