#ifndef Vulkan_DEVICE_HPP
#define Vulkan_DEVICE_HPP
#include <string>
#include <vector>
#include <VulkanTools/Buffer.hpp>

struct VulkanDevice
{
	/** @brief Physical device representation */
	VkPhysicalDevice physicalDevice;
	/** @brief Logical device representation (application's view of the device) */
	VkDevice logicalDevice{};
	/** @brief Properties of the physical device including limits that the application can check against */
	VkPhysicalDeviceProperties properties{};
	/** @brief Features of the physical device that an application can use to check if a feature is supported */
	VkPhysicalDeviceFeatures features{};
	/** @brief Features that have been enabled for use on the physical device */
	VkPhysicalDeviceFeatures enabledFeatures{};
	/** @brief Memory types and heaps of the physical device */
	VkPhysicalDeviceMemoryProperties memoryProperties{};
	/** @brief Queue family properties of the physical device */
	std::vector<VkQueueFamilyProperties> queueFamilyProperties;
	/** @brief List of extensions supported by the device */
	std::vector<std::string> supportedExtensions;
	/** @brief Default command pool for the graphics queue family index */
	VkCommandPool commandPool = VK_NULL_HANDLE;
	/** @brief Set to true when the debug marker extension is detected */
	bool enableDebugMarkers = false;
	/** @brief Contains queue family indices */
	struct
	{
		uint32_t graphics;
		uint32_t compute;
		uint32_t transfer;
	} queueFamilyIndices{};
	operator VkDevice() const
	{
		return logicalDevice;
	};
	explicit VulkanDevice(VkPhysicalDevice physicalDevice);
	~VulkanDevice();
	auto        getMemoryType(uint32_t typeBits, VkMemoryPropertyFlags properties, VkBool32 *memTypeFound = nullptr) const -> uint32_t;
	[[nodiscard]] auto        getQueueFamilyIndex(VkQueueFlagBits queueFlags) const -> uint32_t;
	auto        createLogicalDevice(VkPhysicalDeviceFeatures enabledFeatures, std::vector<const char *> enabledExtensions, void *pNextChain, bool useSwapChain = true, VkQueueFlags requestedQueueTypes = VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT) -> VkResult;
	auto        createBuffer(VkBufferUsageFlags usageFlags, VkMemoryPropertyFlags memoryPropertyFlags, VkDeviceSize size, VkBuffer *buffer, VkDeviceMemory *memory, void *data = nullptr) -> VkResult;
	auto        createBuffer(VkBufferUsageFlags usageFlags, VkMemoryPropertyFlags memoryPropertyFlags, VulkanBuffer *buffer, VkDeviceSize size, void *data = nullptr) -> VkResult;
	void            copyBuffer(VulkanBuffer *src, VulkanBuffer *dst, VkQueue queue, VkBufferCopy *copyRegion = nullptr);
	auto   createCommandPool(uint32_t queueFamilyIndex, VkCommandPoolCreateFlags createFlags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT) -> VkCommandPool;
	auto createCommandBuffer(VkCommandBufferLevel level, VkCommandPool pool, bool begin = false) -> VkCommandBuffer;
	auto createCommandBuffer(VkCommandBufferLevel level, bool begin = false) -> VkCommandBuffer;
	void            flushCommandBuffer(VkCommandBuffer commandBuffer, VkQueue queue, VkCommandPool pool, bool free = true);
	void            flushCommandBuffer(VkCommandBuffer commandBuffer, VkQueue queue, bool free = true);
	auto            extensionSupported(const std::string& extension) -> bool;
	auto        getSupportedDepthFormat(bool checkSamplingSupport) -> VkFormat;
};


#endif