cmake_minimum_required(VERSION 3.20)

project(nm_spline VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(CMAKE_CXX_COMPILER clang++)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include(cmake/testing_util.cmake)

option(NO_GUI "specify to build w/o gui part" OFF)

if(NOT ${NO_GUI})
    find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets WaylandCompositor)
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets WaylandCompositor)
endif()

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
