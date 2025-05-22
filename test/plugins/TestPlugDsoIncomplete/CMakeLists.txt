add_library(TestPlugDsoIncomplete SHARED plugin.cpp)
target_link_libraries(TestPlugDsoIncomplete PUBLIC plug pxr::tf)
