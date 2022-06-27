file(GLOB UTILITIES_SRC "*.cpp")
add_library(Utilities STATIC ${UTILITIES_SRC})
target_link_libraries(Utilities PRIVATE Initializers)
target_include_directories(Utilities PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
