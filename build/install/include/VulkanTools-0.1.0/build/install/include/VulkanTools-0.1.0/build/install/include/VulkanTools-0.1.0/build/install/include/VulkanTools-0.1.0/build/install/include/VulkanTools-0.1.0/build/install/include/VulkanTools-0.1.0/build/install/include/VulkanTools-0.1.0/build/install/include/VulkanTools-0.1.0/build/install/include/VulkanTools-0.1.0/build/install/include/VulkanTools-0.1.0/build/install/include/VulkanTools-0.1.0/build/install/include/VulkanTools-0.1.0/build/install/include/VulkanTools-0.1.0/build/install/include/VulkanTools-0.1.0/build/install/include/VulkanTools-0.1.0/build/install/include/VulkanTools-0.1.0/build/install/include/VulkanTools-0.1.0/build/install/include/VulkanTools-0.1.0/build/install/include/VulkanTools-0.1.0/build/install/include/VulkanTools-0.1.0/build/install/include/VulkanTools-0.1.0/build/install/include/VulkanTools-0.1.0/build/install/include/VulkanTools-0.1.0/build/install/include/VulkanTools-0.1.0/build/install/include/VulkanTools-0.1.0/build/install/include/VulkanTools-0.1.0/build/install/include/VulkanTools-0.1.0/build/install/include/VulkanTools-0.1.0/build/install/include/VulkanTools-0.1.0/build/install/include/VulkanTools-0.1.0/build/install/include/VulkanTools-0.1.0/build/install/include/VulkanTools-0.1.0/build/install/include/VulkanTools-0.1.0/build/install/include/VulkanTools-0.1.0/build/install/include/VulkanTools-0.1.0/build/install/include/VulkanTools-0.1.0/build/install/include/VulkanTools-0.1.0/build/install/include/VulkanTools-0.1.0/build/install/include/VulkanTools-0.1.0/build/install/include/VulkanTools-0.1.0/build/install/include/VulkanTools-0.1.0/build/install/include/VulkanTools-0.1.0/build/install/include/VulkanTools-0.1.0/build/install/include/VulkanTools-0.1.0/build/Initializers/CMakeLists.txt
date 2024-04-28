add_library(Initializers STATIC VulkanPipelineInitializers.cpp)
target_include_directories(Initializers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Initializers PRIVATE Vulkan::Vulkan Utilities Structures)
