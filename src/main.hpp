/// @brief The main header that includes the game manager
/// and defines platform-agnostic settings paths.
///
/// "IWYU pragma: export" means that this include won't be used directly
/// and IDE has to stop giving warnings about it.

#pragma once

#include "game-manager.hpp" // IWYU pragma: export

#if defined(BUILD_WINDOWS)
    #define PATH_TO_SETTINGS "./settings.json"
    #define PATH_TO_DEF_SETTINGS "./assets/default-settings/windows.json"
#elif defined(BUILD_LINUX)
    #define PATH_TO_SETTINGS "./settings.json"
    #define PATH_TO_DEF_SETTINGS "./assets/default-settings/linux.json"
#elif defined(BUILD_MACOS)
    #define PATH_TO_SETTINGS "./settings.json"
    #define PATH_TO_DEF_SETTINGS "./assets/default-settings/macos.json"
#elif defined(BUILD_VITA)
    #define PATH_TO_SETTINGS "ux0:data/Sand-Box2D/settings.json"
    #define PATH_TO_DEF_SETTINGS "./assets/default-settings/vita.json"
#endif
