#pragma once
#include <VulkanTools/Instance.hpp>
namespace VkVP {
// submits registered command buffers to the queue
void submitBuffers(VulkanInstance &vulkanInstance, uint32_t &currentBufferIdx);
void submitComputeBuffer(VkQueue queue, VkCommandBuffer computeCommandBuffer,
                         VkSemaphore graphicsSemaphore,
                         VkSemaphore computeSemaphore);
void submitBuffers(VulkanInstance &vulkanInstance,
                   VkCommandBuffer computeCommandBuffer,
                   VkSemaphore graphicsSemaphore,
                   VkSemaphore computeSemaphore);
} // namespace VkVP