/*
* Assorted Vulkan helper functions
*
* Copyright (C) 2016 by Sascha Willems - www.saschawillems.de
*
* This code is licensed under the MIT license (MIT) (http://opensource.org/licenses/MIT)
*/

#ifndef Vulkan_TOOLS_HPP
#define Vulkan_TOOLS_HPP

#include <vulkan/vulkan.hpp>
#include <iostream>

// Custom define for better code readability
#define VK_FLAGS_NONE 0
// Default fence timeout in nanoseconds
#define DEFAULT_FENCE_TIMEOUT 100000000000

#ifndef VK_CHECK_RESULT
#define VK_CHECK_RESULT(f)                                                                                                               \
	{                                                                                                                                    \
		VkResult res = (f);                                                                                                              \
		if (res != VK_SUCCESS)                                                                                                           \
		{                                                                                                                                \
			std::cout << "Fatal : VkResult is \"" << tools::errorString(res) << "\" in " << __FILE__ << " at line " << __LINE__ << "\n"; \
			assert(res == VK_SUCCESS);                                                                                                   \
		}                                                                                                                                \
	}
#endif

static void check_vk_result(VkResult err)
{
    if (err == 0)
        return;
    fprintf(stderr, "[vulkan] Error: VkResult = %d\n", err);
    if (err < 0)
        abort();
}

namespace tools
{
	/** @brief Disable message boxes on fatal errors */
	extern bool errorModeSilent;

	/** @brief Returns an error code as a string */
	std::string errorString(VkResult errorCode);

	/** @brief Returns the device type as a string */
	std::string physicalDeviceTypeString(VkPhysicalDeviceType type);

	// Selected a suitable supported depth format starting with 32 bit down to 16 bit
	// Returns false if none of the depth formats in the list is supported by the device
	VkBool32 getSupportedDepthFormat(VkPhysicalDevice physicalDevice, VkFormat *depthFormat);


	// Put an image memory barrier for setting an image layout on the sub resource into the given command buffer
	void setImageLayout(
		VkCommandBuffer cmdbuffer,
		VkImage image,
		VkImageLayout oldImageLayout,
		VkImageLayout newImageLayout,
		VkImageSubresourceRange subresourceRange,
		VkPipelineStageFlags srcStageMask = VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
		VkPipelineStageFlags dstStageMask = VK_PIPELINE_STAGE_ALL_COMMANDS_BIT);
	// Uses a fixed sub resource layout with first mip level and layer
	void setImageLayout(
		VkCommandBuffer cmdbuffer,
		VkImage image,
		VkImageAspectFlags aspectMask,
		VkImageLayout oldImageLayout,
		VkImageLayout newImageLayout,
		VkPipelineStageFlags srcStageMask = VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
		VkPipelineStageFlags dstStageMask = VK_PIPELINE_STAGE_ALL_COMMANDS_BIT);

	/** @brief Insert an image memory barrier into the command buffer */
	void insertImageMemoryBarrier(
		VkCommandBuffer cmdbuffer,
		VkImage image,
		VkAccessFlags srcAccessMask,
		VkAccessFlags dstAccessMask,
		VkImageLayout oldImageLayout,
		VkImageLayout newImageLayout,
		VkPipelineStageFlags srcStageMask,
		VkPipelineStageFlags dstStageMask,
		VkImageSubresourceRange subresourceRange);

	// Display error message and exit on fatal error
	void exitFatal(const std::string &message, int32_t exitCode);
	void exitFatal(const std::string &message, VkResult resultCode);

	// Load a SPIR-V shader (binary)

	VkShaderModule loadShaderModule(const char *fileName, VkDevice device);

	/** @brief Checks if a file exists */
	bool fileExists(const std::string &filename);

	uint32_t alignedSize(uint32_t value, uint32_t alignment);
}
#endif