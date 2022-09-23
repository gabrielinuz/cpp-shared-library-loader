#!/bin/bash
##Compilo las librerías
g++ -shared -Wall -std=c++11 -fPIC -I./include/ ./src/ConsoleGreeter.cpp -o ./lib/ConsoleGreeter.so

## Compilo el Binario
g++ -Wall -std=c++11 -ldl -I./include -I./include/vendors/cppset main.cpp -o ./consoleGreeterApp.bin 

## Permisos de Ejecución para el binario
chmod +x ./consoleGreeterApp.bin

## Ejecuto el binario:
./consoleGreeterApp.bin