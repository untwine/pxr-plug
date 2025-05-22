# TODO: Separate C++ plugin tests so they can run independently of Python bindings.
if(BUILD_PYTHON_BINDINGS)
    add_subdirectory(plugins)

    set(plugins_src "${CMAKE_CURRENT_SOURCE_DIR}/plugins")
    set(plugins_bin "${CMAKE_CURRENT_BINARY_DIR}/plugins")

    pytest_discover_tests(
        TestPlug
        LIBRARY_PATH_PREPEND
            $<TARGET_FILE_DIR:plug>
            $<TARGET_FILE_DIR:pyPlug>
            $<TARGET_FILE_DIR:pxr::gf>
            $<TARGET_FILE_DIR:pxr::pyGf>
            $<TARGET_FILE_DIR:pxr::tf>
            $<TARGET_FILE_DIR:pxr::pyTf>
        PYTHON_PATH_PREPEND
            "$<TARGET_FILE_DIR:pyPlug>/../.."
            "$<TARGET_FILE_DIR:pxr::pyGf>/../.."
            "$<TARGET_FILE_DIR:pxr::pyTf>/../.."
            "${plugins_src}/python"
        TRIM_FROM_NAME "^test_"
        TRIM_FROM_FULL_NAME "^TestPlug\."
        ENVIRONMENT
            "PLUGINS_DSO_SEARCH=${plugins_bin}/TestPlugDso*/plugInfo_$<CONFIG>.json"
            "PLUGINS_PYTHON_SEARCH=${plugins_src}/python/*/"
            "PLUGIN_DSO_INCOMPLETE_PATH=$<TARGET_FILE_DIR:TestPlugDsoIncomplete>"
            "PLUGIN_PYTHON_INCOMPLETE_PATH=${plugins_src}/python/TestPlugModuleIncomplete"
        EXTRA_ARGS "-v"
        DEPENDS plug pyPlug
    )
endif ()
