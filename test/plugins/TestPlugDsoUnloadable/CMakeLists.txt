add_library(TestPlugDsoUnloadable SHARED plugin.cpp)
target_link_libraries(TestPlugDsoUnloadable PUBLIC plug pxr::tf)
file(
    GENERATE
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/plugInfo_$<CONFIG>.json"
    INPUT plugInfo.json
)

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set_target_properties(TestPlugDsoUnloadable
        PROPERTIES LINK_FLAGS "-undefined dynamic_lookup"
    )
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # This forces the link to complete but the linker will still
    # report the missing symbol as an error and will also emit a
    # warning that the link was forced.  This is unfortunate as
    # it causes confusion.  There doesn't appear to be any way to
    # suppress either the warning or the error, though.  Rest
    # assured that the unresolved external symbol error is okay
    # for this target.
    set_target_properties(TestPlugDsoUnloadable
        PROPERTIES LINK_FLAGS "/FORCE:UNRESOLVED"
    )
endif()
