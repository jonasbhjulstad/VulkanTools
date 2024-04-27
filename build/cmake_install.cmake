# Install script for directory: /home/deb/Downloads/CLCPP-Vulkan-Tools

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/libimgui.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/cmake/imguiConfig.cmake/imguiConfig.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}/usr/local/lib/cmake/imguiConfig.cmake/imguiConfig.cmake"
         "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/CMakeFiles/Export/49d180369873b459d9aa04fcf781500e/imguiConfig.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}/usr/local/lib/cmake/imguiConfig.cmake/imguiConfig-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}/usr/local/lib/cmake/imguiConfig.cmake/imguiConfig.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/cmake/imguiConfig.cmake/imguiConfig.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib/cmake/imguiConfig.cmake" TYPE FILE FILES "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/CMakeFiles/Export/49d180369873b459d9aa04fcf781500e/imguiConfig.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "/usr/local/lib/cmake/imguiConfig.cmake/imguiConfig-debug.cmake")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "/usr/local/lib/cmake/imguiConfig.cmake" TYPE FILE FILES "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/CMakeFiles/Export/49d180369873b459d9aa04fcf781500e/imguiConfig-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/imgui" TYPE FILE FILES
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui_repo-src/imconfig.h"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui_repo-src/imgui.h"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui_repo-src/imgui_impl_glfw.h"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui_repo-src/imgui_impl_vulkan.h"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui_repo-src/imgui_internal.h"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui_repo-src/imstb_rectpack.h"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui_repo-src/imstb_textedit.h"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui_repo-src/imstb_truetype.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/libVulkanTools.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/VulkanTools/InstanceGraphics" TYPE FILE FILES
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/InstanceGraphics/GLTF_Assets.hpp"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/InstanceGraphics/GLTF_BasicInstance.hpp"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/InstanceGraphics/VulkanEdgeInstance.hpp"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/InstanceGraphics/VulkanNodeInstance.hpp"
    )
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/VulkanTools/Interactive" TYPE FILE FILES
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/Interactive/VulkanCamera.hpp"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/Interactive/VulkanProjectionBuffer.hpp"
    )
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/VulkanTools/Routines" TYPE FILE FILES
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/Routines/VulkanSetup.hpp"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/Routines/VulkanWindow.hpp"
    )
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/VulkanTools/Structures" TYPE FILE FILES
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/Structures/VulkanBuffer.hpp"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/Structures/VulkanDevice.hpp"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/Structures/VulkanInstance.hpp"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/Structures/VulkanSwapChain.hpp"
    )
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/VulkanTools/Utilities" TYPE FILE FILES
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/Utilities/VulkanDebug.hpp"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/Utilities/VulkanInitializers.hpp"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/Utilities/VulkanPipelineInitializers.hpp"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/Utilities/VulkanTools.hpp"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/Utilities/VulkanUtils.hpp"
    )
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/VulkanTools/gltf" TYPE FILE FILES
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/gltf/VulkanTexture.hpp"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/gltf/VulkanglTFModel.hpp"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/gltf/json.hpp"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/gltf/stb_image.h"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/gltf/stb_image_write.h"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/VulkanTools/gltf/tiny_gltf.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/cmake/VulkanTools/VulkanToolsConfig.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}/usr/local/lib/cmake/VulkanTools/VulkanToolsConfig.cmake"
         "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/CMakeFiles/Export/52514b350dbbe639590e1462a02d2f3f/VulkanToolsConfig.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}/usr/local/lib/cmake/VulkanTools/VulkanToolsConfig-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}/usr/local/lib/cmake/VulkanTools/VulkanToolsConfig.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/cmake/VulkanTools/VulkanToolsConfig.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib/cmake/VulkanTools" TYPE FILE FILES "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/CMakeFiles/Export/52514b350dbbe639590e1462a02d2f3f/VulkanToolsConfig.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "/usr/local/lib/cmake/VulkanTools/VulkanToolsConfig-debug.cmake")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "/usr/local/lib/cmake/VulkanTools" TYPE FILE FILES "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/CMakeFiles/Export/52514b350dbbe639590e1462a02d2f3f/VulkanToolsConfig-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
