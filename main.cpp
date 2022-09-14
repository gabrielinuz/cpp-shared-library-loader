#include <iostream>
#include <SharedLibraryLoader.hpp>
#include <Greeter.hpp>

int main()
{
    /*Way 1*/
    // SharedLibraryLoader loader;
    // loader.loadLibrary("./lib/consoleGreeter");

    /*Way 2*/
    SharedLibraryLoader loader("./lib/consoleGreeter");

    //Obtener object from symbol
    Greeter* consoleGreeter = loader.getFunctionFromSymbol<Greeter*>("getInstance");

    //Símbolo erróneo:
    // Greeter* consoleGreeter = loader.getFunctionFromSymbol<Greeter*>("getObject");
    
    
    //Ejecucion
    consoleGreeter->greet("Hello World!");

    //Borrado
    delete consoleGreeter;

    loader.freeLibrary(); // Not releasing library not loaded! Releasing by the SharedLibraryLoader destructor 
    
    return EXIT_SUCCESS;
}
