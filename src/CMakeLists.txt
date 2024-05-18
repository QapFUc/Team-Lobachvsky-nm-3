add_subdirectory(utils)


if(NOT ${NO_GUI})
    add_subdirectory(gui)
endif()

add_subdirectory(core)
add_subdirectory(dataTypes)


