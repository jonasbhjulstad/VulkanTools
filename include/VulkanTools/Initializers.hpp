/*
* Initializers for Vulkan structures and objects used by the examples
* Saves lot of VK_STRUCTURE_TYPE assignments
* Some initializers are parameterized for convenience
*
* Copyright (C) 2016 by Sascha Willems - www.saschawillems.de
*
* This code is licensed under the MIT license (MIT) (http://opensource.org/licenses/MIT)
*/

#ifndef Vulkan_INITIALIZERS_HPP

#define Vulkan_INITIALIZERS_HPP
#include <vector>
#include <vulkan/vulkan.hpp>

namespace initializers
{

	inline constexpr auto memoryAllocateInfo() -> VkMemoryAllocateInfo
	{
		VkMemoryAllocateInfo memAllocInfo{};
		memAllocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
		return memAllocInfo;
	}

	inline constexpr auto mappedMemoryRange() -> VkMappedMemoryRange
	{
		VkMappedMemoryRange mappedMemoryRange{};
		mappedMemoryRange.sType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE;
		return mappedMemoryRange;
	}

	inline constexpr auto commandBufferAllocateInfo(
		VkCommandPool commandPool,
		VkCommandBufferLevel level,
		uint32_t bufferCount) -> VkCommandBufferAllocateInfo
	{
		VkCommandBufferAllocateInfo commandBufferAllocateInfo{};
		commandBufferAllocateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		commandBufferAllocateInfo.commandPool = commandPool;
		commandBufferAllocateInfo.level = level;
		commandBufferAllocateInfo.commandBufferCount = bufferCount;
		return commandBufferAllocateInfo;
	}

	inline constexpr auto commandPoolCreateInfo() -> VkCommandPoolCreateInfo
	{
		VkCommandPoolCreateInfo cmdPoolCreateInfo{};
		cmdPoolCreateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
		return cmdPoolCreateInfo;
	}

	inline constexpr auto commandBufferBeginInfo() -> VkCommandBufferBeginInfo
	{
		VkCommandBufferBeginInfo cmdBufferBeginInfo{};
		cmdBufferBeginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
		return cmdBufferBeginInfo;
	}

	inline constexpr auto commandBufferInheritanceInfo() -> VkCommandBufferInheritanceInfo
	{
		VkCommandBufferInheritanceInfo cmdBufferInheritanceInfo{};
		cmdBufferInheritanceInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO;
		return cmdBufferInheritanceInfo;
	}

	inline constexpr auto renderPassBeginInfo() -> VkRenderPassBeginInfo
	{
		VkRenderPassBeginInfo renderPassBeginInfo{};
		renderPassBeginInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
		return renderPassBeginInfo;
	}

	inline constexpr auto renderPassCreateInfo() -> VkRenderPassCreateInfo
	{
		VkRenderPassCreateInfo renderPassCreateInfo{};
		renderPassCreateInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
		return renderPassCreateInfo;
	}

	/** @brief Initialize an image memory barrier with no image transfer ownership */
	inline constexpr auto imageMemoryBarrier() -> VkImageMemoryBarrier
	{
		VkImageMemoryBarrier imageMemoryBarrier{};
		imageMemoryBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
		imageMemoryBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
		imageMemoryBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
		return imageMemoryBarrier;
	}

	/** @brief Initialize a buffer memory barrier with no image transfer ownership */
	inline constexpr auto bufferMemoryBarrier() -> VkBufferMemoryBarrier
	{
		VkBufferMemoryBarrier bufferMemoryBarrier{};
		bufferMemoryBarrier.sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
		bufferMemoryBarrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
		bufferMemoryBarrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
		return bufferMemoryBarrier;
	}

	inline constexpr auto memoryBarrier() -> VkMemoryBarrier
	{
		VkMemoryBarrier memoryBarrier{};
		memoryBarrier.sType = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
		return memoryBarrier;
	}

	inline constexpr auto imageCreateInfo() -> VkImageCreateInfo
	{
		VkImageCreateInfo imageCreateInfo{};
		imageCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
		return imageCreateInfo;
	}

	inline constexpr auto samplerCreateInfo() -> VkSamplerCreateInfo
	{
		VkSamplerCreateInfo samplerCreateInfo{};
		samplerCreateInfo.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
		samplerCreateInfo.maxAnisotropy = 1.0f;
		return samplerCreateInfo;
	}

	inline constexpr auto imageViewCreateInfo() -> VkImageViewCreateInfo
	{
		VkImageViewCreateInfo imageViewCreateInfo{};
		imageViewCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
		return imageViewCreateInfo;
	}

	inline constexpr auto framebufferCreateInfo() -> VkFramebufferCreateInfo
	{
		VkFramebufferCreateInfo framebufferCreateInfo{};
		framebufferCreateInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
		return framebufferCreateInfo;
	}

	inline constexpr auto semaphoreCreateInfo() -> VkSemaphoreCreateInfo
	{
		VkSemaphoreCreateInfo semaphoreCreateInfo{};
		semaphoreCreateInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
		return semaphoreCreateInfo;
	}

	inline constexpr auto fenceCreateInfo(VkFenceCreateFlags flags = 0) -> VkFenceCreateInfo
	{
		VkFenceCreateInfo fenceCreateInfo{};
		fenceCreateInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
		fenceCreateInfo.flags = flags;
		return fenceCreateInfo;
	}

	inline constexpr auto eventCreateInfo() -> VkEventCreateInfo
	{
		VkEventCreateInfo eventCreateInfo{};
		eventCreateInfo.sType = VK_STRUCTURE_TYPE_EVENT_CREATE_INFO;
		return eventCreateInfo;
	}

	inline constexpr auto submitInfo() -> VkSubmitInfo
	{
		VkSubmitInfo submitInfo{};
		submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		return submitInfo;
	}

	inline constexpr auto viewport(
		float width,
		float height,
		float minDepth,
		float maxDepth) -> VkViewport
	{
		VkViewport viewport{};
		viewport.width = width;
		viewport.height = height;
		viewport.minDepth = minDepth;
		viewport.maxDepth = maxDepth;
		return viewport;
	}

	inline constexpr auto rect2D(
		int32_t width,
		int32_t height,
		int32_t offsetX,
		int32_t offsetY) -> VkRect2D
	{
		VkRect2D rect2D{};
		rect2D.extent.width = width;
		rect2D.extent.height = height;
		rect2D.offset.x = offsetX;
		rect2D.offset.y = offsetY;
		return rect2D;
	}

	inline constexpr auto bufferCreateInfo() -> VkBufferCreateInfo
	{
		VkBufferCreateInfo bufCreateInfo{};
		bufCreateInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		return bufCreateInfo;
	}

	inline constexpr auto bufferCreateInfo(
		VkBufferUsageFlags usage,
		VkDeviceSize size) -> VkBufferCreateInfo
	{
		VkBufferCreateInfo bufCreateInfo{};
		bufCreateInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		bufCreateInfo.usage = usage;
		bufCreateInfo.size = size;
		return bufCreateInfo;
	}

	inline constexpr auto descriptorPoolCreateInfo(
		uint32_t poolSizeCount,
		VkDescriptorPoolSize *pPoolSizes,
		uint32_t maxSets) -> VkDescriptorPoolCreateInfo
	{
		VkDescriptorPoolCreateInfo descriptorPoolInfo{};
		descriptorPoolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
		descriptorPoolInfo.poolSizeCount = poolSizeCount;
		descriptorPoolInfo.pPoolSizes = pPoolSizes;
		descriptorPoolInfo.maxSets = maxSets;
		return descriptorPoolInfo;
	}

	inline auto descriptorPoolCreateInfo(
		const std::vector<VkDescriptorPoolSize> &poolSizes,
		uint32_t maxSets) -> VkDescriptorPoolCreateInfo
	{
		VkDescriptorPoolCreateInfo descriptorPoolInfo{};
		descriptorPoolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
		descriptorPoolInfo.poolSizeCount = static_cast<uint32_t>(poolSizes.size());
		descriptorPoolInfo.pPoolSizes = poolSizes.data();
		descriptorPoolInfo.maxSets = maxSets;
		return descriptorPoolInfo;
	}

	inline constexpr auto descriptorPoolSize(
		VkDescriptorType type,
		uint32_t descriptorCount) -> VkDescriptorPoolSize
	{
		VkDescriptorPoolSize descriptorPoolSize{};
		descriptorPoolSize.type = type;
		descriptorPoolSize.descriptorCount = descriptorCount;
		return descriptorPoolSize;
	}

	inline constexpr auto descriptorSetLayoutBinding(
		VkDescriptorType type,
		VkShaderStageFlags stageFlags,
		uint32_t binding,
		uint32_t descriptorCount = 1) -> VkDescriptorSetLayoutBinding
	{
		VkDescriptorSetLayoutBinding setLayoutBinding{};
		setLayoutBinding.descriptorType = type;
		setLayoutBinding.stageFlags = stageFlags;
		setLayoutBinding.binding = binding;
		setLayoutBinding.descriptorCount = descriptorCount;
		return setLayoutBinding;
	}

	inline constexpr auto descriptorSetLayoutCreateInfo(
		const VkDescriptorSetLayoutBinding *pBindings,
		uint32_t bindingCount) -> VkDescriptorSetLayoutCreateInfo
	{
		VkDescriptorSetLayoutCreateInfo descriptorSetLayoutCreateInfo{};
		descriptorSetLayoutCreateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
		descriptorSetLayoutCreateInfo.pBindings = pBindings;
		descriptorSetLayoutCreateInfo.bindingCount = bindingCount;
		return descriptorSetLayoutCreateInfo;
	}

	inline auto descriptorSetLayoutCreateInfo(
		const std::vector<VkDescriptorSetLayoutBinding> &bindings) -> VkDescriptorSetLayoutCreateInfo
	{
		VkDescriptorSetLayoutCreateInfo descriptorSetLayoutCreateInfo{};
		descriptorSetLayoutCreateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
		descriptorSetLayoutCreateInfo.pBindings = bindings.data();
		descriptorSetLayoutCreateInfo.bindingCount = static_cast<uint32_t>(bindings.size());
		return descriptorSetLayoutCreateInfo;
	}

	inline constexpr auto pipelineLayoutCreateInfo(
		const VkDescriptorSetLayout *pSetLayouts,
		uint32_t setLayoutCount = 1) -> VkPipelineLayoutCreateInfo
	{
		VkPipelineLayoutCreateInfo pipelineLayoutCreateInfo{};
		pipelineLayoutCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutCreateInfo.setLayoutCount = setLayoutCount;
		pipelineLayoutCreateInfo.pSetLayouts = pSetLayouts;
		return pipelineLayoutCreateInfo;
	}

	inline constexpr auto pipelineLayoutCreateInfo(
		uint32_t setLayoutCount = 1) -> VkPipelineLayoutCreateInfo
	{
		VkPipelineLayoutCreateInfo pipelineLayoutCreateInfo{};
		pipelineLayoutCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutCreateInfo.setLayoutCount = setLayoutCount;
		return pipelineLayoutCreateInfo;
	}

	inline constexpr auto descriptorSetAllocateInfo(
		VkDescriptorPool descriptorPool,
		const VkDescriptorSetLayout *pSetLayouts,
		uint32_t descriptorSetCount) -> VkDescriptorSetAllocateInfo
	{
		VkDescriptorSetAllocateInfo descriptorSetAllocateInfo{};
		descriptorSetAllocateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
		descriptorSetAllocateInfo.descriptorPool = descriptorPool;
		descriptorSetAllocateInfo.pSetLayouts = pSetLayouts;
		descriptorSetAllocateInfo.descriptorSetCount = descriptorSetCount;
		return descriptorSetAllocateInfo;
	}

	inline constexpr auto descriptorImageInfo(VkSampler sampler, VkImageView imageView, VkImageLayout imageLayout) -> VkDescriptorImageInfo
	{
		VkDescriptorImageInfo descriptorImageInfo{};
		descriptorImageInfo.sampler = sampler;
		descriptorImageInfo.imageView = imageView;
		descriptorImageInfo.imageLayout = imageLayout;
		return descriptorImageInfo;
	}

	inline constexpr auto writeDescriptorSet(
		VkDescriptorSet dstSet,
		VkDescriptorType type,
		uint32_t binding,
		VkDescriptorBufferInfo *bufferInfo,
		uint32_t descriptorCount = 1) -> VkWriteDescriptorSet
	{
		VkWriteDescriptorSet writeDescriptorSet{};
		writeDescriptorSet.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		writeDescriptorSet.dstSet = dstSet;
		writeDescriptorSet.descriptorType = type;
		writeDescriptorSet.dstBinding = binding;
		writeDescriptorSet.pBufferInfo = bufferInfo;
		writeDescriptorSet.descriptorCount = descriptorCount;
		return writeDescriptorSet;
	}

	inline constexpr auto writeDescriptorSet(
		VkDescriptorSet dstSet,
		VkDescriptorType type,
		uint32_t binding,
		VkDescriptorImageInfo *imageInfo,
		uint32_t descriptorCount = 1) -> VkWriteDescriptorSet
	{
		VkWriteDescriptorSet writeDescriptorSet{};
		writeDescriptorSet.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		writeDescriptorSet.dstSet = dstSet;
		writeDescriptorSet.descriptorType = type;
		writeDescriptorSet.dstBinding = binding;
		writeDescriptorSet.pImageInfo = imageInfo;
		writeDescriptorSet.descriptorCount = descriptorCount;
		return writeDescriptorSet;
	}

	inline constexpr auto vertexInputBindingDescription(
		uint32_t binding,
		uint32_t stride,
		VkVertexInputRate inputRate) -> VkVertexInputBindingDescription
	{
		VkVertexInputBindingDescription vInputBindDescription{};
		vInputBindDescription.binding = binding;
		vInputBindDescription.stride = stride;
		vInputBindDescription.inputRate = inputRate;
		return vInputBindDescription;
	}

	inline constexpr auto vertexInputAttributeDescription(
		uint32_t binding,
		uint32_t location,
		VkFormat format,
		uint32_t offset) -> VkVertexInputAttributeDescription
	{
		VkVertexInputAttributeDescription vInputAttribDescription{};
		vInputAttribDescription.location = location;
		vInputAttribDescription.binding = binding;
		vInputAttribDescription.format = format;
		vInputAttribDescription.offset = offset;
		return vInputAttribDescription;
	}

	inline constexpr auto pipelineVertexInputStateCreateInfo() -> VkPipelineVertexInputStateCreateInfo
	{
		VkPipelineVertexInputStateCreateInfo pipelineVertexInputStateCreateInfo{};
		pipelineVertexInputStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
		return pipelineVertexInputStateCreateInfo;
	}

	inline auto pipelineVertexInputStateCreateInfo(
		const std::vector<VkVertexInputBindingDescription> &vertexBindingDescriptions,
		const std::vector<VkVertexInputAttributeDescription> &vertexAttributeDescriptions) -> VkPipelineVertexInputStateCreateInfo
	{
		VkPipelineVertexInputStateCreateInfo pipelineVertexInputStateCreateInfo{};
		pipelineVertexInputStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
		pipelineVertexInputStateCreateInfo.vertexBindingDescriptionCount = static_cast<uint32_t>(vertexBindingDescriptions.size());
		pipelineVertexInputStateCreateInfo.pVertexBindingDescriptions = vertexBindingDescriptions.data();
		pipelineVertexInputStateCreateInfo.vertexAttributeDescriptionCount = static_cast<uint32_t>(vertexAttributeDescriptions.size());
		pipelineVertexInputStateCreateInfo.pVertexAttributeDescriptions = vertexAttributeDescriptions.data();
		return pipelineVertexInputStateCreateInfo;
	}

	inline constexpr auto pipelineInputAssemblyStateCreateInfo(
		VkPrimitiveTopology topology,
		VkPipelineInputAssemblyStateCreateFlags flags,
		VkBool32 primitiveRestartEnable) -> VkPipelineInputAssemblyStateCreateInfo
	{
		VkPipelineInputAssemblyStateCreateInfo pipelineInputAssemblyStateCreateInfo{};
		pipelineInputAssemblyStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		pipelineInputAssemblyStateCreateInfo.topology = topology;
		pipelineInputAssemblyStateCreateInfo.flags = flags;
		pipelineInputAssemblyStateCreateInfo.primitiveRestartEnable = primitiveRestartEnable;
		return pipelineInputAssemblyStateCreateInfo;
	}

	inline constexpr auto pipelineRasterizationStateCreateInfo(
		VkPolygonMode polygonMode,
		VkCullModeFlags cullMode,
		VkFrontFace frontFace,
		VkPipelineRasterizationStateCreateFlags flags = 0) -> VkPipelineRasterizationStateCreateInfo
	{
		VkPipelineRasterizationStateCreateInfo pipelineRasterizationStateCreateInfo{};
		pipelineRasterizationStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
		pipelineRasterizationStateCreateInfo.polygonMode = polygonMode;
		pipelineRasterizationStateCreateInfo.cullMode = cullMode;
		pipelineRasterizationStateCreateInfo.frontFace = frontFace;
		pipelineRasterizationStateCreateInfo.flags = flags;
		pipelineRasterizationStateCreateInfo.depthClampEnable = VK_FALSE;
		pipelineRasterizationStateCreateInfo.lineWidth = 1.0f;
		return pipelineRasterizationStateCreateInfo;
	}

	inline constexpr auto pipelineColorBlendAttachmentState(
		VkColorComponentFlags colorWriteMask,
		VkBool32 blendEnable) -> VkPipelineColorBlendAttachmentState
	{
		VkPipelineColorBlendAttachmentState pipelineColorBlendAttachmentState{};
		pipelineColorBlendAttachmentState.colorWriteMask = colorWriteMask;
		pipelineColorBlendAttachmentState.blendEnable = blendEnable;
		return pipelineColorBlendAttachmentState;
	}

	inline constexpr auto pipelineColorBlendStateCreateInfo(
		uint32_t attachmentCount,
		const VkPipelineColorBlendAttachmentState *pAttachments) -> VkPipelineColorBlendStateCreateInfo
	{
		VkPipelineColorBlendStateCreateInfo pipelineColorBlendStateCreateInfo{};
		pipelineColorBlendStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
		pipelineColorBlendStateCreateInfo.attachmentCount = attachmentCount;
		pipelineColorBlendStateCreateInfo.pAttachments = pAttachments;
		return pipelineColorBlendStateCreateInfo;
	}

	inline constexpr auto pipelineDepthStencilStateCreateInfo(
		VkBool32 depthTestEnable,
		VkBool32 depthWriteEnable,
		VkCompareOp depthCompareOp) -> VkPipelineDepthStencilStateCreateInfo
	{
		VkPipelineDepthStencilStateCreateInfo pipelineDepthStencilStateCreateInfo{};
		pipelineDepthStencilStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
		pipelineDepthStencilStateCreateInfo.depthTestEnable = depthTestEnable;
		pipelineDepthStencilStateCreateInfo.depthWriteEnable = depthWriteEnable;
		pipelineDepthStencilStateCreateInfo.depthCompareOp = depthCompareOp;
		pipelineDepthStencilStateCreateInfo.back.compareOp = VK_COMPARE_OP_ALWAYS;
		return pipelineDepthStencilStateCreateInfo;
	}

	inline constexpr auto pipelineViewportStateCreateInfo(
		uint32_t viewportCount,
		uint32_t scissorCount,
		VkPipelineViewportStateCreateFlags flags = 0) -> VkPipelineViewportStateCreateInfo
	{
		VkPipelineViewportStateCreateInfo pipelineViewportStateCreateInfo{};
		pipelineViewportStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
		pipelineViewportStateCreateInfo.viewportCount = viewportCount;
		pipelineViewportStateCreateInfo.scissorCount = scissorCount;
		pipelineViewportStateCreateInfo.flags = flags;
		return pipelineViewportStateCreateInfo;
	}

	inline constexpr auto pipelineMultisampleStateCreateInfo(
		VkSampleCountFlagBits rasterizationSamples,
		VkPipelineMultisampleStateCreateFlags flags = 0) -> VkPipelineMultisampleStateCreateInfo
	{
		VkPipelineMultisampleStateCreateInfo pipelineMultisampleStateCreateInfo{};
		pipelineMultisampleStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
		pipelineMultisampleStateCreateInfo.rasterizationSamples = rasterizationSamples;
		pipelineMultisampleStateCreateInfo.flags = flags;
		return pipelineMultisampleStateCreateInfo;
	}

	inline constexpr auto pipelineDynamicStateCreateInfo(
		const VkDynamicState *pDynamicStates,
		uint32_t dynamicStateCount,
		VkPipelineDynamicStateCreateFlags flags = 0) -> VkPipelineDynamicStateCreateInfo
	{
		VkPipelineDynamicStateCreateInfo pipelineDynamicStateCreateInfo{};
		pipelineDynamicStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
		pipelineDynamicStateCreateInfo.pDynamicStates = pDynamicStates;
		pipelineDynamicStateCreateInfo.dynamicStateCount = dynamicStateCount;
		pipelineDynamicStateCreateInfo.flags = flags;
		return pipelineDynamicStateCreateInfo;
	}

	inline auto pipelineDynamicStateCreateInfo(
		const std::vector<VkDynamicState> &pDynamicStates,
		VkPipelineDynamicStateCreateFlags flags = 0) -> VkPipelineDynamicStateCreateInfo
	{
		VkPipelineDynamicStateCreateInfo pipelineDynamicStateCreateInfo{};
		pipelineDynamicStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
		pipelineDynamicStateCreateInfo.pDynamicStates = pDynamicStates.data();
		pipelineDynamicStateCreateInfo.dynamicStateCount = static_cast<uint32_t>(pDynamicStates.size());
		pipelineDynamicStateCreateInfo.flags = flags;
		return pipelineDynamicStateCreateInfo;
	}

	inline constexpr auto pipelineTessellationStateCreateInfo(uint32_t patchControlPoints) -> VkPipelineTessellationStateCreateInfo
	{
		VkPipelineTessellationStateCreateInfo pipelineTessellationStateCreateInfo{};
		pipelineTessellationStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO;
		pipelineTessellationStateCreateInfo.patchControlPoints = patchControlPoints;
		return pipelineTessellationStateCreateInfo;
	}

	inline constexpr auto pipelineCreateInfo(
		VkPipelineLayout layout,
		VkRenderPass renderPass,
		VkPipelineCreateFlags flags = 0) -> VkGraphicsPipelineCreateInfo
	{
		VkGraphicsPipelineCreateInfo pipelineCreateInfo{};
		pipelineCreateInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
		pipelineCreateInfo.layout = layout;
		pipelineCreateInfo.renderPass = renderPass;
		pipelineCreateInfo.flags = flags;
		pipelineCreateInfo.basePipelineIndex = -1;
		pipelineCreateInfo.basePipelineHandle = VK_NULL_HANDLE;
		return pipelineCreateInfo;
	}

	inline constexpr auto pipelineCreateInfo() -> VkGraphicsPipelineCreateInfo
	{
		VkGraphicsPipelineCreateInfo pipelineCreateInfo{};
		pipelineCreateInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
		pipelineCreateInfo.basePipelineIndex = -1;
		pipelineCreateInfo.basePipelineHandle = VK_NULL_HANDLE;
		return pipelineCreateInfo;
	}

	inline constexpr auto computePipelineCreateInfo(
		VkPipelineLayout layout,
		VkPipelineCreateFlags flags = 0) -> VkComputePipelineCreateInfo
	{
		VkComputePipelineCreateInfo computePipelineCreateInfo{};
		computePipelineCreateInfo.sType = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
		computePipelineCreateInfo.layout = layout;
		computePipelineCreateInfo.flags = flags;
		return computePipelineCreateInfo;
	}

	inline constexpr auto pushConstantRange(
		VkShaderStageFlags stageFlags,
		uint32_t size,
		uint32_t offset) -> VkPushConstantRange
	{
		VkPushConstantRange pushConstantRange{};
		pushConstantRange.stageFlags = stageFlags;
		pushConstantRange.offset = offset;
		pushConstantRange.size = size;
		return pushConstantRange;
	}

	inline constexpr auto bindSparseInfo() -> VkBindSparseInfo
	{
		VkBindSparseInfo bindSparseInfo{};
		bindSparseInfo.sType = VK_STRUCTURE_TYPE_BIND_SPARSE_INFO;
		return bindSparseInfo;
	}

	/** @brief Initialize a map entry for a shader specialization constant */
	inline constexpr auto specializationMapEntry(uint32_t constantID, uint32_t offset, size_t size) -> VkSpecializationMapEntry
	{
		VkSpecializationMapEntry specializationMapEntry{};
		specializationMapEntry.constantID = constantID;
		specializationMapEntry.offset = offset;
		specializationMapEntry.size = size;
		return specializationMapEntry;
	}

	/** @brief Initialize a specialization constant info structure to pass to a shader stage */
	inline constexpr auto specializationInfo(uint32_t mapEntryCount, const VkSpecializationMapEntry *mapEntries, size_t dataSize, const void *data) -> VkSpecializationInfo
	{
		VkSpecializationInfo specializationInfo{};
		specializationInfo.mapEntryCount = mapEntryCount;
		specializationInfo.pMapEntries = mapEntries;
		specializationInfo.dataSize = dataSize;
		specializationInfo.pData = data;
		return specializationInfo;
	}

	/** @brief Initialize a specialization constant info structure to pass to a shader stage */
	inline auto specializationInfo(const std::vector<VkSpecializationMapEntry> &mapEntries, size_t dataSize, const void *data) -> VkSpecializationInfo
	{
		VkSpecializationInfo specializationInfo{};
		specializationInfo.mapEntryCount = static_cast<uint32_t>(mapEntries.size());
		specializationInfo.pMapEntries = mapEntries.data();
		specializationInfo.dataSize = dataSize;
		specializationInfo.pData = data;
		return specializationInfo;
	}

	// Ray tracing related
	inline constexpr auto accelerationStructureGeometryKHR() -> VkAccelerationStructureGeometryKHR
	{
		VkAccelerationStructureGeometryKHR accelerationStructureGeometryKHR{};
		accelerationStructureGeometryKHR.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR;
		return accelerationStructureGeometryKHR;
	}

	inline constexpr auto accelerationStructureBuildGeometryInfoKHR() -> VkAccelerationStructureBuildGeometryInfoKHR
	{
		VkAccelerationStructureBuildGeometryInfoKHR accelerationStructureBuildGeometryInfoKHR{};
		accelerationStructureBuildGeometryInfoKHR.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR;
		return accelerationStructureBuildGeometryInfoKHR;
	}

	inline constexpr auto accelerationStructureBuildSizesInfoKHR() -> VkAccelerationStructureBuildSizesInfoKHR
	{
		VkAccelerationStructureBuildSizesInfoKHR accelerationStructureBuildSizesInfoKHR{};
		accelerationStructureBuildSizesInfoKHR.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR;
		return accelerationStructureBuildSizesInfoKHR;
	}

	inline constexpr auto rayTracingShaderGroupCreateInfoKHR() -> VkRayTracingShaderGroupCreateInfoKHR
	{
		VkRayTracingShaderGroupCreateInfoKHR rayTracingShaderGroupCreateInfoKHR{};
		rayTracingShaderGroupCreateInfoKHR.sType = VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR;
		return rayTracingShaderGroupCreateInfoKHR;
	}

	inline constexpr auto rayTracingPipelineCreateInfoKHR() -> VkRayTracingPipelineCreateInfoKHR
	{
		VkRayTracingPipelineCreateInfoKHR rayTracingPipelineCreateInfoKHR{};
		rayTracingPipelineCreateInfoKHR.sType = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR;
		return rayTracingPipelineCreateInfoKHR;
	}

	inline constexpr auto writeDescriptorSetAccelerationStructureKHR() -> VkWriteDescriptorSetAccelerationStructureKHR
	{
		VkWriteDescriptorSetAccelerationStructureKHR writeDescriptorSetAccelerationStructureKHR{};
		writeDescriptorSetAccelerationStructureKHR.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR;
		return writeDescriptorSetAccelerationStructureKHR;
	}

	inline void destroyCommandBuffers(VkDevice device, VkCommandPool cmdPool, std::vector<VkCommandBuffer>& drawCmdBuffers)
{
	vkFreeCommandBuffers(device, cmdPool, static_cast<uint32_t>(drawCmdBuffers.size()), drawCmdBuffers.data());
}

}
#endif