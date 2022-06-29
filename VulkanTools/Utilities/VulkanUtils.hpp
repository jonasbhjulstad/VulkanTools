#ifndef Vulkan_UTILS_HPP
#define Vulkan_UTILS_HPP
#include <vulkan/vulkan.hpp>
VkBool32 getSupportedDepthFormat(VkPhysicalDevice physicalDevice, VkFormat *depthFormat);

#endif // Vulkan_UTILS_HPP