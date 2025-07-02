/*
 * Vulkan buffer class
 *
 * Encapsulates a Vulkan buffer
 *
 * Copyright (C) 2016 by Sascha Willems - www.saschawillems.de
 *
 * This code is licensed under the MIT license (MIT) (http://opensource.org/licenses/MIT)
 */

#ifndef Vulkan_BUFFER_HPP
#define Vulkan_BUFFER_HPP
#include <vector>

#include <vulkan/vulkan.hpp>
namespace VKT {
	struct VulkanBuffer
	{
		VkDevice device{};
		VkBuffer buffer = VK_NULL_HANDLE;
		VkDeviceMemory memory = VK_NULL_HANDLE;
		VkDescriptorBufferInfo descriptor{};
		VkDeviceSize size = 0;
		VkDeviceSize alignment = 0;
		void *mapped = nullptr;
		/** @brief Usage flags to be filled by external source at buffer creation (to query at some later point) */
		VkBufferUsageFlags usageFlags{};
		/** @brief Memory property flags to be filled by external source at buffer creation (to query at some later point) */
		VkMemoryPropertyFlags memoryPropertyFlags{};
		auto map(VkDeviceSize size = VK_WHOLE_SIZE, VkDeviceSize offset = 0) -> VkResult;
		void unmap();
		auto bind(VkDeviceSize offset = 0) -> VkResult;
		void setupDescriptor(VkDeviceSize size = VK_WHOLE_SIZE, VkDeviceSize offset = 0);
		void copyTo(void *data, VkDeviceSize size);
		auto flush(VkDeviceSize size = VK_WHOLE_SIZE, VkDeviceSize offset = 0) -> VkResult;
		auto invalidate(VkDeviceSize size = VK_WHOLE_SIZE, VkDeviceSize offset = 0) -> VkResult;
		void destroy();
	};
} // namespace VKT
#endif