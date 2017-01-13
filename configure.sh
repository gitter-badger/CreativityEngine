platform='unknown'
unamestr=`uname`
if [[ "$unamestr" == 'Linux' ]]; then
   sudo apt-get update
   sudo apt-get install --yes libsdl2-dev
elif [[ "$unamestr" == 'Darwin' ]]; then
   brew install sdl2
fi


mkdir bin