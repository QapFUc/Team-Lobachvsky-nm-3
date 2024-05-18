set(TARGET_NAME test_util)

file(GLOB_RECURSE SRCS "*.[c|h]pp")

add_library(${TARGET_NAME} STATIC ${SRCS})
add_library(test::util ALIAS ${TARGET_NAME})

target_include_directories(${TARGET_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)