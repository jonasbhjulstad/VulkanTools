# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/deb/.CPM/imgui/e01586cb61b1f0b5251ffecbe55802a4a415bc39"
  "/home/deb/Documents/VulkanTools/build/_deps/imgui-build"
  "/home/deb/Documents/VulkanTools/build/_deps/imgui-subbuild/imgui-populate-prefix"
  "/home/deb/Documents/VulkanTools/build/_deps/imgui-subbuild/imgui-populate-prefix/tmp"
  "/home/deb/Documents/VulkanTools/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp"
  "/home/deb/Documents/VulkanTools/build/_deps/imgui-subbuild/imgui-populate-prefix/src"
  "/home/deb/Documents/VulkanTools/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/deb/Documents/VulkanTools/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/deb/Documents/VulkanTools/build/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
