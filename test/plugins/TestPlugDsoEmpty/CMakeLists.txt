add_library(TestPlugDsoEmpty SHARED plugin.cpp)
target_link_libraries(TestPlugDsoEmpty PUBLIC plugTest pxr::tf)
file(
    GENERATE
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/plugInfo_$<CONFIG>.json"
    INPUT plugInfo.json
)
