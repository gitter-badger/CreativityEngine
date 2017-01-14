#!/bin/bash
echo "Running macOS Dependency Script"
brew update
brew install sdl2
curl -O -L https://www.libsdl.org/release/SDL2-2.0.5.dmg
hdiutil attach SDL2-2.0.5.dmg
sudo cp -a /Volumes/SDL2/SDL2.framework /Library/Frameworks/