# Cross-Platform Sand-Box2D
Sand-Box2D is a cross-platform project. It aims to be as portable as possible.
I'll explain how to keep up with the dev environment
so it's simple to handle all of the platforms.

1. If some action should be performed with a native function on a platform
(like create a directory on PS Vita),
think about moving this piece of code to a **platform-specific module**.
2. Platform-specific module should have **its own directory**
inside `/src/platform` (we'll use `module`, thus `/src/platform/module`).
3. This directory should contain the **base header file** (we'll use `module.hpp`).
It should declare the basic functions we would expect from each platform
(like create directories, init renderer,
get state of the "button" that moves camera up).
Refer to naming and comment conventions to know how to declare these properly
([here](./naming.md) and [here](./comments.md)).
4. When header file is declared, create a **new directory** in the module folder.
We generally expect it to be named `platform`
where platform describes where this directory should be compiled
(for example, "std" for modern C++ and "vita" for PS Vita specifically).
5. Create a **source file** inside that dir which includes the base header file
and realizes it (we'll use `module-platform.cpp`).
6. As of [comment convention](./comments.md) p.2,
please describe **difference** between other implementations.
7. Add other header/source files inside that dir if needed.
8. When finished, ensure you have implementations working on **all the platforms**.
9. Open [`CMakeLists.txt`](/CMakeLists.txt) file
and link the **implementation folder manually for each platform**.
10. Please specify the **list of platforms** this implementation is intended for
(like "all the PC builds" for Windows, Linux and macOS)
at the end of the description.
11. This information itself should be enough to be **self-explainable**.
It could go as the documentation for all the different platforms.
