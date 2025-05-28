add_library(plugTest
    plugTest/testPlugBase.cpp
)

target_include_directories(plugTest
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(plugTest
    PUBLIC
        plug
)

target_compile_definitions(plugTest
    PRIVATE
        PLUG_EXPORTS=1
)

if(BUILD_PYTHON_BINDINGS)
    add_subdirectory(python)
endif()