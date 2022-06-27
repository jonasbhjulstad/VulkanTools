file(GLOB INSTANCE_GRAPHICS_SRC "*.cpp")
add_library(InstanceGraphics STATIC ${INSTANCE_GRAPHICS_SRC})
target_include_directories(InstanceGraphics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(InstanceGraphics PRIVATE GLTF Structures Initializers Utilities)
