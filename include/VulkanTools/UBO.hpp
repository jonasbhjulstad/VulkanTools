#ifndef NV_PROJECTION_BUFFER_HPP
#define NV_PROJECTION_BUFFER_HPP
#include <VulkanTools/Buffer.hpp>
#include <VulkanTools/Camera.hpp>
#include <VulkanTools/Device.hpp>
#include <VulkanTools/glsl_types.hpp>
#include <vulkan/vulkan.hpp>
struct UBOField {
  std::string name;
  size_t size;
};

struct UBO {
  VulkanBuffer buffer;
  const std::vector<UBOField> fields;
  const size_t total_size;
  UBO(VulkanDevice &device, const std::vector<UBOField> &fields);

  void update(void *data) const;

  size_t get_offset(const std::string &name) const;

  size_t get_size(const std::string &name) const;

  void update(const std::string &name, void *data) const;
};
#endif