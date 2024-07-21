#pragma once
#include <VulkanTools/Instance.hpp>
namespace VkVP {
//submits registered command buffers to the queue
void submitBuffers(VulkanInstance &vulkanInstance, uint32_t &currentBufferIdx);
} // namespace VkVP