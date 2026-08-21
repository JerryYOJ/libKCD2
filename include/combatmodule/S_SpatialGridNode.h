#pragma once
#include <cstddef>
#include <cstdint>
#include "S_SpatialGridNodeDynArray.h"

namespace wh::combatmodule {

struct S_SpatialGridNode {
    S_SpatialGridNode();
    S_SpatialGridNode(const S_SpatialGridNode& rhs);
    S_SpatialGridNode(S_SpatialGridNode&& rhs);
    S_SpatialGridNode& operator=(const S_SpatialGridNode& rhs);
    ~S_SpatialGridNode();

    std::int8_t m_extent; // +0x00, quantized half-extent
    std::int8_t m_posX;   // +0x01, signed quantized origin
    std::int8_t m_posY;   // +0x02
    std::int8_t m_posZ;   // +0x03
    bool m_occupied;      // +0x04
    std::uint8_t _pad05[3];
    DynArray<S_SpatialGridNode> m_children; // +0x08, owned recursive children
};
static_assert(sizeof(S_SpatialGridNode) == 0x10);
static_assert(offsetof(S_SpatialGridNode, m_extent) == 0x00);
static_assert(offsetof(S_SpatialGridNode, m_posX) == 0x01);
static_assert(offsetof(S_SpatialGridNode, m_occupied) == 0x04);
static_assert(offsetof(S_SpatialGridNode, m_children) == 0x08);

}  // namespace wh::combatmodule
