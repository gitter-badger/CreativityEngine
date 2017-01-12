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

int MAIN_PRINT(string mText)
{
    if(gVerbose == 1)
    {
        cout << mText << endl;

        ofstream engineLog;
        engineLog.open ("engine.log");
        engineLog << mText << endl;
        engineLog.close();
    }
    return 0;
}

int ERROR_PRINT(const string mText)
{
    cout << mText << endl;

    ofstream engineLog;
    engineLog.open ("error.log");
    engineLog << mText << endl;
    engineLog.close();
    return 0;
}