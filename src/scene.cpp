#include "scene.h"
#include "global.h"
#include "logging.h"
#include "engine.h"

bool isSceneGameQuit = false;

Scene::Scene()
{

}

Scene::~Scene()
{
    
}

void Scene::onSceneUpdate()
{
    
}

void Scene::onQuitScene()
{
    if(isSceneGameQuit == true)
    {
        MAIN_PRINT("[Engine] Preparing to kill the game engine via Scene::onQuitScene");
        gGameRunning = false;
        return;
    }
}

int Scene::getMouseX()
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    return mouseX;
}

int Scene::getMouseY()
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    return mouseY;
}