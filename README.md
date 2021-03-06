# Creativity Game Engine
[![Build Status](https://travis-ci.org/CreativityEngineTeam/CreativityEngine.svg?branch=master)](https://travis-ci.org/CreativityEngineTeam/CreativityEngine)
[![Build Status](https://scan.coverity.com/projects/11471/badge.svg)](https://scan.coverity.com/projects/creativityengineteam-creativityengine)

Creativity Engine is a Game Engine being developed from scratch using C++ and SDL2. The Goals are to create a game engine with 3D functionality, an editor, and mayble some actual games.

It only supports building to Desktop platforms for now via commandline (it's barebones), but maybe Android and iOS build support may be implemented.

I would also like to implement support for Consoles as well, but that is further on down the line.

This repository contains the main engine source code and uses only SDL2.

It currently works with MacOS, but it is written in pure C++ and SDL2, so it should in theory work on Linux and Windows as well.

## Development Team
Sean McElholm - Project Lead


## Build Instructions
Ensure that a build environment is installed such as Xcode, GNU Compilers or MS Visual Studio Compilers

1. Clone repository:
```
git clone https://github.com/CreativityEngineTeam/CreativityEngine.git
```
2. Install SDL2 is not already done already.
*Windows:* ????
*Ubuntu Linux & Variants*: `sudo apt-get install --yes libsdl2-dev`
*macOS:* `brew install sdl2`
3. `cd` to the repository:
```
cd CreativityEngine/
```
3. Create the `bin` directory:
```
mkdir bin
```
4. Compile using:
```
make
```

## History
Creativity Engine is a project that I am doing in my free time to learn C++ and add something to my CV.

This project was initially started on Thursday, January 12, 2017.

## Want to contribute? 
Fork, make a change and push it back to the main repository! :smile:

## Features
* [Features](https://github.com/seanny/CreativityEngine/blob/master/FEATURES.md)
* [Roadmap](https://github.com/seanny/CreativityEngine/blob/master/ROADMAP.md)

## About
* [License](https://github.com/seanny/CreativityEngine/blob/master/LICENSE)

## Screenshots

Engine Window
![Engine Window](https://github.com/seanny/CreativityEngine/blob/master/screenshots/app_window.png)

Engine Terminal Output
![Verbose Terminal Output](https://github.com/seanny/CreativityEngine/blob/master/screenshots/app_terminal.png)