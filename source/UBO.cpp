#include <VulkanTools/Tools.hpp>
#include <VulkanTools/UBO.hpp>
#include <numeric>
UBO::UBO(VulkanDevice &device, const std::vector<UBOField> &fields)
    : fields(fields),
      total_size(std::accumulate(fields.begin(), fields.end(), 0,
                           [](size_t result, const UBOField &field) {
                             return result + field.size;
                           })) {
  VK_CHECK_RESULT(device.createBuffer(VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
                                      VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
                                          VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
                                      &buffer, sizeof(total_size)));
}

void UBO::update(void *data) const { memcpy(buffer.mapped, data, total_size); }

size_t UBO::get_offset(const std::string &name) const {
  size_t offset = 0;
  for (const auto &field : fields) {
    if (field.name == name) {
      return offset;
    }
    offset += field.size;
  }
  throw std::runtime_error("field not found");
  return 0;
}

size_t UBO::get_size(const std::string &name) const {
  size_t offset = 0;
  for (const auto &field : fields) {
    if (field.name == name) {
      return field.size;
    }
    offset += field.size;
  }
  throw std::runtime_error("field not found");
}

void UBO::update(const std::string &name, void *data) const {
  size_t offset = get_offset(name);
  memcpy((char *)buffer.mapped + offset, data, get_size(name));
}