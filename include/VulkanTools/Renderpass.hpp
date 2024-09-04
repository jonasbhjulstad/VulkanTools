#pragma once
#include <vulkan/vulkan.h>
namespace VkVP {
void beginRenderPass(VkRenderPass renderPass, VkCommandBuffer commandBuffer,
                     VkFramebuffer frameBuffer, uint32_t width,
                     uint32_t height);
} // namespace VkVO