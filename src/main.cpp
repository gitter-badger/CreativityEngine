/*
 * Creativity Engine.
 * Copyright (C) 2017 Sean McElholm. All Rights Reserved.
 */

// Standard Headers
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <exception>
#include <signal.h>

// 3rd Party Headers
#include <SDL2/SDL.h>

// Project Headers
#include "main.h"
#include "engine.h"
#include "logging.h"
#include "global.h"

using namespace std;


// Credits to someone from Stack Overflow. (idk their name)
char* getCmdOption(char ** begin, char ** end, const std::string & option)
{
    char ** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return 0;
}

bool cmdOptionExists(char** begin, char** end, const std::string& option)
{
    return std::find(begin, end, option) != end;
}



int main(int argc, char**argv)
{
    try
    {
        #if DEBUG
        if(cmdOptionExists(argv, argv+argc, "--fake-crash")) // Fake a crash to test its error handling
        {
            ERROR_PRINT("Faking a crash");
            raise(SIGABRT);
            return -1;
        }
        #endif

        if(cmdOptionExists(argv, argv+argc, "-h") || cmdOptionExists(argv, argv+argc, "--help")) // Show available command line arguments
        {
            cout << "Syntax: " << argv[0] << " [Option]" << endl;
            cout << "   -h --help      Shows this help menu" << endl;
            cout << "   -v --verbose   Verbose mode" << endl;
            cout << "   -a --about     Engine Version" << endl;
            cout << "   -w --windowed  Windowed Mode" << endl;
            return 0;
        }

        if(cmdOptionExists(argv, argv+argc, "-a") || cmdOptionExists(argv, argv+argc, "--about")) // Show engine info, similar to uname
        {
            cout << ""ENGINE_NAME" Version "ENGINE_MAJOR"."ENGINE_MINOR"."ENGINE_BUILD": "__DATE__" "__TIME__"." << endl;
            return 0;
        }

        if(cmdOptionExists(argv, argv+argc, "-v") || cmdOptionExists(argv, argv+argc, "--verbose")) // Enable Verbose mode for Logging
        {
            gVerbose = true;
        }

        if(cmdOptionExists(argv, argv+argc, "-w") || cmdOptionExists(argv, argv+argc, "--windowed")) // Enable Verbose mode for Logging
        {
            gWindowed = true;
        }
        

        MAIN_PRINT(""ENGINE_NAME" (C) "ENGINE_YEARS" "ENGINE_DEVELOPER". All Rights Reserved. Hello World!");

        Engine engine;

        engine.Start();


        
        
    }
    catch (...)
    {
        ERROR_PRINT("[Main @ main.cpp] Unknown Exception caught, killing engine!");
        raise(SIGABRT);
        return -1;
    }
    return 0;
}