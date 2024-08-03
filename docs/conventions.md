# Sand-Box2D Conventions
In order to simplify the dev's life when one has to create and name something
and in order to effectively use the fact that we're refactoring the full project,
these strong rules were defined. Please refer to them when contributing.

## Naming Conventions
Filenames/pathnames:
```
./
physians/
  physian.hpp
  physian.cpp
  physian-box.hpp
  physian-box.cpp

...

./
game-manager.hpp
game-manager.cpp
```

Classnames:
```cpp
#pragma once  // Generally recommended to leave at all the header files
              // (instead of #define #ifdef ... #endif).

class GameManager;
```

Abstract classnames:
```cpp
class BasePhysian;

// ...

class PhysianBox : public BasePhysian;
```

Method *(public members first!)*:
```cpp
renderAll();
```

Private method:
```cpp
m_findPhysianId();
```

Private member:
```cpp
m_CurrentLevel;
```

Private pointer:
```cpp
Window *mp_CurrentWindow;
```

Argument:
```cpp
boxWidth;
```

Referenced argument:
```cpp
r_nodeToModify;
```

Global const / preprocessor:
```cpp
#ifdef BUILD_VITA
```

Variable (inside a function or a little scope):
```cpp
texture_width;
```

Pointer (inside a function or a little scope):
```cpp
*p_texture_data;
```

## Comment Conventions
1. Each **header** file should have a **detailed description**
about what it is and what it can do.
2. If header file can have **multiple** C++ implementations on different platforms
(which is the case for graphics renderer and controls),
each source file realizing this header should also have a detailed description
about how it **differs from other implementations**.
3. Each **class declaration** in header should also have a detailed description.
It should describe the following:
  * If an object of this class should be created as a **pointer**. If so, why.
  * What happens when you **create** an object of this file.
  * If you need to do something other and/or specific to make this object **usable**.
  If yes, explain what to do and under which condition
  (for example, call `init()` when renderer is ready).
4. Each method of the class should have
a **full Doxygen-like description** in the header file
(brief, optional full, describe all the arguments and return value).
5. Each member of the class (even private)
is required to have a **brief description** in the header file.
If needed, also include the full one.
6. Avoid writing code requiring **inline comments**.
If possible, name your variables in a very descriptive way
(for example, `physian_to_render` instead of `i`).

## Cross-Platform
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
Refer to conventions above for more details how to declare these properly.
4. When header file is declared, create a **new directory** in the module folder.
We generally expect it to be named `module-platform`
where platform describes where this directory should be compiled
(for example, `std` for modern C++ and `vita` for PS Vita specifically).
5. Create a **source file** inside that dir which includes the base header file
and realizes it (we'll use `module.cpp`).
6. As of [comment convention](#comment-conventions) p.2,
please describe **difference** between other implementations.
7. Add other header/source files inside that dir if needed.
8. When finished, ensure you have implementations working on **all the platforms**.
9. Open [`CMakeLists.txt`](/CMakeLists.txt) file
and link the **base header file for all the platforms**
while linking the **implementation folder manually for each platform**.
10. Please specify the list of platforms this implementation is intended for
(like "all the PC builds" for Windows, Linux and macOS)
at the end of the description.
11. This information itself should be enough to be self-explainable.
It could go as the documentation for all the different platforms.
