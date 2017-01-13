/*
 * Creativity Engine.
 * Copyright (C) 2017 Sean McElholm. All Rights Reserved.
 */

#ifndef ENGINE_H
#define ENGINE_H

// Include GLFW
#include <SDL2/SDL.h>

#include <SDL2/SDL_opengl.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

using namespace std;

class Engine {
public:

    // onRender
    void onRender();
    int Start();

    // GL Context
    SDL_GLContext gContext;

    // Main Window
    SDL_Window* window = NULL;

    // The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    // Surface Renderer
    SDL_Renderer* renderer = nullptr;

};

#endif