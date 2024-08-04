# How to Build Sand-Box2D
This folder contains build instructions for each platform.

Here's the list of them:
* [PS Vita](./vita.md).
* [Windows](./windows.md).
* [Linux](./linux.md).
* [macOS](./macos.md).

## Detailed List of Platforms
This list contains more info regarding each platform to navigate quickly.

### PS Vita
* Build option: `BUILD_VITA`.
* Build doc: [`vita.md`](./vita.md).
* Settings file: `vita.json`.

This project is "Vita-first" because originally
it's been developing as a game for PS Vita only with additional PC build for dev.

Nowadays, PC build is officially supported and default build is for [Windows](#windows).

As this game is still "Vita-first", UI should be tested on PS Vita resolution first.
Then there should be tests for adapting to other resolutions.

If there's a new function (like Python scripting),
it should be able to compile and run on PS Vita.
If it can't, make all the effort possible to make it work on PS Vita or abandon it.

Build is performed with VitaSDK.
Read more [here](./vita.md).

### Windows
* Build option: `BUILD_WINDOWS`.
* Build doc: [`windows.md`](./windows.md).
* Settings file: `windows.json`.

The default build option in CMake.

Build is performed with MSYS2 UCRT64 tools.
Read more [here](./windows.md).

### Linux
* Build option: `BUILD_LINUX`.
* Build doc: [`linux.md`](./linux.md).
* Settings file: `linux.json`.

Build is performed with the G++ compiler and any package manager.
Read more [here](./linux.md).

### macOS
* Build option: `BUILD_MACOS`.
* Build doc: [`macos.md`](./macos.md).
* Settings file: `macos.json`.

Build is performed with the Apple's Clang and Homebrew.
Read more [here](./macos.md).
