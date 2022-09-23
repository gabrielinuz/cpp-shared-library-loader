/**
* Copyright (c) 2022 Gabriel Nicolás González Ferreira. All rights reserved.
* This file is part of CPPSET tools.
* Released under the MIT license
* https://opensource.org/licenses/MIT
**/
#include <iostream>
#include <SharedLibraryLoader.hpp>
#include <Greeter.hpp>

int main(int argc, char const *argv[])
{
    SharedLibraryLoader libraryLoader;
    libraryLoader.load("./lib/ConsoleGreeter");

    typedef Greeter* ( *LibFunctionPointer ) ();
    LibFunctionPointer libFunctionPointer = (LibFunctionPointer)libraryLoader.getExternSymbol("getInstance");
    Greeter* greeter = libFunctionPointer();
    greeter->greet("Hello World");
    delete greeter;
    return 0;
}
