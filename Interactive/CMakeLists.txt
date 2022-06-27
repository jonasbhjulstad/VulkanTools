file(GLOB INTERACTIVE_SRC "*.cpp")
add_library(Interactive STATIC ${INTERACTIVE_SRC})
target_link_libraries(Interactive PRIVATE imgui Structures Utilities)
target_include_directories(Interactive PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})