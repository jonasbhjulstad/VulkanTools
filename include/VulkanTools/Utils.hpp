#ifndef Vulkan_UTILS_HPP
#define Vulkan_UTILS_HPP
#include <vulkan/vulkan.hpp>
namespace VKT {
    auto getSupportedDepthFormat(VkPhysicalDevice physicalDevice, VkFormat *depthFormat) -> VkBool32;
} // namespace VKT

#endif // Vulkan_UTILS_HPP