# Sand-Box2D Comment Conventions
1. Each **header** file should have a **detailed description**
about what it is and what it can do.
2. If header file can have **multiple** C++ implementations on different platforms
(which is the case for controls and some low-level functions),
each source file realizing this header should also have a detailed description
about how it **differs from other implementations**.
3. Each **class declaration** in header should also have a detailed description.
It should describe the following:
  * What happens when you **create** an object of this file.
  * If you need to do something other and/or specific to make this object **usable**.
  If yes, explain what to do and under which condition
  (for example, call `init()` when renderer is ready).
  * If an object of this class should be created **in the heap** (as a pointer).
  If so, why.
4. Each method of the class should have
a **full Doxygen-like description** in the header file
(brief, optional full, describe all the arguments and return value).
5. Each member of the class (even private)
is required to have a **brief description** in the header file.
If needed, also include the full one.
The same applies to declarations of structs, enums, etc...
But empty (de-)constructors could be an exception.
6. Avoid writing code requiring **inline comments**.
If possible, name your variables in a very descriptive way
(for example, `physian_to_render` instead of `i`).
