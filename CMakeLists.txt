cmake_minimum_required(VERSION 3.5)

option(BUILD_WINDOWS "Build Windows .exe" ON)
option(BUILD_LINUX "Build Linux executable" OFF)
option(BUILD_MACOS "Build macOS executable" OFF)
option(BUILD_VITA "Build PS Vita .vpk" OFF)

set(GAME_NAME "Sand-Box2D")

set(SRC_DIR "src")
set(IMGUI_DIR "${SRC_DIR}/lib/imgui")

file(GLOB SRC_MAIN "${SRC_DIR}/main*[.hpp|.cpp]")
file(GLOB SRC_MANAGER "${SRC_DIR}/game-manager*[.hpp|.cpp]")

file(GLOB_RECURSE SRC_SYSTEM "${SRC_DIR}/system/*[.hpp|.cpp]")
file(GLOB_RECURSE SRC_MODELS "${SRC_DIR}/models/*[.hpp|.cpp]")

file(GLOB SRC_IMGUI "${IMGUI_DIR}/im*[.h|.cpp]")

if(BUILD_WINDOWS)
    message(STATUS "Building for Windows")
    add_definitions(-DBUILD_WINDOWS)

    project(${GAME_NAME})

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")    # Use C++ version 17
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")     # Hide terminal window

    # SDL2 Implementations
    file(GLOB SRC_PLATFORM_RENDERER "${SRC_DIR}/platform/renderer/sdl2/*[.hpp|.cpp]")
    file(GLOB SRC_PLATFORM_CONTROLS "${SRC_DIR}/platform/controls/sdl2/*[.hpp|.cpp]")
    file(GLOB SRC_PLATFORM_IMGUI_MANAGER "${SRC_DIR}/platform/imgui-manager/sdl2/*[.hpp|.cpp]")

    # SDL2 Implementations
    file(GLOB SRC_IMGUI_WINDOW "${IMGUI_DIR}/backends/imgui_impl_sdl2*[.h|.cpp]")
    file(GLOB SRC_IMGUI_RENDERER "${IMGUI_DIR}/backends/imgui_impl_sdlrenderer2*[.h|.cpp]")

    add_executable(${CMAKE_PROJECT_NAME}
        ${SRC_MAIN}
        ${SRC_MANAGER}

        ${SRC_SYSTEM}
        ${SRC_MODELS}

        ${SRC_PLATFORM_RENDERER}
        ${SRC_PLATFORM_CONTROLS}
        ${SRC_PLATFORM_IMGUI_MANAGER}

        ${SRC_IMGUI}
        ${SRC_IMGUI_WINDOW}
        ${SRC_IMGUI_RENDERER}
    )

    find_package(SDL2)

    target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        "${SRC_DIR}"
        "${IMGUI_DIR}"
        "${SDL2_INCLUDE_DIRS}"
    )

    target_link_libraries(${CMAKE_PROJECT_NAME}
        SDL2::SDL2
    )

    file(COPY assets DESTINATION .)

elseif(BUILD_LINUX)
    message(STATUS "Building for Linux")
    add_definitions(-DBUILD_LINUX)

    project(${GAME_NAME})

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")    # Use C++ version 17

    # SDL2 Implementations
    file(GLOB SRC_PLATFORM_RENDERER "${SRC_DIR}/platform/renderer/sdl2/*[.hpp|.cpp]")
    file(GLOB SRC_PLATFORM_CONTROLS "${SRC_DIR}/platform/controls/sdl2/*[.hpp|.cpp]")
    file(GLOB SRC_PLATFORM_IMGUI_MANAGER "${SRC_DIR}/platform/imgui-manager/sdl2/*[.hpp|.cpp]")

    # SDL2 Implementations
    file(GLOB SRC_IMGUI "${IMGUI_DIR}/im*[.h|.cpp]")
    file(GLOB SRC_IMGUI_WINDOW "${IMGUI_DIR}/backends/imgui_impl_sdl2*[.h|.cpp]")
    file(GLOB SRC_IMGUI_RENDERER "${IMGUI_DIR}/backends/imgui_impl_sdlrenderer2*[.h|.cpp]")

    add_executable(${CMAKE_PROJECT_NAME}
        ${SRC_MAIN}
        ${SRC_MANAGER}

        ${SRC_SYSTEM}
        ${SRC_MODELS}

        ${SRC_PLATFORM_RENDERER}
        ${SRC_PLATFORM_CONTROLS}
        ${SRC_PLATFORM_IMGUI_MANAGER}

        ${SRC_IMGUI}
        ${SRC_IMGUI_WINDOW}
        ${SRC_IMGUI_RENDERER}
    )

    find_package(SDL2)

    target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        "${SRC_DIR}"
        "${IMGUI_DIR}"
        "${SDL2_INCLUDE_DIRS}"
    )

    target_link_libraries(${CMAKE_PROJECT_NAME}
        SDL2
    )

    file(COPY assets DESTINATION .)

elseif(BUILD_MACOS)
    message(STATUS "Building for macOS")
    add_definitions(-DBUILD_MACOS)

    project(${GAME_NAME})

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")    # Use C++ version 17

    # SDL2 Implementations
    file(GLOB SRC_PLATFORM_RENDERER "${SRC_DIR}/platform/renderer/sdl2/*[.hpp|.cpp]")
    file(GLOB SRC_PLATFORM_CONTROLS "${SRC_DIR}/platform/controls/sdl2/*[.hpp|.cpp]")
    file(GLOB SRC_PLATFORM_IMGUI_MANAGER "${SRC_DIR}/platform/imgui-manager/sdl2/*[.hpp|.cpp]")

    # SDL2 Implementations
    file(GLOB SRC_IMGUI "${IMGUI_DIR}/im*[.h|.cpp]")
    file(GLOB SRC_IMGUI_WINDOW "${IMGUI_DIR}/backends/imgui_impl_sdl2*[.h|.cpp]")
    file(GLOB SRC_IMGUI_RENDERER "${IMGUI_DIR}/backends/imgui_impl_sdlrenderer2*[.h|.cpp]")

    add_executable(${CMAKE_PROJECT_NAME}
        ${SRC_MAIN}
        ${SRC_MANAGER}

        ${SRC_SYSTEM}
        ${SRC_MODELS}

        ${SRC_PLATFORM_RENDERER}
        ${SRC_PLATFORM_CONTROLS}
        ${SRC_PLATFORM_IMGUI_MANAGER}

        ${SRC_IMGUI}
        ${SRC_IMGUI_WINDOW}
        ${SRC_IMGUI_RENDERER}
    )

    find_package(SDL2)

    target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        "${SRC_DIR}"
        "${IMGUI_DIR}"
        "${SDL2_INCLUDE_DIRS}"
    )

    target_link_libraries(${CMAKE_PROJECT_NAME}
        SDL2::SDL2
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

    # SDL2 Implementations
    file(GLOB SRC_PLATFORM_RENDERER "${SRC_DIR}/platform/renderer/sdl2/*[.hpp|.cpp]")
    file(GLOB SRC_PLATFORM_CONTROLS "${SRC_DIR}/platform/controls/sdl2/*[.hpp|.cpp]")

    # SDL2 Implementations Adapted for PS Vita
    file(GLOB SRC_PLATFORM_IMGUI_MANAGER "${SRC_DIR}/platform/imgui-manager/sdl2-vita/*[.hpp|.cpp]")

    add_executable(${CMAKE_PROJECT_NAME}
        ${SRC_MAIN}
        ${SRC_MANAGER}

        ${SRC_SYSTEM}
        ${SRC_MODELS}

        ${SRC_PLATFORM_RENDERER}
        ${SRC_PLATFORM_CONTROLS}
        ${SRC_PLATFORM_IMGUI_MANAGER}
    )

    find_package(SDL2)

    target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        "${SDL2_INCLUDE_DIRS}"
    )

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
