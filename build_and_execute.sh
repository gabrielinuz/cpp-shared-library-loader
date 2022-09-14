#!/bin/bash
## Compilo el Binario
g++ -Wall -std=c++11 -ldl -I./include -I./include/vendors/cppset main.cpp -o ./consoleGreeterApp.bin 

## Permisos de Ejecución para el binario
chmod +x ./consoleGreeterApp.bin

## Ejecuto el binario:
./consoleGreeterApp.bin