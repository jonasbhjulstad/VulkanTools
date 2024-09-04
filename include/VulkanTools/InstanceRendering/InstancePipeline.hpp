#ifndef GLTF_BASIC_INSTANCE_PIPELINE_HPP
#define GLTF_BASIC_INSTANCE_PIPELINE_HPP
#include <vector>
#include <memory>
#include <vulkan/vulkan.hpp>
#include <VulkanTools/gltf/glTFModel.hpp>
#include <VulkanTools/Initializers.hpp>
#include <VulkanTools/Buffer.hpp>
#include <VulkanTools/Tools.hpp>
#include <VulkanTools/GLTF_Assets.hpp>
#include <VulkanTools/NodeInstance.hpp>


namespace VkVP
{
    enum InstanceBindIDs
    {
        GLTF_BIP_VERTEX_BIND_ID,
        GLTF_BIP_INSTANCE_BIND_ID
    };

    struct InstancePipelineData
    {
        std::shared_ptr<vkglTF::Model> model;
        std::shared_ptr<Texture2D> texture = nullptr;
        VulkanBuffer instanceBuffer;
        VkDescriptorSetLayout descriptorSetLayout;
        VkPipelineLayout pipelineLayout;
        VkDescriptorSet descriptorSet;
        VkPipeline pipeline;
        VkDeviceSize *offset;
        uint32_t N_instances = 0;
        VkDevice device;
        std::vector<VkPipelineShaderStageCreateInfo> shaderStages;

        InstancePipelineData(VkDevice _device) : device(_device)
        {
            shaderStages.reserve(2);
        }

        ~InstancePipelineData()
        {
            vkDestroyPipeline(device, pipeline, nullptr);
            vkDestroyPipelineLayout(device, pipelineLayout, nullptr);
            vkDestroyDescriptorSetLayout(device, descriptorSetLayout, nullptr);
            if (texture != nullptr)
            {
                texture->destroy();
            }

            for (auto &stage : shaderStages)
            {
                vkDestroyShaderModule(device, stage.module, nullptr);
            }
        }
    };

    struct InstanceRenderingParams
    {
        std::string vertexShaderPath;
        std::string fragmentShaderPath;
        std::string modelPath;
        std::string texturePath;
        VulkanDevice *vulkanDevice;
        VulkanBuffer *uniformProjectionBuffer;
        VkQueue queue;
        VkDescriptorPool descriptorPool;
        VkRenderPass renderPass;
        VkPipelineCache pipelineCache = nullptr;
        VkDeviceSize* offset;
        VkBufferUsageFlags bufferUsageFlags = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
        
    };

    template <typename InstanceData>
    VulkanBuffer prepareInstanceBuffer(std::vector<InstanceData> &instancePipelineData, VulkanDevice *vulkanDevice, VkQueue queue, VkMemoryPropertyFlags memPropFlags = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT)
    {
        VulkanBuffer instanceBuffer;
        uint32_t N_instances = static_cast<uint32_t>(instancePipelineData.size());
        instanceBuffer.size = N_instances * sizeof(InstanceData);

        struct
        {
            VkDeviceMemory memory;
            VkBuffer buffer;
        } stagingBuffer;

        VK_CHECK_RESULT(vulkanDevice->createBuffer(
            VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
            VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
            instanceBuffer.size,
            &stagingBuffer.buffer,
            &stagingBuffer.memory,
            instancePipelineData.data()));

        VK_CHECK_RESULT(vulkanDevice->createBuffer(
            memPropFlags | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
            VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
            instanceBuffer.size,
            &instanceBuffer.buffer,
            &instanceBuffer.memory));

        VkCommandBuffer copyCmd = vulkanDevice->createCommandBuffer(VK_COMMAND_BUFFER_LEVEL_PRIMARY, true);

        VkBufferCopy copyRegion = {};
        copyRegion.size = instanceBuffer.size;
        vkCmdCopyBuffer(
            copyCmd,
            stagingBuffer.buffer,
            instanceBuffer.buffer,
            1,
            &copyRegion);

        vulkanDevice->flushCommandBuffer(copyCmd, queue, true);

        instanceBuffer.descriptor.range = instanceBuffer.size;
        instanceBuffer.descriptor.buffer = instanceBuffer.buffer;
        instanceBuffer.descriptor.offset = 0;

        // Destroy staging resources
        vkDestroyBuffer(vulkanDevice->logicalDevice, stagingBuffer.buffer, nullptr);
        vkFreeMemory(vulkanDevice->logicalDevice, stagingBuffer.memory, nullptr);

        return instanceBuffer;
    }


    VkDescriptorSetLayout uniformDescriptorSetLayout(VkDevice device);

    VkDescriptorSetLayout textureDescriptorSetLayout(VkDevice device);

    VkPipelineLayout setupPipelineLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout);

    VkDescriptorSet setupDescriptorSets(VkDevice device,
                                        VkDescriptorSetLayout descriptorSetLayout,
                                        VkDescriptorPool descriptorPool,
                                        VulkanBuffer *uniformProjectionBuffer,
                                        Texture *texture);

    template <typename InstanceData>
    VkPipeline setupPipeline(const std::string &vertexShaderPath,
                             const std::string &fragmentShaderPath,
                             VkPipelineLayout pipelineLayout,
                             std::vector<VkPipelineShaderStageCreateInfo> &shaderStages,
                             VkDevice device,
                             VkRenderPass renderPass,
                             VkPipelineCache pipelineCache = VK_NULL_HANDLE)
    {
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyState = initializers::pipelineInputAssemblyStateCreateInfo(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST, 0, VK_FALSE);
        VkPipelineRasterizationStateCreateInfo rasterizationState = initializers::pipelineRasterizationStateCreateInfo(VK_POLYGON_MODE_FILL, VK_CULL_MODE_BACK_BIT, VK_FRONT_FACE_COUNTER_CLOCKWISE);
        VkPipelineColorBlendAttachmentState blendAttachmentState = initializers::pipelineColorBlendAttachmentState(0xf, VK_FALSE);
        VkPipelineColorBlendStateCreateInfo colorBlendState = initializers::pipelineColorBlendStateCreateInfo(1, &blendAttachmentState);
        VkPipelineDepthStencilStateCreateInfo depthStencilState = initializers::pipelineDepthStencilStateCreateInfo(VK_TRUE, VK_TRUE, VK_COMPARE_OP_LESS_OR_EQUAL);
        VkPipelineViewportStateCreateInfo viewportState = initializers::pipelineViewportStateCreateInfo(1, 1, 0);
        VkPipelineMultisampleStateCreateInfo multisampleState = initializers::pipelineMultisampleStateCreateInfo(VK_SAMPLE_COUNT_1_BIT);
        std::vector<VkDynamicState> dynamicStateEnables = {VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR};
        VkPipelineDynamicStateCreateInfo dynamicState = initializers::pipelineDynamicStateCreateInfo(dynamicStateEnables);

        VkGraphicsPipelineCreateInfo pipelineCI = initializers::pipelineCreateInfo(pipelineLayout, renderPass);
        pipelineCI.pInputAssemblyState = &inputAssemblyState;
        pipelineCI.pRasterizationState = &rasterizationState;
        pipelineCI.pColorBlendState = &colorBlendState;
        pipelineCI.pMultisampleState = &multisampleState;
        pipelineCI.pViewportState = &viewportState;
        pipelineCI.pDepthStencilState = &depthStencilState;
        pipelineCI.pDynamicState = &dynamicState;
        pipelineCI.stageCount = static_cast<uint32_t>(2);
        pipelineCI.pStages = shaderStages.data();

        // Vertex input bindings
        // The instancing pipeline uses a vertex input state with two bindings
        std::vector<VkVertexInputBindingDescription> bindingDescriptions = {
            // Binding point 0: Mesh vertex layout description at per-vertex rate
            initializers::vertexInputBindingDescription(GLTF_BIP_VERTEX_BIND_ID, sizeof(vkglTF::Vertex), VK_VERTEX_INPUT_RATE_VERTEX),
            // Binding point 1: Instanced data at per-instance rate
            initializers::vertexInputBindingDescription(GLTF_BIP_INSTANCE_BIND_ID, sizeof(InstanceData), VK_VERTEX_INPUT_RATE_INSTANCE)};

        std::vector<VkVertexInputAttributeDescription> attributeDescriptions = {
            initializers::vertexInputAttributeDescription(GLTF_BIP_VERTEX_BIND_ID, 0, VK_FORMAT_R32G32B32_SFLOAT, 0),                 // Location 0: Position
            initializers::vertexInputAttributeDescription(GLTF_BIP_VERTEX_BIND_ID, 1, VK_FORMAT_R32G32B32_SFLOAT, sizeof(float) * 3), // Location 1: Normal
            initializers::vertexInputAttributeDescription(GLTF_BIP_VERTEX_BIND_ID, 2, VK_FORMAT_R32G32_SFLOAT, sizeof(float) * 6),    // Location 2: Texture coordinates
            initializers::vertexInputAttributeDescription(GLTF_BIP_VERTEX_BIND_ID, 3, VK_FORMAT_R32G32B32_SFLOAT, sizeof(float) * 8), // Location 3: Color
        };

        std::vector<VkVertexInputAttributeDescription> instancePipelineDataDescriptions = InstanceData::getAttributeDescriptions(GLTF_BIP_INSTANCE_BIND_ID, 4);

        attributeDescriptions.insert(attributeDescriptions.end(), instancePipelineDataDescriptions.begin(), instancePipelineDataDescriptions.end());
        VkPipelineVertexInputStateCreateInfo inputState = initializers::pipelineVertexInputStateCreateInfo();
        inputState.pVertexBindingDescriptions = bindingDescriptions.data();
        inputState.pVertexAttributeDescriptions = attributeDescriptions.data();

        inputState.vertexBindingDescriptionCount = static_cast<uint32_t>(bindingDescriptions.size());
        inputState.vertexAttributeDescriptionCount = static_cast<uint32_t>(attributeDescriptions.size());
        pipelineCI.pVertexInputState = &inputState;

        shaderStages.push_back(loadShader(device, vertexShaderPath, VK_SHADER_STAGE_VERTEX_BIT));
        shaderStages.push_back(loadShader(device, fragmentShaderPath, VK_SHADER_STAGE_FRAGMENT_BIT));

        VkPipeline pipeline;
        VK_CHECK_RESULT(vkCreateGraphicsPipelines(device, nullptr, 1, &pipelineCI, nullptr, &pipeline));
        return pipeline;
    }

    void buildCommandBuffer(InstancePipelineData &instancePipelineData, VkCommandBuffer commandBuffer);

    template <typename InstanceData>
    std::unique_ptr<InstancePipelineData> prepareInstanceRendering(InstanceRenderingParams &p, std::vector<InstanceData>& instanceData)
    {

        VkDevice device = p.vulkanDevice->logicalDevice;

        std::unique_ptr<InstancePipelineData> instancePipelineData = std::make_unique<InstancePipelineData>(device);

        instancePipelineData->model = loadModel(p.modelPath, p.vulkanDevice, p.queue);
        instancePipelineData->instanceBuffer = prepareInstanceBuffer(instanceData, p.vulkanDevice, p.queue, p.bufferUsageFlags);
        if (!p.texturePath.empty())
        {
            instancePipelineData->texture = loadTexture(p.texturePath, p.vulkanDevice, p.queue);
            instancePipelineData->descriptorSetLayout = textureDescriptorSetLayout(device);
        }
        else
        {
            instancePipelineData->descriptorSetLayout = uniformDescriptorSetLayout(device);
        }
        instancePipelineData->pipelineLayout = setupPipelineLayout(device, instancePipelineData->descriptorSetLayout);
        instancePipelineData->descriptorSet = setupDescriptorSets(device, instancePipelineData->descriptorSetLayout, p.descriptorPool, p.uniformProjectionBuffer, nullptr);
        instancePipelineData->pipeline = setupPipeline<InstanceData>(p.vertexShaderPath, p.fragmentShaderPath, instancePipelineData->pipelineLayout, instancePipelineData->shaderStages, device, p.renderPass, p.pipelineCache);
        instancePipelineData->offset = p.offset;
        instancePipelineData->N_instances = instanceData.size();

        return instancePipelineData;
    }




}
#endif