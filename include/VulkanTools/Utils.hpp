#ifndef Vulkan_UTILS_HPP
#define Vulkan_UTILS_HPP
#include <vulkan/vulkan.hpp>
auto getSupportedDepthFormat(VkPhysicalDevice physicalDevice, VkFormat *depthFormat) -> VkBool32;

#endif // Vulkan_UTILS_HPP