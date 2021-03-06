/*
 * Creativity Engine.
 * Copyright (C) 2017 Sean McElholm. All Rights Reserved.
 */

#include "logging.h"

int MAIN_PRINT(const char* mText, ...)
{
    if(gVerbose == 1) // Only print text to console when verbose mode is enabled.
    {
        EngineTime eTime;
        cout << mText << endl;

        ofstream engineLog;
        engineLog.open ("engine.log", ios::app);
        engineLog << "[" << eTime.currentDateTime() << "] " << mText << endl;
        engineLog.close();
    }
    return 0;
}

int SYS_FATAL_PRINT(char* file, int line, const char* mText, ...)
{
    EngineTime eTime;
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fatal Error", mText, NULL);
    cerr << "[FATAL ERROR] " << mText << endl;
    cerr << "Error caught at '" << file << "' at line " << line << endl;

    ofstream engineLog;
    engineLog.open ("fatal.log", ios::app);
    engineLog << "[" << eTime.currentDateTime() << "] " << mText << endl;
    engineLog.close();
    return -1;
}

int ERROR_PRINT(const char* mText, ...)
{
    EngineTime eTime;
    cerr << mText << endl;

    ofstream engineLog;
    engineLog.open ("error.log", ios::app);
    engineLog << "[" << eTime.currentDateTime() << "] " << mText << endl;
    engineLog.close();
    return 0;
}