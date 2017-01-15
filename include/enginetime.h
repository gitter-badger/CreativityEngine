/*
 * Creativity Engine.
 * Copyright (C) 2017 Sean McElholm. All Rights Reserved.
 */

#ifndef ENGINE_TIME_H
#define ENGINE_TIME_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

class EngineTime
{
public:
    EngineTime();
    virtual ~EngineTime();
    const std::string currentDateTime();
};

#endif