# Cross-Platform Sand-Box2D
Sand-Box2D is a cross-platform project. It aims to be as portable as possible.
I'll explain how to keep up with the dev environment
so it's simple to handle all of the platforms.

## Two Levels
Let's review the basics of the "platform" system first.

"Platform" system of Sand-Box2D has two levels: **abstract** (commonly called basic header)
and **concrete** (commonly called implementation).

Abstract level is commonly a single header file which contains declaration
of the basic functionality of a module.
For example, we have a module Renderer which should init a window.
We ask it to do so. We don't know how it does that. Nor do we care.
But, picking the right implementation for the right platform, it finely does so.

Concrete level though has to take care of the implementation routine.
For example, Renderer can have SDL2 implementation. This impl. has to include the basic header
and SDL2 libs and define all the class methods from it.
It can have some private storage for the objects of this class and declare some methods
that are returning something whose type is not-yet-known at the abstract level.

## How to Create a Platform-Specific Module
1. If some action should be performed with a native function on a platform
(like create a directory on PS Vita),
think about moving this piece of code to a **platform-specific module**.
2. Platform-specific module should have **its own directory**
inside `/src/platform` (we'll use `module`, thus `/src/platform/module`).
3. This directory should contain the **base header file** (we'll use `module.hpp`).
It should declare the basic functions we would expect from each platform
(like create directories, init renderer,
get state of the "button" that moves camera up).
Refer to naming and commenting conventions to know how to declare these properly
([here](./naming.md) and [here](./commenting.md)).
4. When header file is declared, create a **new directory** in the module folder.
We generally expect it to be named `platform`
where platform describes where this directory should be compiled
(for example, "std" for modern C++ and "vita" for PS Vita specifically).
5. Create a **source file** inside that dir which includes the base header file
named as the module and realizes it (we'll use `module.cpp`).
6. As of [commenting convention](./commenting.md) p.2,
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

## Implementation Private Members
If your object has to contain some private members that are unique for this platform
and that you cannot modify the basic header (since header has to stay basic),
you can forward-declare a struct that contains them. I'll explain how to do so
with an example for SDL2 implementation for Renderer.

1. First, refer to [naming](./naming.md) and [commenting](./commenting.md)
conventions to know how to name your classes and comment your work.
2. Open the basic header. We'll use `src/platform/renderer/renderer.hpp`.
3. Declare a new struct named `ModuleSpecific` where "Module"
is the name of this basic module class (here it's `Renderer`, thus `RendererSpecific`):
```cpp
/// @brief Declaration of platform-specific Renderer data.
struct RendererSpecific;
```

4. Add a private pointer to the declaration of this module class
(you can choose between smart unique and shared pointers, or bare C ptr if you like)
(for info, you have to use a pointer since it's a forward-declared struct):
```cpp
private:
    /// @brief Pointer to platform-specific Renderer data.
    std::unique_ptr<RendererSpecific> mp_Specific;
```

5. Now, you have a little private storage that you can use however you want in your
implementation source file. Define contents of the new struct (SDL2 Renderer example):
```cpp
/// @brief SDL2 Renderer impl. specific data.
struct RendererSpecific
{
    /// @brief Window for the SDL2 Renderer impl.
    SDL_Window *p_window = nullptr;

    /// @brief Renderer for this SDL2 impl.
    SDL_Renderer *p_renderer = nullptr;
};
```

6. Take care of your data, each load should have an unload (if not using smart pointers,
which *might* be the simpler solution with other forward-declared types as for SDL2).
Load:
```cpp
Renderer::mp_Specific = std::make_shared<RendererSpecific>();

// ...

Renderer::mp_Specific->p_window = SDL_CreateWindow("Sand-Box2D", /* ... */);

// ...

Renderer::mp_Specific->p_renderer = SDL_CreateRenderer(
    Renderer::mp_Specific->p_window, /* ... */
);
```

Unload:
```cpp
SDL_DestroyRenderer(Renderer::mp_Specific->p_renderer);
SDL_DestroyWindow(Renderer::mp_Specific->p_window);
```

## Implementation Not-Yet-Known Type Functions
If your platform-specific class has to communicate with the other one,
you might need to export some member of it which has a not-yet-known type
in the basic header level. It will be only known at the implementation level.

That's the case for GLFW implementation for Renderer and Controls
(it does not exist yet but we expect to realize it in the future.
That's why our example below is very useless).
GLFW-based Controls implementation has to bind itself to a
GLFW window, which is contained inside the GLWF-based Renderer implementation.

In order to do so, you would pass the Renderer object inside a method of
the Controls class. In the implementation level, you would know it exports GLFW window.

Let's follow the example where we export the SDL2 renderer object (the only tested ftm):

1. Open the basic header of the class where you want to export something special.
We want to export a pointer to SDL_Renderer. We'll use `src/platform/renderer/renderer.hpp`.
2. Declare a new public method which returns a template type:
```cpp
/// @brief Get link to the renderer object specific to an implementation.
/// @tparam T Type of the pointer to the renderer object that could be different
/// on different Renderer platforms such as SDL2 or OpenGL.
/// @return Pointer to the specific renderer object.
template<typename T>
T getRenderer();
```
3. That's all for the abstract level. Go to the implementation source file.
We'll use `src/platform/renderer/sdl2/renderer.cpp`.
4. Define the function in your implementation:
```cpp
template<typename T>
T Renderer::getRenderer()
{
    return Renderer::mp_Specific->p_renderer;
}
template SDL_Renderer* Renderer::getRenderer();
```
5. As you could see, we also added a new line at the end which helps compiler
understand which type could be returned. In our case, it's only `SDL_Renderer*`,
thus a pointer to the SDL_Renderer object.
6. Now, you can use such a function inside another platform-specific module.
Please remember that we have to do so in two levels: abstract and concrete.
That means that there is a strong link between Controls and Renderer modules:
Controls module depends on Renderer, since it has to request its GLFW window
(in our example, SDL_Renderer is used though).
7. Open the basic header of the module that depends on another one.
We'll use `src/platform/controls/controls.hpp`.
8. Include the basic header of a module this module depends on:
```cpp
#include "../renderer/renderer.hpp"
```

9. Declare a method which accepts referenced Renderer module object:
```cpp
/// @brief Bind this Controls object with Renderer.
///
/// This could be implemented differently on different platforms or even unnecessary.
///
/// @param r_renderer Referenced Renderer to be bound with.
void bind(Renderer &r_renderer);
```

10. Using public methods of Renderer, you can get all the data you need in Controls.
Open the implementation source file (we'll use `src/platform/controls/sdl2/controls.cpp`)
and define the method (in our example, we just interact with SDL_Renderer from Controls):
```cpp
void Controls::bind(Renderer &r_renderer)
{
    auto renderer = r_renderer.getRenderer<SDL_Renderer*>();

    SDL_SetRenderDrawColor(
        renderer,
        0xFF,
        0,
        0,
        0xFF
    );
    SDL_RenderClear(renderer);
}
```

11. As you could see, we are **sure** the `getRenderer()` method can provide us
a `SDL_Renderer*`. That means that current implementation could only work with
SDL2 Renderer implementation of Renderer. That's the info you have to consider
putting in the implementation description:
```
NOTE: Please remember that current implementation only works with
the SDL2 Implementation of Renderer.
```
