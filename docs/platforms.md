# Sand-Box2D Platforms
This document describes all the platform-specific modules of the game
so you know what to expect and what to modify on each platform.

## List of Platforms
First, we should define the list of the platforms that Sand-Box2D supports.

It might be extended later.

### PS Vita
* Build option: `BUILD_VITA`.
* Build doc: [`vita.md`](./build/vita.md).
* Settings file: `vita.json`.

This project is "Vita-first" as in origin,
it's been developing as a game for PS Vita only with additional PC build for dev.

Nowadays, PC build is officially supported and default build is for [Windows](#windows).

As this game is "Vita-first", UI should be tested on PS Vita resolution first.
Then there are tests for adapting to other resolutions.

If there's a new function (like Python scripting), it should be able to compile and run on PS Vita.
If it can't, make all the effort possible to make it work on PS Vita or abandon it.

Build is performed with VitaSDK.
Read more [here](./build/vita.md).

### Windows
* Build option: `BUILD_WINDOWS`.
* Build doc: [`windows.md`](./build/windows.md).
* Settings file: `windows.json`.

The default build option.

Build is performed with MSYS2 UCRT64 tools.
Read more [here](./build/windows.md).

### Linux
* Build option: `BUILD_LINUX`.
* Build doc: [`linux.md`](./build/linux.md).
* Settings file: `linux.json`.

Build is performed with the G++ compiler and any package manager.
Read more [here](./build/linux.md).

### macOS
* Build option: `BUILD_MACOS`.
* Build doc: [`macos.md`](./build/macos.md).
* Settings file: `macos.json`.

Build is performed with the G++ compiler and Homebrew.
Read more [here](./build/macos.md).
