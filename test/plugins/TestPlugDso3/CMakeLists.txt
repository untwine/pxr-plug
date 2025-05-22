add_library(TestPlugDso3 SHARED plugin.cpp)
target_link_libraries(TestPlugDso3 PUBLIC plugTest pxr::tf)
file(
    GENERATE
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/plugInfo_$<CONFIG>.json"
    INPUT plugInfo.json
)
