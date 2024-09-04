#ifndef NV_ASSETS_HPP
#define NV_ASSETS_HPP
#include <string>
#include <memory>
#include <VulkanTools/gltf/glTFModel.hpp>
#include <VulkanTools/gltf/Texture.hpp>


std::unique_ptr<vkglTF::Model> loadModel(const std::string &modelPath, VulkanDevice *vulkanDevice, VkQueue queue);
std::unique_ptr<Texture2D> loadTexture(const std::string &texturePath, VulkanDevice *vulkanDevice, VkQueue queue);

VkPipelineShaderStageCreateInfo loadShader(
    VkDevice device,
    std::string fileName,
    VkShaderStageFlagBits stage);


#endif