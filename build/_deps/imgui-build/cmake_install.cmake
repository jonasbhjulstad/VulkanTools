# Install script for directory: /home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/install")
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

if(CMAKE_INSTALL_COMPONENT STREQUAL "imgui_Development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/imgui-1.82" TYPE DIRECTORY FILES "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui-build/PackageProjectInclude/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "imgui_Development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/imgui" TYPE STATIC_LIBRARY FILES "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui-build/libimgui.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "imgui_Development" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/imgui/imguiTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/imgui/imguiTargets.cmake"
         "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui-build/CMakeFiles/Export/1c9f1db1a0c9398944d65050189647a4/imguiTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/imgui/imguiTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/imgui/imguiTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/imgui" TYPE FILE FILES "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui-build/CMakeFiles/Export/1c9f1db1a0c9398944d65050189647a4/imguiTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/imgui" TYPE FILE FILES "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui-build/CMakeFiles/Export/1c9f1db1a0c9398944d65050189647a4/imguiTargets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "imgui_Development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/imgui" TYPE FILE FILES
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui-build/imguiConfigVersion.cmake"
    "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui-build/imguiConfig.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "imgui_Development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/imgui-1.82" TYPE DIRECTORY FILES "/home/deb/Downloads/CLCPP-Vulkan-Tools/build/_deps/imgui-src/include//")
endif()

