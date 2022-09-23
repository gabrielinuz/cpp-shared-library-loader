:: Compilo código objeto
g++ -shared -Wall -std=c++11 -I.\include\ .\src\ConsoleGreeter.cpp -o .\lib\ConsoleGreeter.dll

:: Compilo el Binario
g++ -Wall -std=c++11 -ldl -I.\include -I.\include\vendors\cppset main.cpp -o .\consoleGreeterApp.exe

:: Limpio los códigos objeto
DEL .\*.o

:: Ejecuto el binario:
consoleGreeterApp.exe