add_library(pyPlugTest SHARED
    module.cpp
    wrapTestPlugBase.cpp
)

set_target_properties(pyPlugTest
    PROPERTIES
        PREFIX ""
        OUTPUT_NAME _plug_test
        RUNTIME_OUTPUT_DIRECTORY "$<CONFIG>/plug_test"
        LIBRARY_OUTPUT_DIRECTORY "$<CONFIG>/plug_test"
        ARCHIVE_OUTPUT_DIRECTORY "$<CONFIG>/plug_test"
        POSITION_INDEPENDENT_CODE ON
)

target_include_directories(pyPlugTest
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(pyPlugTest
    PUBLIC
        plugTest
        pxr::boost-python
)

if(WIN32)
    set_target_properties(pyPlugTest PROPERTIES SUFFIX ".pyd")
elseif(APPLE)
    set_target_properties(pyPlugTest PROPERTIES SUFFIX ".so")
endif()

target_compile_definitions(
    pyPlugTest
    PRIVATE
        BOOST_BIND_GLOBAL_PLACEHOLDERS
        BOOST_PYTHON_NO_PY_SIGNATURES
        MFB_PACKAGE_MODULE=PlugTest
        MFB_PACKAGE_NAME=plug_test
        MFB_ALT_PACKAGE_NAME=plug_test
)

file(
    GENERATE
    OUTPUT "$<TARGET_FILE_DIR:pyPlugTest>/__init__.py"
    INPUT "__init__.py"
)
