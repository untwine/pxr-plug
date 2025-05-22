add_library(TestPlugDso1 SHARED plugin.cpp)
target_link_libraries(TestPlugDso1 PUBLIC plug pxr::tf)
file(
    GENERATE
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/plugInfo_$<CONFIG>.json"
    INPUT plugInfo.json
)
