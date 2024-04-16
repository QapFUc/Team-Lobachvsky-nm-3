
set( PROJECT_SOURCES
    main.cpp
    widget.cpp
)

add_executable( gui.out
                ${PROJECT_SOURCES}
)

target_link_libraries(gui.out PRIVATE Qt${QT_VERSION_MAJOR}::Widgets  Qt${QT_VERSION_MAJOR}::WaylandCompositor)