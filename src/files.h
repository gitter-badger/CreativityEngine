#ifndef FILES_H
#define FILES_H

// C++ Headers
#include <iostream>

// 3rd Party
#include <SDL2/SDL_filesystem.h>

class Files
{
public:
    Files();
    virtual ~Files();
    void initializeEnginePrefs();
    bool isWritingEnabled();
    char* getEnginePreferences();
private:
    char* preferencePath;
    bool noPreference;
};

#endif