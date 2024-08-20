# Sand-Box2D on PS Vita
This document describes the way Sand-Box2D function on PS Vita.

How do you install dependencies and compile and etc.

## Dependencies
First, let's review list of dependencies that are required for Sand-Box2D to run on PS Vita.

1. **SDL2**. Library responsible for creating a window and a SDL2_renderer inside it.
2. **Dear ImGui**. Library providing an easy access to draw some windows inside the game.
It's an internal lib, meaning that its code is cloned locally and compiled alongside the game.

Note that game is compiled with the Vita SDK tools.

## Prerequisites
Let's prepare our dev environment by installing all the tools we need.

1. Install [Vita SDK](https://vitasdk.org/).
You need to have a UNIX-like environment for it to work. It works on Linux, Windows and macOS.
Everything you need to know is already well explained at the Vita SDK main page.

By the way, if you are using a machine with an ARM-based CPU (such as Apple Silicon Macs),
you can use the [ARM fork of VDPM](https://github.com/hammerill/vdpm) in cooperation with
the clear UNIX-like environment provider such as [Lima](https://github.com/lima-vm/lima)
in order to compile with the Vita SDK natively.

## Compile
With all the needed tools installed, we can compile the game.

1. Clone this Git repo, move into it and download submodules:
```bash
git clone https://github.com/sand-box2d/sand-box2d
cd sand-box2d
git submodule update --init --depth=1
```

2. Compile the game (Vita SDK sometime uses deprecated CMake, we suppress that):
```bash
mkdir build
cd build
cmake .. -DBUILD_WINDOWS=OFF -DBUILD_VITA=ON -Wno-deprecated
make -j4
```

3. Normally, you should have a new .vpk file named `Sand-Box2D.vpk`
you can send and install on your hacked PS Vita.
