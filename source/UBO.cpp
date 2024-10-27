#include <VulkanTools/Tools.hpp>
#include <VulkanTools/UBO.hpp>
#include <numeric>
namespace VkVP {
UBO::UBO(VulkanDevice &device, const std::vector<UBOField> &fields, uint32_t binding)
  : fields(fields), total_size(std::accumulate(fields.begin(),
                      fields.end(),
                      0,
                      [](uint32_t result, const UBOField &field) { return result + field.size; })),
    binding(binding)
{
  VK_CHECK_RESULT(device.createBuffer(VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
    VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
    &buffer,
    sizeof(total_size)));
}
  UBO::UBO(VulkanDevice& device, const UBOEntry& entry)
  : UBO(device, entry.fields, entry.binding){}
void UBO::update(void *data) const { memcpy(buffer.mapped, data, total_size); }

uint32_t UBO::get_offset(const std::string &name) const
{
  uint32_t offset = 0;
  for (const auto &field : fields) {
    if (field.name == name) { return offset; }
    offset += field.size;
  }
  throw std::runtime_error("field not found");
  return 0;
}

uint32_t UBO::get_size(const std::string &name) const
{
  uint32_t offset = 0;
  for (const auto &field : fields) {
    if (field.name == name) { return field.size; }
    offset += field.size;
  }
  throw std::runtime_error("field not found");
}

void UBO::update(const std::string &name, void *data) const
{
  uint32_t offset = get_offset(name);
  memcpy((char *)buffer.mapped + offset, data, get_size(name));
}

std::unordered_map<std::string, VkVP::UBO> make_ubos(VulkanDevice &device, const std::vector<UBOEntry> &entries)
{

  std::unordered_map<std::string, VkVP::UBO> ubos;

  std::transform(entries.begin(), entries.end(), std::inserter(ubos, ubos.end()), [&](const UBOEntry &entry) {
    return std::make_pair(entry.name, VkVP::UBO(device, entry.fields, entry.binding));
  });
  return ubos;
}

}// namespace VkVP