function(nm_add_tests EXECS LIBS)
    foreach(ex IN LISTS EXECS)
    get_filename_component(FNAME ${ex} NAME_WE)
        set(TARGET_NAME ${FNAME})
        add_executable(${TARGET_NAME} ${ex})

        target_link_libraries(${TARGET_NAME} PRIVATE ${LIBS})
        
        add_test(NAME ${TARGET_NAME} COMMAND $<TARGET_FILE:${TARGET_NAME}>)
    endforeach()
endfunction()
