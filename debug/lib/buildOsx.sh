#!/bin/bash
g++ -shared -Wall -std=c++11 -fPIC -I../include/ consoleGreeter.cpp -o consoleGreeter.dylib
