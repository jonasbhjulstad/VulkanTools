# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui_repo-src"
  "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui_repo-build"
  "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui_repo-subbuild/imgui_repo-populate-prefix"
  "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui_repo-subbuild/imgui_repo-populate-prefix/tmp"
  "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui_repo-subbuild/imgui_repo-populate-prefix/src/imgui_repo-populate-stamp"
  "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui_repo-subbuild/imgui_repo-populate-prefix/src"
  "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui_repo-subbuild/imgui_repo-populate-prefix/src/imgui_repo-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui_repo-subbuild/imgui_repo-populate-prefix/src/imgui_repo-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui_repo-subbuild/imgui_repo-populate-prefix/src/imgui_repo-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
