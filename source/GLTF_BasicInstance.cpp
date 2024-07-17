#include <VulkanTools/GLTF_BasicInstance.hpp>
namespace glTFBasicInstance
{
    template <>
    std::unique_ptr<InstancePipelineData> prepareInstanceRendering<NodeInstanceData>(InstanceRenderingParams &p, std::vector<NodeInstanceData> & instanceData);

    template <>
    VulkanBuffer prepareInstanceBuffer(std::vector<NodeInstanceData> &instanceData, VulkanDevice *vulkanDevice, VkQueue queue);


    template <>
    VkPipeline setupPipeline<NodeInstanceData>(const std::string &vertexShaderPath,
                                               const std::string &fragmentShaderPath,
                                               VkPipelineLayout pipelineLayout,
                                               std::vector<VkPipelineShaderStageCreateInfo> &shaderStages,
                                               VkDevice device,
                                               VkRenderPass renderPass,
                                               VkPipelineCache pipelineCache);
}