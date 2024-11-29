# Sand-Box2D on Linux
This document describes the way Sand-Box2D function on Linux distributions.

How do you install dependencies and compile and etc.

## Dependencies
First, let's review list of dependencies that are required for Sand-Box2D to run on Linux.

- **SDL2**. Library responsible for creating a window and a SDL2_renderer inside it.
- **JsonCpp**. Library letting C++ to understand JSON. It's used to store settings and levels.
- **Dear ImGui** ([`ocornut/imgui`](https://github.com/ocornut/imgui)).
Library providing an easy access to draw some windows inside the game.
It's an internal lib, meaning that its code is cloned locally and compiled alongside the game.

Also note that game is compiled with the GNU Compiler Collection.

## Prerequisites
Let's prepare our dev environment by installing all the tools we need.

1. Install Git, GCC, Make, CMake and dependencies with your package manager
(adapt your command, these are some test commands or their parts that could be useful):
```bash
# Debian-ish...
sudo apt install git gcc make cmake libsdl2-dev libjsoncpp-dev

# Fedor-ish...
sudo dnf install git gcc make cmake SDL2-devel jsoncpp-devel

# Arch-ish...
sudo pacman -S git gcc make cmake sdl2 jsoncpp
```

## Compile
With all the needed tools installed, we can compile the game.

1. Clone this Git repo, move into it and download submodules:
```bash
git clone https://github.com/sand-box2d/sand-box2d
cd sand-box2d
git submodule update --init --depth=1
```

2. Compile the game:
```bash
mkdir build
cd build
cmake .. -DBUILD_LINUX=ON
make -j4
```

3. Normally, you should have a new `Sand-Box2D` executable you can run with:
```bash
./Sand-Box2D
```
