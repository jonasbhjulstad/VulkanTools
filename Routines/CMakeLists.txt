file(GLOB ROUTINES_SRC "*.cpp")
add_library(ROUTINES STATIC ${ROUTINES_SRC})
target_include_directories(ROUTINES PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ROUTINES PRIVATE Structures Initializers Utilities)