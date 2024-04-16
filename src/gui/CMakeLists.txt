
set( PROJECT_SOURCES
    main.cpp
    widget.cpp
)

add_executable( gui.out
                ${PROJECT_SOURCES}
)

option(X11 "Use this option if you have X11" OFF)
option(MAC "Use this option if you have MAC"  OFF)

if(${X11})
    target_link_libraries(gui.out PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
endif()

if(${MAC})
    target_link_libraries(gui.out PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
endif()

if(NOt ${X11} and NOT ${MAC})
    target_link_libraries(gui.out PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::WaylandCompositor)
endif()