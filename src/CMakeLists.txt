configure_file(
    pxr/plug/pxr.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/pxr/plug/pxr.h
    @ONLY
)

add_library(plug
    pxr/plug/debugCodes.cpp
    pxr/plug/info.cpp
    pxr/plug/initConfig.cpp
    pxr/plug/interfaceFactory.cpp
    pxr/plug/notice.cpp
    pxr/plug/plugin.cpp
    pxr/plug/registry.cpp
    pxr/plug/staticInterface.cpp
)

target_include_directories(plug
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Compile features can only raise the effective standard, so this can't be
# undercut by a toolchain file that pre-sets CMAKE_CXX_STANDARD lower.
target_compile_features(plug PUBLIC cxx_std_17)

target_link_libraries(plug
    PUBLIC
        pxr::arch
        pxr::tf
        pxr::js
        pxr::trace
        pxr::work
        TBB::tbb
)

if(NOT WIN32 AND NOT SKBUILD)
    set_target_properties(plug PROPERTIES INSTALL_RPATH_USE_LINK_PATH TRUE)
endif()

if(BUILD_PYTHON_BINDINGS)
    target_sources(plug
        PRIVATE
            pxr/plug/moduleDeps.cpp
    )

    target_link_libraries(plug
        PUBLIC
            pxr::boost-python
    )

    add_subdirectory(python)
endif()

if (ENABLE_PRECOMPILED_HEADERS)
    target_precompile_headers(plug
        PRIVATE
            pxr/plug/pch.h
    )
endif()

set_target_properties(plug
    PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        OUTPUT_NAME "PxrPlug"
)

target_compile_definitions(plug
    PRIVATE
        PLUG_EXPORTS=1
        MFB_PACKAGE_MODULE=Plug
        MFB_PACKAGE_NAME=plug
        MFB_ALT_PACKAGE_NAME=plug
        PXR_BUILD_LOCATION="usd/*/resources/"
        PXR_PLUGIN_BUILD_LOCATION="../plugin/usd/*/resource/"
)

if (SKBUILD)
    target_compile_definitions(plug
        PRIVATE
            PXR_INSTALL_LOCATION="../../pxr/pluginfo/*/resources/"
    )
endif()

target_sources(plug
    PUBLIC
        FILE_SET public_headers
        TYPE HEADERS
        BASE_DIRS
            ${CMAKE_CURRENT_SOURCE_DIR}
            ${CMAKE_CURRENT_BINARY_DIR}
        FILES
            ${CMAKE_CURRENT_BINARY_DIR}/pxr/plug/pxr.h
            pxr/plug/api.h
            pxr/plug/interfaceFactory.h
            pxr/plug/notice.h
            pxr/plug/plugin.h
            pxr/plug/registry.h
            pxr/plug/staticInterface.h
            pxr/plug/thisPlugin.h
)

install(
    TARGETS plug EXPORT ${PROJECT_NAME}
    FILE_SET public_headers
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(EXPORT ${PROJECT_NAME}
    FILE pxr-plug-targets.cmake
    NAMESPACE pxr::
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/pxr-plug
)
