/*
 * Creativity Engine.
 * Copyright (C) 2017 Sean McElholm. All Rights Reserved.
 */
#include <SDL2/SDL.h>
#include <iostream>
#include <cstdio>
#include <algorithm>

#include "main.h"
#include "logging.h"
#include "global.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
bool gVerbose = false;

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
    if(cmdOptionExists(argv, argv+argc, "-h") || cmdOptionExists(argv, argv+argc, "--help")) // Enable Verbose mode for Logging
    {
        cout << "Syntax: " << argv[0] << " [Option]" << endl;
        cout << "Verbose Output: -v --verbose" << endl;
        return 0;
    }

    if(cmdOptionExists(argv, argv+argc, "-v") || cmdOptionExists(argv, argv+argc, "--verbose")) // Enable Verbose mode for Logging
    {
        gVerbose = true;
    }

    MAIN_PRINT(""ENGINE_NAME" (C) "ENGINE_YEARS" "ENGINE_DEVELOPER". All Rights Reserved. Hello World!");
    SDL_Window* window = NULL;
    
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        string errorString = "[Engine @ main.cpp] SDL could not initialize! SDL_Error: ";
        errorString += SDL_GetError();
        ERROR_PRINT(errorString);
    }
    else
    {
        MAIN_PRINT("[Engine] Create Window");
        //Create window
        window = SDL_CreateWindow( "Creativity Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            string errorString = "[Engine @ main.cpp] Window could not be created! SDL_Error: ";
            errorString += SDL_GetError();
            ERROR_PRINT(errorString);
        }
        else
        {
            MAIN_PRINT("[Engine] Get window surface");
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            MAIN_PRINT("[Engine] Fill the surface white");
            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
            MAIN_PRINT("[Engine] Update the surface");
            //Update the surface
            SDL_UpdateWindowSurface( window );

            SDL_Event event;
            bool gameRunning = true;
            while (gameRunning)
            {
                if (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                    {
                        MAIN_PRINT("[Engine] Preparing to kill the game engine process");
                        gameRunning = false;
                    }
                }
            }

        }

        MAIN_PRINT("[Engine] Exiting gracefully via SDL_Quit()! Goodbye World!");
        SDL_Quit();
    }	
    return 0;
}