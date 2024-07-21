#ifndef Vulkan_SETUP_HPP
#define Vulkan_SETUP_HPP
#include <string>
#include <VulkanTools/Instance.hpp>

VkResult createVulkanInstance(bool enableValidation,
							  const std::string &name,
							  VkInstance& instance,
							  std::vector<std::string> &supportedInstanceExtensions,
							  std::vector<const char *> &enabledInstanceExtensions,
							  uint32_t apiVersion);
void setupVulkanPhysicalDevice(VulkanInstance &vulkanInstance, bool enableValidation, bool enable_compute_queue = false);

void prepareVulkan(VulkanInstance &vulkanInstance, uint32_t width, uint32_t height);

#endif