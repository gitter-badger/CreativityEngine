#include "files.h"
#include "global.h"

using namespace std;

char* preferencePath;
bool writingEnabled = true;

Files::Files()
{
}

Files::~Files()
{
    free(preferencePath);
}

void Files::initializeEnginePrefs() 
{
    
    char* base_path = SDL_GetPrefPath(ENGINE_DEVELOPER, ENGINE_NAME);
    if (strlen(base_path) > 0) 
    {
        preferencePath = base_path;
    } 
    else 
    {
        writingEnabled = false;
    }
}

bool Files::isWritingEnabled()
{
    return writingEnabled;
}

char* Files::getEnginePreferences()
{
    return preferencePath;
}