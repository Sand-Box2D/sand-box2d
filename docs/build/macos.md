# Sand-Box2D on macOS
This document describes the way Sand-Box2D function on macOS machines.

How do you install dependencies and compile and etc.

## Dependencies
First, let's review list of dependencies that are required for Sand-Box2D to run on macOS.

1. **SDL2**. Library responsible for creating a window and a SDL2_renderer inside it.
2. **Dear ImGui**. Library providing an easy access to draw some windows inside the game.
It's an internal lib, meaning that its code is cloned locally and compiled alongside the game.

## Prerequisites
Let's prepare our dev environment by installing all the tools we need.

1. Ensure you have [Brew](https://brew.sh) installed as well as
Apple's dev tools (Clang compiler and Git).
2. Install dependencies and CMake with Brew:
```bash
brew install sdl2 cmake
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
cmake .. -DBUILD_WINDOWS=OFF -DBUILD_MACOS=ON
make -j4
```

3. Normally, you should have a new `Sand-Box2D` executable you can run with:
```bash
./Sand-Box2D
```
