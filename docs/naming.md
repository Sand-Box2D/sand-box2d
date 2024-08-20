# Sand-Box2D Naming Conventions
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

Classnames / enum / struct:
```cpp
#pragma once  // Generally recommended to leave at all the header files
              // (instead of #define #ifdef ... #endif).

class GameManager {};
```

Abstract classnames / interfaces:
```cpp
class BasePhysian {};
// Or
class IPhysian {};

// ...

class PhysianBox : public BasePhysian {};
// Or
class PhysianBox : public IPhysian {};
```

Structs/enums that take part of a module:
```cpp
struct PhysianConfig {};
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

Global const / preprocessor / enum value:
```cpp
#ifdef BUILD_VITA
```

Variable (inside a function or a little scope) or struct member:
```cpp
texture_width;
```

Pointer (inside a function or a little scope) or struct member:
```cpp
*p_texture_data;
```
