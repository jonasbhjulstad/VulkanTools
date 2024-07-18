#include <VulkanTools/Renderpass.hpp>
#include <VulkanTools/Initializers.hpp>
namespace VkVP {
void beginRenderPass(VkRenderPass renderPass, VkCommandBuffer commandBuffer,
                     VkFramebuffer frameBuffer, uint32_t width,
                     uint32_t height) {
  VkClearValue clearValues[2];
  clearValues[0].color = {{67. / 255, 74. / 255, 69. / 255, 1.f}};
  clearValues[1].depthStencil = {1.0f, 0};

  VkRenderPassBeginInfo renderPassBeginInfo =
      initializers::renderPassBeginInfo();
  renderPassBeginInfo.framebuffer = frameBuffer;

  renderPassBeginInfo.renderPass = renderPass;
  renderPassBeginInfo.renderArea.offset.x = 0;
  renderPassBeginInfo.renderArea.offset.y = 0;
  renderPassBeginInfo.renderArea.extent.width = width;
  renderPassBeginInfo.renderArea.extent.height = height;
  renderPassBeginInfo.clearValueCount = 2;
  renderPassBeginInfo.pClearValues = clearValues;

  vkCmdBeginRenderPass(commandBuffer, &renderPassBeginInfo,
                       VK_SUBPASS_CONTENTS_INLINE);

  VkViewport viewport =
      initializers::viewport((float)width, (float)height, 0.0f, 1.0f);
  vkCmdSetViewport(commandBuffer, 0, 1, &viewport);

  VkRect2D scissor = initializers::rect2D(width, height, 0, 0);
  vkCmdSetScissor(commandBuffer, 0, 1, &scissor);
}
} // namespace VkVO