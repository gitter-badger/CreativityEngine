platform='unknown'
unamestr=`uname`
if [[ "$unamestr" == 'Linux' ]]; then
    export DEBIAN_FRONTEND=noninteractive
    sudo apt-get update
    # sudo apt-get -q -y upgrade
    sudo apt-get -q -y install g++
    sudo apt-get -q -y install build-essential
    sudo apt-get -q -y install freeglut3-dev 
    sudo apt-get -q -y install libsdl2-dev
elif [[ "$unamestr" == 'Darwin' ]]; then
    brew update
    brew install sdl2
fi

mkdir -p bin