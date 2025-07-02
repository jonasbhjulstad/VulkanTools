#ifndef NV_ASSETS_HPP
#define NV_ASSETS_HPP
#include <string>
#include <memory>
#include <VulkanTools/gltf/glTFModel.hpp>
#include <VulkanTools/gltf/Texture.hpp>

namespace VKT {
    
    auto loadModel(const std::string &modelPath, VulkanDevice *vulkanDevice, VkQueue queue) -> std::unique_ptr<vkglTF::Model>;
    auto loadTexture(const std::string &texturePath, VulkanDevice *vulkanDevice, VkQueue queue) -> std::unique_ptr<Texture2D>;
    
    auto loadShader(
        VkDevice device,
        const std::string& fileName,
        VkShaderStageFlagBits stage) -> VkPipelineShaderStageCreateInfo;
    
} // namespace VKT

#endif