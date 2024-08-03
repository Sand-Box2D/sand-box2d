cmake_minimum_required(VERSION 3.5)

option(BUILD_WINDOWS "Build Windows .exe" ON) # Default. Windows means using MSYS2 / UCRT tools
option(BUILD_LINUX "Build Linux executable" OFF)
option(BUILD_MACOS "Build macOS executable" OFF)
option(BUILD_VITA "Build PS Vita .vpk" OFF)

set(GAME_NAME "Sand-Box2D")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

if(BUILD_WINDOWS)
    message(STATUS "Building for Windows")
    add_definitions(-DBUILD_WINDOWS)

    project(${GAME_NAME})

elseif(BUILD_LINUX)
    message(STATUS "Building for Linux")
    add_definitions(-DBUILD_LINUX)

    project(${GAME_NAME})

elseif(BUILD_MACOS)
    message(STATUS "Building for macOS")
    add_definitions(-DBUILD_MACOS)

    project(${GAME_NAME})

elseif(BUILD_VITA)
    message(STATUS "Building for PS Vita")
    add_definitions(-DBUILD_VITA)

    project(${GAME_NAME})

else()
    message(STATUS "Please specify the build platform.")

endif()

## TEST
add_executable(${CMAKE_PROJECT_NAME} "src/main.cpp")
#######
