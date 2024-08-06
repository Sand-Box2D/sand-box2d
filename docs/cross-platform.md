# Cross-Platform Sand-Box2D
Sand-Box2D is a cross-platform project. It aims to be as portable as possible.
I'll explain how to keep up with the dev environment
so it's simple to handle all of the platforms.

1. If some action should be performed with a native function on a platform
(like create a directory on PS Vita),
think about moving this piece of code to a **platform-specific module**.
2. Platform-specific module should have **its own directory**
inside `/src/platform` (we'll use `module`).
3. This directory should contain the **base header file** (we'll use `module.hpp`).
It should declare the basic functions we would expect from each platform
(like create directories, init renderer,
get state of the "button" that moves camera up).
It should be an **abstract class**.
Refer to conventions above for more details how to declare these properly.
4. When header file is declared, create a **new directory** in the module folder.
We generally expect it to be named `platform`
where platform describes where this directory should be compiled
(for example, `std` for modern C++ and `vita` for PS Vita specifically).
5. Create a **header** and a **source file** inside that dir
which includes the base header file,
creates a **concrete class** out of abstract one in the base header
and realizes it (we'll use `module-platform.hpp` and `module-platform.cpp`).
6. As of [comment convention](./comments.md) p.2,
please describe **difference** between other implementations.
7. Add other header/source files inside that dir if needed.
8. When finished, ensure you have implementations working on **all the platforms**.
9. Open [`CMakeLists.txt`](/CMakeLists.txt) file
and link the **base header file for all the platforms**
while linking the **implementation folder manually for each platform**.
10. Please specify the **list of platforms** this implementation is intended for
(like "all the PC builds" for Windows, Linux and macOS)
at the end of the description.
11. This information itself should be enough to be **self-explainable**.
It could go as the documentation for all the different platforms.
12. Then, in order to use the implementation, you should know where it's used.
For example, **Controls** object is created within **GameManager**.
We need to mark **GameManager** as a **"platform-aware"** module.
Please add such detail to the **header description** of the GameManager.
Also add this info to the **base header** of our platform-specific module
to keep track of everything.
13. It means that in the moment where GameManager creates an object of Controls,
We should write a little preprocessor branch where it decides which implementation
of Controls to create. Take a look at this piece of code:
```cpp
// game-manager.hpp

// First, ensure it's clearly stated that GameManager is a platform-aware class.

#ifdef BUILD_VITA
#include "../platform/controls/vita/controls-vita.hpp"

#else
#include "../platform/controls/sdl2/controls-sdl2.hpp"

#endif

// ...

std::unique_ptr<BaseControls> GameManager::controls; // In the GM class declaration.

// ...

// game-manager.cpp
// GameManager init function ...

#ifdef BUILD_VITA
    GameManager::controls = std::make_unique<ControlsVita>();
#else
    GameManager::controls = std::make_unique<ControlsSdl2>();
#endif

// GameManager init function goes on ...
```
