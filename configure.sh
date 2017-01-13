platform='unknown'
unamestr=`uname`
if [[ "$unamestr" == 'Linux' ]]; then
    sudo apt-get update
    sudo apt-get upgrade
    sudo apt-get install --yes build-essential
    sudo apt-get install --yes freeglut3-dev 
    sudo apt-get install --yes libsdl2-dev
elif [[ "$unamestr" == 'Darwin' ]]; then
    brew update
    brew install sdl2
fi

mkdir -p bin