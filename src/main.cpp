/*
 * Creativity Engine.
 * Copyright (C) 2017 Sean McElholm. All Rights Reserved.
 */
#include <SDL2/SDL.h>
#include <iostream>
#include <cstdio>

#include "main.h"
#include "logging.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

using namespace std;

int main(int argc, char**argv)
{
    ERROR_PRINT("Creativity Engine (C) 2017 Sean McElholm. All Rights Reserved.");
    SDL_Window* window = NULL;
    
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        string errorString = "SDL could not initialize! SDL_Error: ";
        errorString += SDL_GetError();
        ERROR_PRINT(errorString);
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "Creativity Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            string errorString = "Window could not be created! SDL_Error: ";
            errorString += SDL_GetError();
            ERROR_PRINT(errorString);
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
            //Update the surface
            SDL_UpdateWindowSurface( window );
        }
    }	
    return 0;
}