add_subdirectory(utils)
add_subdirectory(gui)
add_subdirectory(core)
add_subdirectory(dataTypes)

add_executable(test main.cpp)
target_compile_options(test PUBLIC -O3)
target_link_libraries(test PRIVATE 
    nm::prof
    nm::logger
    spline::core
    spline::dtypes
)