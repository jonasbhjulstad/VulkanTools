#include <VulkanTools/Window.hpp>
#include <exception>
void setupGLFWVulkanWindow(VulkanInstance &vulkanInstance,
						   int width,
						   int height,
						   uint32_t minImageCount)
{

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  vulkanInstance.glfwWindow =
      glfwCreateWindow(width, height, "ParticleCompute", nullptr, nullptr);

  if (!glfwVulkanSupported()) {
    throw std::runtime_error("GLFW: Vulkan Not Supported\n");
  }
  uint32_t extensions_count = 0;
  const char **extensions =
      glfwGetRequiredInstanceExtensions(&extensions_count);
  for (int i = 0; i < extensions_count; i++) {
    vulkanInstance.enabledInstanceExtensions.push_back(extensions[i]);
  }

	ImGui_ImplVulkanH_Window *wd = &vulkanInstance.ImGuiWindow;
	wd->Swapchain = vulkanInstance.swapChain.swapChain;
	wd->Surface = vulkanInstance.surface;
	VkPhysicalDevice physicalDevice = vulkanInstance.vulkanDevice->physicalDevice;
	VkDevice logicalDevice = vulkanInstance.vulkanDevice->logicalDevice;
	uint32_t queueFamily = vulkanInstance.vulkanDevice->queueFamilyIndices.graphics;
	// Check for WSI support
	VkBool32 res;
	vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamily, wd->Surface, &res);
	if (res != VK_TRUE)
	{
		fprintf(stderr, "Error no WSI support on physical device 0\n");
		exit(-1);
	}

	// Select Surface Format
	const VkFormat requestSurfaceImageFormat[] = {VK_FORMAT_B8G8R8A8_UNORM, VK_FORMAT_R8G8B8A8_UNORM, VK_FORMAT_B8G8R8_UNORM, VK_FORMAT_R8G8B8_UNORM};
	const VkColorSpaceKHR requestSurfaceColorSpace = VK_COLORSPACE_SRGB_NONLINEAR_KHR;
	wd->SurfaceFormat = ImGui_ImplVulkanH_SelectSurfaceFormat(physicalDevice, wd->Surface, requestSurfaceImageFormat, (size_t)IM_ARRAYSIZE(requestSurfaceImageFormat), requestSurfaceColorSpace);

	VkPresentModeKHR present_modes[] = {VK_PRESENT_MODE_FIFO_KHR};
	wd->PresentMode = ImGui_ImplVulkanH_SelectPresentMode(physicalDevice, wd->Surface, &present_modes[0], IM_ARRAYSIZE(present_modes));

	ImGui_ImplVulkanH_CreateOrResizeWindow(vulkanInstance.instance, physicalDevice, logicalDevice, wd, queueFamily, NULL, width, height, minImageCount);
}


void recreateWindow(
    VulkanInstance &vulkanInstance, Camera &camera, int width, int height) {
  VkDevice logicalDevice = vulkanInstance.vulkanDevice->logicalDevice;
  // Ensure all operations on the device have been finished before destroying
  // resources
  vkDeviceWaitIdle(logicalDevice);
  vulkanInstance.swapChain.create(&vulkanInstance.ImGuiWindow,
                                  (uint32_t *)&width, (uint32_t *)&height,
                                  false);
  vulkanInstance.ImGuiWindow.Swapchain = vulkanInstance.swapChain.swapChain;
  // Recreate the frame buffersqueuePresent
  vkDestroyImageView(logicalDevice, vulkanInstance.depthStencil.view, nullptr);
  vkDestroyImage(logicalDevice, vulkanInstance.depthStencil.image, nullptr);
  vkFreeMemory(logicalDevice, vulkanInstance.depthStencil.mem, nullptr);
  initializers::setupDepthStencil(vulkanInstance, width, height);
  for (uint32_t i = 0; i < vulkanInstance.frameBuffers.size(); i++) {
    vkDestroyFramebuffer(logicalDevice, vulkanInstance.frameBuffers[i],
                         nullptr);
  }
  initializers::setupFrameBuffer(
      logicalDevice, vulkanInstance.renderPass, width, height,
      vulkanInstance.depthStencil.view, vulkanInstance.swapChain,
      vulkanInstance.frameBuffers);

  // Command buffers need to be recreated as they may store
  // references to the recreated frame buffer
  initializers::destroyCommandBuffers(logicalDevice,
                                      vulkanInstance.vulkanDevice->commandPool,
                                      vulkanInstance.drawCmdBuffers);
  initializers::createCommandBuffers(
      logicalDevice, vulkanInstance.drawCmdBuffers, vulkanInstance.swapChain,
      vulkanInstance.vulkanDevice->commandPool);

  vkDeviceWaitIdle(logicalDevice);

  if ((width > 0.0f) && (height > 0.0f)) {
    camera.updateAspectRatio((float)width / (float)height);
  }
}

void cleanupGLFWVulkanWindow(VkInstance instance, VkDevice device, ImGui_ImplVulkanH_Window *wd)
{
	ImGui_ImplVulkanH_DestroyWindow(instance, device, wd, NULL);
}


bool getFrameBufferSizeChange(GLFWwindow *window, uint32_t &width,
                              uint32_t &height) {

  int w_new, h_new;
  glfwGetFramebufferSize(window, &w_new, &h_new);

  if (w_new != width || h_new != height) {
    width = w_new;
    height = h_new;
    return true;
  }
  return false;
}

static void recreateWindowBuffers(VulkanInstance &vulkanInstance,
                                  uint32_t width, uint32_t height) {
  auto &logicalDevice = vulkanInstance.vulkanDevice->logicalDevice;
  // Recreate the frame buffersqueuePresent
  vkDestroyImageView(logicalDevice, vulkanInstance.depthStencil.view, nullptr);
  vkDestroyImage(logicalDevice, vulkanInstance.depthStencil.image, nullptr);
  vkFreeMemory(logicalDevice, vulkanInstance.depthStencil.mem, nullptr);
  initializers::setupDepthStencil(vulkanInstance, width, height);
  for (uint32_t i = 0; i < vulkanInstance.frameBuffers.size(); i++) {
    vkDestroyFramebuffer(logicalDevice, vulkanInstance.frameBuffers[i],
                         nullptr);
  }
  initializers::setupFrameBuffer(
      logicalDevice, vulkanInstance.renderPass, width, height,
      vulkanInstance.depthStencil.view, vulkanInstance.swapChain,
      vulkanInstance.frameBuffers);

  // Command buffers need to be recreated as they may store
  // references to the recreated frame buffer
  initializers::destroyCommandBuffers(logicalDevice,
                                      vulkanInstance.vulkanDevice->commandPool,
                                      vulkanInstance.drawCmdBuffers);
  initializers::createCommandBuffers(
      logicalDevice, vulkanInstance.drawCmdBuffers, vulkanInstance.swapChain,
      vulkanInstance.vulkanDevice->commandPool);
}

void resizeImGuiWindow(VulkanInstance &vulkanInstance, uint32_t width,
                       uint32_t height) {

  // Imgui global variables
  ImGui_ImplVulkan_SetMinImageCount(vulkanInstance.swapChain.imageCount);
  ImGui_ImplVulkanH_CreateOrResizeWindow(
      vulkanInstance.instance, vulkanInstance.vulkanDevice->physicalDevice,
      vulkanInstance.vulkanDevice->logicalDevice, &vulkanInstance.ImGuiWindow,
      vulkanInstance.vulkanDevice->queueFamilyIndices.graphics, nullptr, width,
      height, vulkanInstance.swapChain.imageCount);
  vulkanInstance.ImGuiWindow.FrameIndex = 0;

  // VulkanInstance-related variables
  vkDeviceWaitIdle(vulkanInstance.vulkanDevice->logicalDevice);
  vulkanInstance.swapChain.create(&vulkanInstance.ImGuiWindow,
                                  (uint32_t *)&width, (uint32_t *)&height,
                                  false);
  vulkanInstance.ImGuiWindow.Swapchain = vulkanInstance.swapChain.swapChain;

  recreateWindowBuffers(vulkanInstance, width, height);
}