#pragma once

#pragma once
#include <VulkanTools/Instance.hpp>
#include <VulkanTools/InstanceRendering/InstancePipeline.hpp>
#include <VulkanTools/Tools.hpp>
#include <VulkanTools/Renderpass.hpp>
// #include <VulkanViewport/UI/ImGuiUI.hpp>
#include <vector>
#include <vulkan/vulkan.hpp>
namespace VkVP
{

// void buildCommandBuffers(
//     std::vector<VkCommandBuffer> &commandBuffers,
//     std::vector<VkFramebuffer> &frameBuffers, VkRenderPass renderPass,
//     VkVP::ImGuiVulkanData &ivData,
//     const std::vector<std::unique_ptr<VkVP::InstancePipelineData>>
//         &instancePipelines,
//     int width, int height) {
//   // VkCommandBufferBeginInfo cmdBufInfo =
//   // initializers::commandBufferBeginInfo();
//   for (int32_t i = 0; i < commandBuffers.size(); ++i) {

//     // VK_CHECK_RESULT(vkBeginCommandBuffer(commandBuffer[i], &cmdBufInfo));
//     beginCommandBuffer(commandBuffers[i]);

//     beginRenderPass(renderPass, commandBuffers[i], frameBuffers[i], width,
//                     height);
//     for (auto &instancePipeline : instancePipelines) {
//       buildCommandBuffer(*instancePipeline, commandBuffers[i]);
//     }
//     VkVP::drawFrame(ivData, commandBuffers[i]);

//     vkCmdEndRenderPass(commandBuffers[i]);

//     VK_CHECK_RESULT(vkEndCommandBuffer(commandBuffers[i]));
//   }
// }



}  // namespace VkVP