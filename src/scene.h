/*
 * Creativity Engine.
 * Copyright (C) 2017 Sean McElholm. All Rights Reserved.
 */

#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <vector>

// 3rd Party Headers
#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <GLUT/glut.h>
#else
    #include <GL/gl.h>
    #include <GL/glu.h>
    #include <GL/glut.h>
#endif

#include <SDL2/SDL.h>

#include <SDL2/SDL_opengl.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

using namespace std;

class Scene {
public:

    Scene();
    virtual ~Scene();
    void onSceneUpdate();
    void onQuitScene();
    int getMouseX();
    int getMouseY();

};

#endif