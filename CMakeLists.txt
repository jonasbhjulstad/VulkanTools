cmake_minimum_required(VERSION 3.23)
project(CLCPP_Vulkan_Tools)

find_package(Vulkan REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)
find_package(Ktx REQUIRED)

include(FetchContent)
find_package(imgui QUIET)
if (NOT IMGUI_FOUND)
message(STATUS "ImGui fetched from https://github.com/ocornut/imgui")
FetchContent_Declare(
    imgui_repo
    GIT_REPOSITORY https://github.com/ocornut/imgui
)
FetchContent_MakeAvailable(imgui_repo)
file(GLOB IMGUI_SRC "${imgui_repo_SOURCE_DIR}/*.cpp")
set(IMGUI_BACKEND "${imgui_repo_SOURCE_DIR}/backends/imgui_impl_vulkan.cpp" "${imgui_repo_SOURCE_DIR}/backends/imgui_impl_glfw.cpp")
add_library(imgui STATIC ${IMGUI_SRC} ${IMGUI_BACKEND})
target_include_directories(imgui PUBLIC ${imgui_repo_SOURCE_DIR} "${imgui_repo_SOURCE_DIR}/backends")
target_link_libraries(imgui PUBLIC Vulkan::Vulkan)
target_compile_options(imgui PRIVATE "-O3")
endif()

add_subdirectory(Utilities)
add_subdirectory(Initializers)
add_subdirectory(Interactive)
add_subdirectory(Structures)
add_subdirectory(gltf)
add_subdirectory(InstanceGraphics)
add_subdirectory(Routines)





