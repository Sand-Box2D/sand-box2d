cmake_minimum_required(VERSION 3.5)

option(BUILD_WINDOWS "Build Windows .exe" ON)
option(BUILD_LINUX "Build Linux executable" OFF)
option(BUILD_MACOS "Build macOS executable" OFF)
option(BUILD_VITA "Build PS Vita .vpk" OFF)

set(GAME_NAME "sand-box2d")

set(IMGUI_FOLDER "src/lib/imgui")

file(GLOB SRC_MAIN "src/main*[.hpp|.cpp]")
file(GLOB SRC_MANAGER "src/game-manager*[.hpp|.cpp]")

file(GLOB_RECURSE SRC_SYSTEM "src/system/*[.hpp|.cpp]")
file(GLOB_RECURSE SRC_MODELS "src/models/*[.hpp|.cpp]")

if(BUILD_WINDOWS)
    message(STATUS "Building for Windows")
    add_definitions(-DBUILD_WINDOWS)

    project(${GAME_NAME})

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")    # Use C++ version 17
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")     # Hide terminal window

    file(GLOB SRC_PLATFORM_RENDERER_SDL2 "src/platform/renderer/sdl2/*[.hpp|.cpp]")
    file(GLOB SRC_PLATFORM_CONTROLS_SDL2 "src/platform/controls/sdl2/*[.hpp|.cpp]")

    file(GLOB SRC_IMGUI "${IMGUI_FOLDER}/im*[.h|.cpp]")
    file(GLOB SRC_IMGUI_SDL2 "${IMGUI_FOLDER}/backends/imgui_impl_sdl2*[.h|.cpp]")
    file(GLOB SRC_IMGUI_SDLRENDERER2 "${IMGUI_FOLDER}/backends/imgui_impl_sdlrenderer2*[.h|.cpp]")

    add_executable(${CMAKE_PROJECT_NAME}
        ${SRC_MAIN}
        ${SRC_MANAGER}

        ${SRC_SYSTEM}
        ${SRC_MODELS}

        ${SRC_PLATFORM_RENDERER_SDL2}
        ${SRC_PLATFORM_CONTROLS_SDL2}

        ${SRC_IMGUI}
        ${SRC_IMGUI_SDL2}
        ${SRC_IMGUI_SDLRENDERER2}
    )

    target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        "${IMGUI_FOLDER}"
    )

    find_library(SDL2_LIBS sdl2)

    target_link_libraries(${CMAKE_PROJECT_NAME}
        ${SDL2_LIBS}
    )

    file(COPY assets DESTINATION .)

elseif(BUILD_LINUX)
    message(STATUS "Building for Linux")
    add_definitions(-DBUILD_LINUX)

    project(${GAME_NAME})

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")    # Use C++ version 17

    file(GLOB SRC_PLATFORM_RENDERER_SDL2 "src/platform/renderer/sdl2/*[.hpp|.cpp]")
    file(GLOB SRC_PLATFORM_CONTROLS_SDL2 "src/platform/controls/sdl2/*[.hpp|.cpp]")

    file(GLOB SRC_IMGUI "${IMGUI_FOLDER}/im*[.h|.cpp]")
    file(GLOB SRC_IMGUI_SDL2 "${IMGUI_FOLDER}/backends/imgui_impl_sdl2*[.h|.cpp]")
    file(GLOB SRC_IMGUI_SDLRENDERER2 "${IMGUI_FOLDER}/backends/imgui_impl_sdlrenderer2*[.h|.cpp]")

    add_executable(${CMAKE_PROJECT_NAME}
        ${SRC_MAIN}
        ${SRC_MANAGER}

        ${SRC_SYSTEM}
        ${SRC_MODELS}

        ${SRC_PLATFORM_RENDERER_SDL2}
        ${SRC_PLATFORM_CONTROLS_SDL2}

        ${SRC_IMGUI}
        ${SRC_IMGUI_SDL2}
        ${SRC_IMGUI_SDLRENDERER2}
    )

    target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        "${IMGUI_FOLDER}"
    )

    find_package(SDL2)

    target_link_libraries(${CMAKE_PROJECT_NAME}
        SDL2
    )

    file(COPY assets DESTINATION .)

elseif(BUILD_MACOS)
    message(STATUS "Building for macOS")
    add_definitions(-DBUILD_MACOS)

    project(${GAME_NAME})

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")    # Use C++ version 17

    file(GLOB SRC_PLATFORM_RENDERER_SDL2 "src/platform/renderer/sdl2/*[.hpp|.cpp]")
    file(GLOB SRC_PLATFORM_CONTROLS_SDL2 "src/platform/controls/sdl2/*[.hpp|.cpp]")

    file(GLOB SRC_IMGUI "${IMGUI_FOLDER}/im*[.h|.cpp]")
    file(GLOB SRC_IMGUI_SDL2 "${IMGUI_FOLDER}/backends/imgui_impl_sdl2*[.h|.cpp]")
    file(GLOB SRC_IMGUI_SDLRENDERER2 "${IMGUI_FOLDER}/backends/imgui_impl_sdlrenderer2*[.h|.cpp]")

    add_executable(${CMAKE_PROJECT_NAME}
        ${SRC_MAIN}
        ${SRC_MANAGER}

        ${SRC_SYSTEM}
        ${SRC_MODELS}

        ${SRC_PLATFORM_RENDERER_SDL2}
        ${SRC_PLATFORM_CONTROLS_SDL2}

        ${SRC_IMGUI}
        ${SRC_IMGUI_SDL2}
        ${SRC_IMGUI_SDLRENDERER2}
    )

    target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        "${IMGUI_FOLDER}"
        "/opt/homebrew/include"
    )

    find_library(SDL2_LIBS sdl2)

    target_link_libraries(${CMAKE_PROJECT_NAME}
        ${SDL2_LIBS}
    )

    file(COPY assets DESTINATION .)

elseif(BUILD_VITA)
    message(STATUS "Building for PS Vita")
    add_definitions(-DBUILD_VITA)

    if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
        if(DEFINED ENV{VITASDK})
            set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
        else()
            message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
        endif()
    endif()

    project(${GAME_NAME})
    include("${VITASDK}/share/vita.cmake" REQUIRED)

    set(VITA_APPNAME "Sand-Box2D")
    set(VITA_TITLEID "SANDBOX2D")
    set(VITA_VERSION "01.00")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")    # Use C++ version 17

    set(VITA_MKSFOEX_FLAGS "${VITA_MKSFOEX_FLAGS} -d PARENTAL_LEVEL=1")

    file(GLOB SRC_PLATFORM_RENDERER_SDL2 "src/platform/renderer/sdl2/*[.hpp|.cpp]")
    file(GLOB SRC_PLATFORM_CONTROLS_SDL2 "src/platform/controls/sdl2/*[.hpp|.cpp]")

    add_executable(${CMAKE_PROJECT_NAME}
        ${SRC_MAIN}
        ${SRC_MANAGER}

        ${SRC_SYSTEM}
        ${SRC_MODELS}

        ${SRC_PLATFORM_RENDERER_SDL2}
        ${SRC_PLATFORM_CONTROLS_SDL2}
    )

    find_package(SDL2)

    target_link_libraries(${CMAKE_PROJECT_NAME}
        SDL2::SDL2
    )

    vita_create_self(${CMAKE_PROJECT_NAME}.self ${CMAKE_PROJECT_NAME})

    vita_create_vpk(${CMAKE_PROJECT_NAME}.vpk ${VITA_TITLEID} ${CMAKE_PROJECT_NAME}.self
        VERSION ${VITA_VERSION}
        NAME ${VITA_APPNAME}

        FILE assets assets
    )

else()
    message(STATUS "Please specify the build platform.")

endif()
