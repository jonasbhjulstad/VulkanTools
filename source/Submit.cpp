#include <VulkanTools/Initializers.hpp>
#include <VulkanTools/Submit.hpp>
namespace VkVP {
// void submitBuffers(VulkanInstance &vulkanInstance, uint32_t
// &currentBufferIdx) {
//   VK_CHECK_RESULT(vulkanInstance.swapChain.acquireNextImage(
//       vulkanInstance.semaphores.presentComplete, &currentBufferIdx));
//   vulkanInstance.submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
//   vulkanInstance.submitInfo.commandBufferCount = 1;
//   vulkanInstance.submitInfo.pCommandBuffers =
//       &vulkanInstance.drawCmdBuffers[currentBufferIdx];
//   vulkanInstance.submitInfo.pNext = nullptr;
//   VK_CHECK_RESULT(vkQueueSubmit(vulkanInstance.queue, 1,
//                                 &vulkanInstance.submitInfo, VK_NULL_HANDLE));
//   VK_CHECK_RESULT(vulkanInstance.swapChain.queuePresent(
//       vulkanInstance.queue, currentBufferIdx,
//       vulkanInstance.semaphores.renderComplete));
//   VK_CHECK_RESULT(vkQueueWaitIdle(vulkanInstance.queue));
// }

void submitComputeBuffer(VkQueue queue, VkCommandBuffer computeCommandBuffer,
                         VkSemaphore graphicsSemaphore,
                         VkSemaphore computeSemaphore) {
  VkPipelineStageFlags waitStageMask = VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT;

  // Submit compute commands
  VkSubmitInfo computeSubmitInfo = initializers::submitInfo();
  computeSubmitInfo.commandBufferCount = 1;
  computeSubmitInfo.pCommandBuffers = &computeCommandBuffer;
  computeSubmitInfo.waitSemaphoreCount = 1;
  computeSubmitInfo.pWaitSemaphores = &graphicsSemaphore;
  computeSubmitInfo.pWaitDstStageMask = &waitStageMask;
  computeSubmitInfo.signalSemaphoreCount = 1;
  computeSubmitInfo.pSignalSemaphores = &computeSemaphore;
  VK_CHECK_RESULT(vkQueueSubmit(queue, 1, &computeSubmitInfo, VK_NULL_HANDLE));
}

void submitGraphicsBuffer(VulkanInstance &vulkanInstance,
                          uint32_t &currentBuffer,
                          VkSemaphore graphicsSemaphore,
                          VkSemaphore computeSemaphore) {

  VK_CHECK_RESULT(vulkanInstance.swapChain.acquireNextImage(
      vulkanInstance.semaphores.presentComplete, &currentBuffer));

  VkPipelineStageFlags graphicsWaitStageMasks[] = {
      VK_PIPELINE_STAGE_VERTEX_INPUT_BIT,
      VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
  VkSemaphore graphicsWaitSemaphores[] = {
      computeSemaphore, vulkanInstance.semaphores.presentComplete};
  VkSemaphore graphicsSignalSemaphores[] = {
      graphicsSemaphore, vulkanInstance.semaphores.renderComplete};
  auto submitInfo = initializers::submitInfo();
  // Submit graphics commands
  submitInfo.commandBufferCount = 1;
  submitInfo.pCommandBuffers = &vulkanInstance.drawCmdBuffers[currentBuffer];
  submitInfo.waitSemaphoreCount = 2;
  submitInfo.pWaitSemaphores = graphicsWaitSemaphores;
  submitInfo.pWaitDstStageMask = graphicsWaitStageMasks;
  submitInfo.signalSemaphoreCount = 2;
  submitInfo.pSignalSemaphores = graphicsSignalSemaphores;
  VK_CHECK_RESULT(
      vkQueueSubmit(vulkanInstance.queue, 1, &submitInfo, VK_NULL_HANDLE));

  VK_CHECK_RESULT(vulkanInstance.swapChain.queuePresent(
      vulkanInstance.queue, currentBuffer,
      vulkanInstance.semaphores.renderComplete));
  VK_CHECK_RESULT(vkQueueWaitIdle(vulkanInstance.queue));
}

// submits compute-graphics semaphore synchronized command buffers
void submitBuffers(VulkanInstance &vulkanInstance,
                   VkCommandBuffer computeCommandBuffer,
                   VkSemaphore graphicsSemaphore,
                   VkSemaphore computeSemaphore) {
  submitComputeBuffer(vulkanInstance.computeQueue, computeCommandBuffer,
                      graphicsSemaphore, computeSemaphore);
  submitGraphicsBuffer(vulkanInstance, vulkanInstance.currentBuffer,
                       graphicsSemaphore, computeSemaphore);
}
} // namespace VkVP