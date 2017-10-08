# install script for ubuntu

# install g++-6
sudo apt-get update
sudo apt-get install build-essential software-properties-common -y
sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y
sudo apt-get update
sudo apt-get install gcc-snapshot -y
sudo apt-get update
sudo apt-get install gcc-6 g++-6 -y
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-6 60 --slave /usr/bin/g++ g++ /usr/bin/g++-6
sudo apt-get install gcc-4.8 g++-4.8 -y
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 60 --slave /usr/bin/g++ g++ /usr/bin/g++-4.8
# sudo update-alternatives --config gcc

# install required libraries and build Humanity.out
sudo apt-get install -y cmake libsdl2-dev libsdl2-{image,mixer,ttf}-dev
cmake .
make