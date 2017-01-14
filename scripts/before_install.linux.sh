#!/bin/bash
echo "Running Linux Dependency Script"
# For gcc-6
sudo apt-key adv --recv-keys --keyserver keyserver.ubuntu.com 1397BC53640DB551
sudo add-apt-repository --yes ppa:ubuntu-toolchain-r/test
sudo apt-get install -qq g++-6 libsdl2-dev freeglut3-dev
#if [ "$CXX" = "g++" ]; then sudo apt-get install -qq g++-4.8; fi
#if [ "$CXX" = "g++" ]; then export CXX="g++-4.8" CC="gcc-4.8"; fi