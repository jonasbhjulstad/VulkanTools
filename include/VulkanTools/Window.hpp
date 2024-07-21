#ifndef Vulkan_WINDOW_HPP
#define Vulkan_WINDOW_HPP
#include <GLFW/glfw3.h>
#include <VulkanTools/Camera.hpp>
#include <VulkanTools/Initializers.hpp>
#include <VulkanTools/Instance.hpp>
#include <VulkanTools/PipelineInitializers.hpp>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_vulkan.h>
#include <vulkan/vulkan.hpp>

void setupGLFWVulkanWindow(VulkanInstance &vulkanInstance, int width,
                           int height, uint32_t minImageCount = 2);

void recreateWindow(VulkanInstance &vulkanInstance, Camera &camera, int width,
                    int height);
void cleanupGLFWVulkanWindow(VkInstance instance, VkDevice device,
                             ImGui_ImplVulkanH_Window *wd);

bool getFrameBufferSizeChange(GLFWwindow *window, uint32_t &width,
                              uint32_t &height);

#endif // Vulkan_WINDOW_HPP