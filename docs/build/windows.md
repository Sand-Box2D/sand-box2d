# Sand-Box2D on Windows
This document describes the way Sand-Box2D function on Windows machines.

How do you install dependencies and compile and etc.

## Dependencies
First, let's review list of dependencies that are required for Sand-Box2D to run on Windows.

- **SDL2**. Library responsible for creating a window and a SDL2_renderer inside it.
- **JsonCpp**. Library letting C++ to understand JSON. It's used to store settings and levels.
- **Dear ImGui** ([`ocornut/imgui`](https://github.com/ocornut/imgui)).
Library providing an easy access to draw some windows inside the game.
It's an internal lib, meaning that its code is cloned locally and compiled alongside the game.

Also note that game is compiled with GCC installed via MSYS2.
Visual Studio C++ compiler was never tested.

## Prerequisites
Let's prepare our dev environment by installing all the tools we need.

1. Ensure you have [Git](https://www.git-scm.com/download/win) installed.
2. Download [MSYS2](https://www.msys2.org/) and launch it. Type in the appeared terminal:
```bash
# Install C++ compiler, CMake and external dependencies
yes "" | pacman -S mingw-w64-ucrt-x86_64-toolchain mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-SDL2 mingw-w64-ucrt-x86_64-jsoncpp

# Link mingw32-make to simply make
ln -s /ucrt64/bin/mingw32-make.exe /ucrt64/bin/make.exe

# Automatically close the terminal at the end
exit
```
Normally, terminal closes itself.

3. Add `C:\msys64\ucrt64\bin` to PATH environment variable.

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
cmake .. -DBUILD_WINDOWS=ON -G "MinGW Makefiles"
make -j4
```

3. Normally, you should have a new .exe file named `Sand-Box2D.exe` you can run with:
```bash
.\Sand-Box2D.exe
```
