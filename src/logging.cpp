/*
 * Creativity Engine.
 * Copyright (C) 2017 Sean McElholm. All Rights Reserved.
 */
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>

#include "logging.h"
#include "global.h"

/*int test(const char* fmt,
             ...)
{
    SDL_Log(fmt);
}*/

int MAIN_PRINT(string mText)
{
    if(gVerbose == 1) // Only print text to console when verbose mode is enabled.
    {
        cout << mText << endl;

        ofstream engineLog;
        engineLog.open ("engine.log", ios::app);
        engineLog << mText << endl;
        engineLog.close();
    }
    return 0;
}

int ERROR_PRINT(const string mText)
{
    cerr << mText << endl;

    ofstream engineLog;
    engineLog.open ("error.log", ios::app);
    engineLog << mText << endl;
    engineLog.close();
    return 0;
}