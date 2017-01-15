/*
 * Creativity Engine.
 * Copyright (C) 2017 Sean McElholm. All Rights Reserved.
 */

#ifndef LOGGING_H
#define LOGGING_H

using namespace std;

#define FATAL_PRINT(a, ...) SYS_FATAL_PRINT(__FILE__, __LINE__, a, #__VA_ARGS__)

int MAIN_PRINT(const char* mText, ...);
int SYS_FATAL_PRINT(char* file, int line, const char* mText, ...);
int ERROR_PRINT(const char* mText, ...);

#endif