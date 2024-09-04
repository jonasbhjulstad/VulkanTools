#pragma once
#include <unordered_map>
#include <string>
#include <glm/glm.hpp>
const std::unordered_map<std::string, size_t> glsl_sizes = 
{
    {"float", sizeof(float)},
    {"vec2", sizeof(glm::vec2)},
    {"vec3", sizeof(glm::vec3)},
    {"vec4", sizeof(glm::vec4)},
    {"mat3", sizeof(glm::mat3)},
    {"mat4", sizeof(glm::mat4)},
    {"int", sizeof(int)},
    {"ivec2", sizeof(glm::ivec2)},
    {"ivec3", sizeof(glm::ivec3)},
    {"ivec4", sizeof(glm::ivec4)},
    {"bool", sizeof(bool)},
    {"bvec2", sizeof(glm::bvec2)},
    {"bvec3", sizeof(glm::bvec3)},
    {"bvec4", sizeof(glm::bvec4)},
    {"uint", sizeof(uint32_t)},
    {"uvec2", sizeof(glm::uvec2)},
    {"uvec3", sizeof(glm::uvec3)},
    {"uvec4", sizeof(glm::uvec4)}
};
