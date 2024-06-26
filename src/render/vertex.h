#pragma once

#include "libs.h"

struct Vertex {
    glm::vec3 pos;
    glm::vec2 texCoord;

    bool operator==(const Vertex &other) const {
        return pos == other.pos && texCoord == other.texCoord;
    }

    static vk::VertexInputBindingDescription getBindingDescription();

    static std::array<vk::VertexInputAttributeDescription, 2> getAttributeDescriptions();
};

template<>
struct std::hash<Vertex> {
    size_t operator()(Vertex const &vertex) const noexcept {
        return (hash<glm::vec3>()(vertex.pos) >> 1) ^
               (hash<glm::vec2>()(vertex.texCoord) << 1);
    }
};
