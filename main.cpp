/**
* Copyright (c) 2022 Gabriel Nicolás González Ferreira. All rights reserved.
* This file is part of CPPSET tools.
* Released under the MIT license
* https://opensource.org/licenses/MIT
**/

#include <iostream>
#include <ModuleLoader.hpp>
#include <Greeter.hpp>

int main()
{
    //Load Module A
    ModuleLoader mla = "./lib/ConsoleGreeterModuleA";
    Greeter* greeterA = mla.getInstanceOf<Greeter*>();
    //Send message:
    greeterA->greet("Hello World!");

    //Load Module B
    ModuleLoader mlb = "./lib/ConsoleGreeterModuleB";
    Greeter* greeterB = mlb.getInstanceOf<Greeter*>();
    //Send message:
    greeterB->greet("Hello World!");

    //Borrado
    delete greeterA;
    delete greeterB;

    return EXIT_SUCCESS;
}
