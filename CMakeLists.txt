cmake_minimum_required(VERSION 3.20)

project(cg_lab VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets WaylandCompositor)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets WaylandCompositor)


include_directories(${OPENGL_INCLUDE_DIRS})

#Gui

set( PROJECT_SOURCES
    main.cpp
    widget.cpp
    View.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
qt_add_executable(client-gui.out
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET client-gui.out APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
if(ANDROID)
    add_library(client-gui.out SHARED
        ${PROJECT_SOURCES}
    )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
else()
    add_executable(client-gui.out
        ${PROJECT_SOURCES}
    )
endif()
endif()

target_link_libraries(client-gui.out PRIVATE Qt${QT_VERSION_MAJOR}::Widgets  Qt${QT_VERSION_MAJOR}::WaylandCompositor pthread)

if(${QT_VERSION_MAJOR} LESS 6)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.client-gui.out)
endif()

set_target_properties(client-gui.out PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS client-gui.out
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(client-gui.out)
endif()

target_include_directories(client-gui.out PRIVATE Client/gui)

add_subdirectory(src)
