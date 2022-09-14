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
    ModuleLoader ml;
    ml.load("./lib/consoleGreeter");
    Greeter* consoleGreeter = ml.getInstanceOf<Greeter*>();

    //Ejecucion
    consoleGreeter->greet("Hello World!");

    //Borrado
    delete consoleGreeter;

    return EXIT_SUCCESS;
}
