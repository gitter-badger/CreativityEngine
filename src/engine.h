/*
 * Creativity Engine.
 * Copyright (C) 2017 Sean McElholm. All Rights Reserved.
 */

#ifndef ENGINE_H
#define ENGINE_H

using namespace std;

class Engine {
public:

    // onRender
    void onRender();
    int Start();
    // Main Window
    SDL_Window* window = NULL;

    // The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    // Surface Renderer
    SDL_Renderer* renderer = nullptr;

};

#endif