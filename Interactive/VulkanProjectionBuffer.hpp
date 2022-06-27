#ifndef NV_PROJECTION_BUFFER_HPP
#define NV_PROJECTION_BUFFER_HPP
#include <vulkan/vulkan.hpp>
#include <VulkanDevice.hpp>
#include <VulkanBuffer.hpp>
#include <VulkanCamera.hpp>

struct ProjectionData {
    glm::mat4 projection;
    glm::mat4 view;
    glm::vec4 lightPos = glm::vec4(0.0f, -5.0f, 0.0f, 1.0f);
};

	void prepareProjectionBuffer(VulkanDevice* vulkanDevice, VulkanBuffer& buffer, ProjectionData& projectionData, const Camera& camera);

	void updateProjectionBuffer(VulkanBuffer& buffer, ProjectionData& projectionData, const Camera& camera, bool viewChanged);

#endif