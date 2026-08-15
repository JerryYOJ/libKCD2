#pragma once
#include <cstdint>

namespace wh::animationmodule {

// Source-reconstructed name; exact 0x08 root-motion clip record.
struct S_LODRootMotionAnimation {
    std::int32_t m_animationId; // +0x00
    float m_cumulativeEndTime;  // +0x04
};
static_assert(sizeof(S_LODRootMotionAnimation) == 0x08,
              "LOD root-motion animation must be 0x08");

}  // namespace wh::animationmodule
