#ifndef Vulkan_WINDOW_HPP
#define Vulkan_WINDOW_HPP
#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_vulkan.h>
#include <imgui/imgui_impl_glfw.h>
#include <VulkanTools/Instance.hpp>
#include <VulkanTools/PipelineInitializers.hpp>
#include <VulkanTools/Initializers.hpp>


namespace VKT {
    
    void setupGLFWVulkanWindow(
                           VulkanInstance &vulkanInstance,
                           int width,
                           int height,
                           uint32_t minImageCount = 2);
    void cleanupGLFWVulkanWindow(VkInstance instance, VkDevice device, ImGui_ImplVulkanH_Window *wd);
    
} // namespace VKT
#endif // Vulkan_WINDOW_HPP