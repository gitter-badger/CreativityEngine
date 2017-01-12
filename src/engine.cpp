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


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool gVerbose = false;
bool gWindowed = false;

//Keep track of the current frame
int frame = 0;

//Whether or not to cap the frame rate
bool cap = true;

using namespace std;

bool borderlessWindowed = false;

void Engine::onRender()
{
    //Get window surface
    screenSurface = SDL_GetWindowSurface( window );

    //Fill the surface white
    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

    //Update the surface
    SDL_UpdateWindowSurface( window );
}

int Engine::Start()
{
    try
    {
        //Initialize SDL
        if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        {
            string errorString = "[Engine] SDL could not initialize! SDL_Error: ";
            errorString += SDL_GetError();
            ERROR_PRINT(errorString);
            return -1;
        }
        else
        {
            MAIN_PRINT("[Engine] Create Window");

            //Create window
            SDL_Rect rect;
            if (SDL_GetDisplayBounds(0, &rect) != 0) 
            {
                SDL_Log("SDL_GetDisplayBounds failed: %s", SDL_GetError());
                Engine::window = SDL_CreateWindow( ENGINE_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
            }
            else
            {
                Engine::window = SDL_CreateWindow( ENGINE_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, rect.w, rect.h, SDL_WINDOW_SHOWN );
            }

            
            if( Engine::window == NULL )
            {
                string errorString = "[Engine @ engine.cpp] Window could not be created! SDL_Error: ";
                errorString += SDL_GetError();
                ERROR_PRINT(errorString);
            }
            else
            {

                if(gWindowed == false)
                {
                    if(borderlessWindowed == true)
                    {
                        SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN_DESKTOP);
                    }
                    else
                    {
                        
                        SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN);
                    }
                }
                //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

                MAIN_PRINT("[Engine] First onRender");
                Engine::onRender();

                SDL_Event event;
                bool gameRunning = true;
                while (gameRunning)
                {
                    Engine::onRender();
                    if (SDL_PollEvent(&event))
                    {
                        switch(event.type)
                        {
                            case SDL_QUIT:
                            {
                                MAIN_PRINT("[Engine] Preparing to kill the game engine process");
                                gameRunning = false;
                            }
                            case SDL_KEYDOWN:
                            {
                                MAIN_PRINT("[Engine] OnKeyDown");
                            }
                            case SDL_KEYUP:
                            {
                                MAIN_PRINT("[Engine] OnKeyUp");
                            }
                        }
                        
                    }
                }

            }

            MAIN_PRINT("[Engine] Exiting gracefully via SDL_Quit()! Goodbye World!");
            SDL_Quit();
        }
    }
    catch (...)
    {
        ERROR_PRINT("[Engine @ main.cpp] Unknown Exception caught, killing engine!");
        raise(SIGABRT);
        return -1;
    }
    return 0;
}