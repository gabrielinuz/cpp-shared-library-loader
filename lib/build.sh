#!/bin/bash
g++ -shared -Wall -std=c++11 -fPIC -I../include/ ../src/ConsoleGreeter.cpp -o ConsoleGreeter.so

