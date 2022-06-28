cmake_minimum_required(VERSION 3.23)
project(CLCPP_Vulkan_Tools)

find_package(Vulkan REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)
find_package(Ktx REQUIRED)

include(FetchContent)
option(EXTERNAL_IMGUI ON)
find_package(imgui REQUIRED HINTS "/usr/local/cmake/")
if (${IMGUI_FOUND})
else()
message(STATUS "ImGui fetched from https://github.com/ocornut/imgui")
FetchContent_Declare(
    imgui_repo
    GIT_REPOSITORY https://github.com/ocornut/imgui
)
FetchContent_MakeAvailable(imgui_repo)
message(WARNING ${imgui_repo_SOURCE_DIR})
set(IMGUI_BACKEND_SRC ${imgui_repo_SOURCE_DIR}/backends/imgui_impl_vulkan.cpp ${imgui_repo_SOURCE_DIR}/backends/imgui_impl_glfw.cpp)
set(IMGUI_BACKEND_HEADERS ${imgui_repo_SOURCE_DIR}/backends/imgui_impl_vulkan.h ${imgui_repo_SOURCE_DIR}/backends/imgui_impl_glfw.h)
file(COPY ${IMGUI_BACKEND_SRC} DESTINATION ${imgui_repo_SOURCE_DIR})
file(COPY ${IMGUI_BACKEND_HEADERS} DESTINATION ${imgui_repo_SOURCE_DIR})
file(GLOB IMGUI_SRC CONFIGURE_DEPENDS "${imgui_repo_SOURCE_DIR}/*.cpp")
file(GLOB IMGUI_HEADERS CONFIGURE_DEPENDS "${imgui_repo_SOURCE_DIR}/*.h")
add_library(imgui STATIC ${IMGUI_SRC} ${IMGUI_HEADERS})
target_link_libraries(imgui PUBLIC Vulkan::Vulkan)
target_include_directories(imgui PUBLIC $<BUILD_INTERFACE:${imgui_repo_SOURCE_DIR}> $<INSTALL_INTERFACE:include/imgui>)
# target_include_directories(imgui PUBLIC ${imgui_repo_SOURCE_DIR} "${imgui_repo_SOURCE_DIR}/backends")
endif()

file(GLOB CLCPP_VULKAN_TOOLS_SRC gltf/*.cpp InstanceGraphics/*.cpp Interactive/*.cpp Routines/*.cpp Structures/*.cpp Utilities/*.cpp)
file(GLOB CLCPP_VULKAN_TOOLS_HEADERS gltf/*.h InstanceGraphics/*.h Interactive/*.h Routines/*.h Structures/*.h Utilities/*.h)
add_library(VulkanTools STATIC ${CLCPP_VULKAN_TOOLS_SRC} ${CLCPP_VULKAN_TOOLS_HEADERS})
target_include_directories(VulkanTools PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:include/VulkanTools>)
target_link_libraries(VulkanTools Vulkan::Vulkan imgui glfw3 glm)
if (NOT IMGUI_FOUND)
install(TARGETS imgui EXPORT imguiConfig)
install(EXPORT imguiConfig DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake/imguiConfig.cmake)
endif()

install(TARGETS VulkanTools EXPORT CLCPP_VulkanToolsConfig)
install(EXPORT CLCPP_VulkanToolsConfig NAMESPACE CLCPP_VulkanTools DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake/CLCPP_VulkanToolsConfig.cmake)
# install(EXPORT CLCPP_VulkanToolsConfig NAMESPACE CLCPP_VulkanTools DESTINATION ${CMAKE_INSTALL_LIBDIR})





