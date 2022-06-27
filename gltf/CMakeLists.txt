file(GLOB VULKAN_GLTF_SRC "*.cpp")
add_library(GLTF STATIC ${VULKAN_GLTF_SRC})
target_include_directories(GLTF PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(GLTF PRIVATE Vulkan::Vulkan Utilities Structures Initializers)