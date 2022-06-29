cmake_minimum_required(VERSION 3.23)
project(Vulkan_Tools)

find_package(Vulkan REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)
find_package(Threads REQUIRED)
find_package(Ktx REQUIRED)

include(FetchContent)
option(EXTERNAL_IMGUI ON)
if (NOT ON)
find_package(imgui REQUIRED HINTS "/usr/local/cmake/")
else()
message(STATUS "ImGui fetched from https://github.com/ocornut/imgui")
FetchContent_Declare(
    imgui_repo
    GIT_REPOSITORY https://github.com/ocornut/imgui
)
FetchContent_MakeAvailable(imgui_repo)
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

file(GLOB VULKAN_TOOLS_SRC VulkanTools/gltf/*.cpp VulkanTools/InstanceGraphics/*.cpp VulkanTools/Interactive/*.cpp VulkanTools/Routines/*.cpp VulkanTools/Structures/*.cpp VulkanTools/Utilities/*.cpp)
file(GLOB VULKAN_TOOLS_HEADERS VulkanTools/gltf/*.h VulkanTools/gltf/*.hpp VulkanTools/InstanceGraphics/*.hpp VulkanTools/Interactive/*.hpp VulkanTools/Routines/*.hpp VulkanTools/Structures/*.hpp VulkanTools/Utilities/*.hpp)
add_library(VulkanTools STATIC)
target_sources(VulkanTools PRIVATE ${VULKAN_TOOLS_SRC} PUBLIC FILE_SET HEADERS 
BASE_DIRS "${PROJECT_SOURCE_FOLDER}" FILES ${VULKAN_TOOLS_HEADERS})
target_include_directories(VulkanTools PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:include>)
target_link_libraries(VulkanTools KTX::ktx Vulkan::Vulkan imgui glfw glm::glm)
if (NOT imgui_FOUND)
install(TARGETS imgui EXPORT imguiConfig ARCHIVE DESTINATION lib PUBLIC_HEADER DESTINATION include/imgui)
install(EXPORT imguiConfig DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake/imguiConfig.cmake)
install(FILES ${IMGUI_HEADERS} DESTINATION include/imgui)
endif()

install(TARGETS VulkanTools EXPORT VulkanToolsConfig FILE_SET HEADERS DESTINATION include)
install(EXPORT VulkanToolsConfig NAMESPACE VulkanTools:: DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake/VulkanTools)
# install(FILES ${VULKAN_TOOLS_HEADERS} DESTINATION include/VulkanTools)

# install(EXPORT VulkanToolsConfig NAMESPACE VulkanTools DESTINATION ${CMAKE_INSTALL_LIBDIR})




