cmake_minimum_required(VERSION 3.23)
project(VulkanTools)
set(PROJECT_NAMESPACE VulkanTools)
set(PROJECT_VERSION 0.1.0)
include(cmake/ccache.cmake)
include(cmake/external_packages.cmake)

option(VULKAN_TOOLS_PRECOMPILE_MAIN_HEADER "Precompile main header" ON)
file(GLOB_RECURSE VULKAN_TOOLS_SOURCES "source/*.cpp")
add_library(VulkanTools ${VULKAN_TOOLS_SOURCES})
target_include_directories(VulkanTools PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
target_link_libraries(VulkanTools PRIVATE KTX::ktx Vulkan::Vulkan imgui glfw glm::glm)
if(VULKAN_TOOLS_PRECOMPILE_MAIN_HEADER)
target_precompile_headers(VulkanTools PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAMESPACE}/${PROJECT_NAMESPACE}.hpp>)
endif()
# install(FILES ${VULKAN_TOOLS_HEADERS} DESTINATION include/VulkanTools)
# include(${PROJECT_SOURCE_DIR}/cmake/CPM.cmake)
# find_package(Vulkan REQUIRED)
# find_package(glfw3 3.3 REQUIRED)
# find_package(glm REQUIRED)
# find_package(Threads REQUIRED)
# find_package(Ktx REQUIRED)
# install(EXPORT VulkanToolsConfig NAMESPACE VulkanTools DESTINATION ${CMAKE_INSTALL_LIBDIR})
packageProject(
  # the name of the target to export
  NAME ${PROJECT_NAME}
  # the version of the target to export
  VERSION ${PROJECT_VERSION}
  # a temporary directory to create the config files
  BINARY_DIR ${PROJECT_BINARY_DIR}
  # location of the target's public headers
  INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include
  # should match the target's INSTALL_INTERFACE include directory
  INCLUDE_DESTINATION include/${PROJECT_NAME}-${PROJECT_VERSION}
  # (optional) option to install only header files with matching pattern
  INCLUDE_HEADER_PATTERN "*.h"
  # semicolon separated list of the project's dependencies
  DEPENDENCIES "Vulkan 1.2.162; glfw 3.3; glm; Ktx"
  # (optional) create a header containing the version info
  # Note: that the path to headers should be lowercase
  VERSION_HEADER "${PROJECT_NAME}/version.h"
  # (optional) create a export header using GenerateExportHeader module
  EXPORT_HEADER "${PROJECT_NAME}/export.h"
  # (optional) install your library with a namespace (Note: do NOT add extra '::')
  NAMESPACE ${PROJECT_NAMESPACE}
  # (optional) define the project's version compatibility, defaults to `AnyNewerVersion`
  # supported values: `AnyNewerVersion|SameMajorVersion|SameMinorVersion|ExactVersion`
  COMPATIBILITY AnyNewerVersion
  # (optional) option to disable the versioning of install destinations
  DISABLE_VERSION_SUFFIX YES
  # (optional) option to ignore target architecture for package resolution
  # defaults to YES for header only (i.e. INTERFACE) libraries
  ARCH_INDEPENDENT YES
  # (optional) option to generate CPack variables
  CPACK YES
)



