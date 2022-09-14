/**
* Copyright (c) 2016 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of CPPSET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#ifndef SHARED_LIBRARY_LOADER_HPP
#define SHARED_LIBRARY_LOADER_HPP

#ifdef __unix__
    #define RTLD_LAZY   1
    #define RTLD_NOW    2
    #define RTLD_GLOBAL 4
    #include <vendors/dlopen/dlfcn.h>
#elif __APPLE__
    #include <vendors/dlopen/dlfcnMac.h>
#elif defined(_WIN32) || defined(WIN32)
    #include <windows.h>
#endif // defined

#include <string>
#include <iostream>

// #include <memory>
// #include <typeinfo>

using namespace std;

class SharedLibraryLoader
{
    private:
        void* library;
        void* symbol;
        bool isFree;
        bool isLoaded;

        void showError(string message, string message2 = "")
        {
            cerr << message << ' ' << message2 << endl;
            exit(EXIT_FAILURE);
        }

    public:
        SharedLibraryLoader()
        {
            cout << "create SharedLibraryLoader..." << endl;
            library = nullptr;
            symbol = nullptr;
            isLoaded = false;
            isFree = false;
        }

        SharedLibraryLoader(string filePath)
        {
            isLoaded = false;
            isFree = false;
            cout << "create SharedLibraryLoader..." << endl;
            cout << "Load library:" << endl;
            loadLibrary(filePath);
            symbol = nullptr;
        }

        virtual ~SharedLibraryLoader()
        {
            cout << "Free library into destructor:" << endl;
            freeLibrary();
            cout << "delete SharedLibraryLoader..." << endl;
        }

        void* loadLibrary(string filePath)
        {
            #ifdef __unix__
                filePath += ".so";
                library = dlopen(filePath.c_str(), RTLD_NOW);
            #elif __APPLE__
                filePath += ".dylib";
                library = dlopen(filePath.c_str(), RTLD_LOCAL|RTLD_LAZY);
            #elif defined(_WIN32) || defined(WIN32)
                filePath += ".dll";
                library = (void*) LoadLibrary(filePath.c_str());
            #endif // defined

            //LEER DOCUMENTACION DE MICROSOFT
            (library) ? isLoaded = true : isLoaded = false;
            if(!isLoaded) showError("Error: Library could not be loaded!");

            return library;
        }

        void* getExternSymbol(string name)
        {
            if(isLoaded)
            {
                #ifdef __unix__
                    symbol = dlsym(library, name.c_str());
                #elif __APPLE__
                    symbol = dlsym(library, name.c_str());
                #elif defined(_WIN32) || defined(WIN32)
                    symbol = (void*) GetProcAddress((HINSTANCE)library, name.c_str());
                #endif // defined        
                if(!symbol) showError("Error: Library symbol does not exist or cannot be obtained!");        
            }
            else
            {
                showError("Error: Library is not loaded, can't get symbol");
            }
            

            return symbol;
        }

        // template<typename ObjectType> ObjectType getObjectFromSymbol(string symbolName)

        template<typename ObjectType> ObjectType getFunctionFromSymbol(string symbolName)
        {
            //@toDo doctrine comment format and dinamic cast para comprobar tipo
            ObjectType obj;
            if(isLoaded)
            {
                typedef ObjectType ( *LibFactoryFunction ) ();
                LibFactoryFunction factory = (LibFactoryFunction)getExternSymbol(symbolName); // OK
                if( factory )
                {
                    obj = factory();
                }
                else
                {
                    showError("Incorrect Object Type!");
                }
            }
            return obj;        
        }

        /**
         * @brief Free the shared library handler. dlclose no return boolean value
         */
        bool freeLibrary()
        {
            cout << "1-Execute freeLibrary method..." << endl;
            cout << "2-Previous IsFree value: " << isFree << endl;
            cout << "3-Previous IsLoaded value: " << isLoaded << endl;
            if(isLoaded)
            {
                #ifdef __unix__
                    isLoaded = dlclose(library);
                    isLoaded ? isFree = false : isFree = true; 
                #elif __APPLE__
                    isLoaded = dlclose(library);
                    isLoaded ? isFree = false : isFree = true; 
                #elif defined(_WIN32) || defined(WIN32)
                    isFree = FreeLibrary((HINSTANCE)library);
                    isFree ? isLoaded = false : isLoaded = true; 
                #endif // defined
            }
            // else
            // {
            //     showError("Error releasing library not loaded!");
            // }
            
            cout << "4-Last IsFree value: " << isFree << endl;
            cout << "5-Last IsLoaded value: " << isLoaded << endl;
            return isFree;
        }
};

#endif // SHARED_LIBRARY_LOADER_HPP

