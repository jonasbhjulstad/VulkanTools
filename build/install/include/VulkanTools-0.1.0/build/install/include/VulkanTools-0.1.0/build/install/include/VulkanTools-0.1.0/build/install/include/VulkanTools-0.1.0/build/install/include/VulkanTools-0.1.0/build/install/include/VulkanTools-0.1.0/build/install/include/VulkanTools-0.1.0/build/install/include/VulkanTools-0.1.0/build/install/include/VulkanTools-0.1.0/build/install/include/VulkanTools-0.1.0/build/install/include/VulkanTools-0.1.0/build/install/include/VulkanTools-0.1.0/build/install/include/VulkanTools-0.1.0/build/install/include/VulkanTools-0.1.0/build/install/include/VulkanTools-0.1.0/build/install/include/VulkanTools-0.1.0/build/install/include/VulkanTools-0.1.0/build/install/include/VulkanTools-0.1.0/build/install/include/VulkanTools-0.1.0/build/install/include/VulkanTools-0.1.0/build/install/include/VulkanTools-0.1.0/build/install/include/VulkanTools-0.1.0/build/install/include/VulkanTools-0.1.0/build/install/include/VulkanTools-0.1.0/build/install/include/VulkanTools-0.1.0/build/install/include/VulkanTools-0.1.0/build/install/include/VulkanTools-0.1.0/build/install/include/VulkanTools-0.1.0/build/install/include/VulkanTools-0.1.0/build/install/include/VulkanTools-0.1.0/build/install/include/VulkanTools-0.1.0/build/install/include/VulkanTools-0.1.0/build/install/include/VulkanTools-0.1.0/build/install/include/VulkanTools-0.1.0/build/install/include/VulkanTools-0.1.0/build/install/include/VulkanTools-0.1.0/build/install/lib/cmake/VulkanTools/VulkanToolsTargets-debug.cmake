#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "VulkanTools::VulkanTools" for configuration "Debug"
set_property(TARGET VulkanTools::VulkanTools APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(VulkanTools::VulkanTools PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/VulkanTools/libVulkanTools.a"
  )

list(APPEND _cmake_import_check_targets VulkanTools::VulkanTools )
list(APPEND _cmake_import_check_files_for_VulkanTools::VulkanTools "${_IMPORT_PREFIX}/lib/VulkanTools/libVulkanTools.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
