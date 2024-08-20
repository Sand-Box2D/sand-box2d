# Sand-Box2D Commenting Conventions
1. Each **header file** has to have a brief line at the very top explaining what is it
and what is the principal class or something other it declares. E.g.:
```cpp
/// @brief Platform-specific module of the Renderer. See class `Renderer`.
```
2. Each **class declaration** in header should also have a detailed description.
It should describe the following:
  * What is this class and what kind of problem it resolves.
  * What happens when you **create** an object of this file.
  * If you need to do something other and/or specific to make this object **usable**.
  If yes, explain what to do and under which condition
  (for example, call `init()` when renderer is ready).
  * If an object of this class should be created **in the heap** (as a pointer).
  If so, why.
3. Each method of the class should have
a **full Doxygen-like description** in the header file
(brief, optional full, describe all the arguments and return value).
4. Each member of the class (even private)
is required to have a **brief description** in the header file.
If needed, also include the full one.
The same applies to declarations of structs, enums, etc...
But empty (de-)constructors could be an exception.
5. Avoid writing code requiring **inline comments**.
If possible, name your variables in a very descriptive way
(for example, `physian_to_render` instead of `i`).
