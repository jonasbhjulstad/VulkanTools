include(${PROJECT_SOURCE_DIR}/cmake/CPM.cmake)
find_package(Vulkan REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)

# find_package(Threads REQUIRED)
find_package(Ktx REQUIRED)
CPMAddPackage("gh:TheLartians/PackageProject.cmake@1.6.0")
CPMAddPackage("gh:jonasbhjulstad/imgui#cmake")