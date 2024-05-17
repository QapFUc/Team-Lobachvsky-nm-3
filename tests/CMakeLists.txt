add_subdirectory(utils)

set(TEST_FILES "")
file(GLOB SRCS "test_*.cpp")

foreach(FILE IN LISTS SRCS)
    list(APPEND TEST_FILES ${FILE})
endforeach()

set(LIBS
    nm::prof 
    nm::logger 
    spline::core 
    spline::dtypes 
    test::util 
)

nm_add_tests("${TEST_FILES}" "${LIBS}")

