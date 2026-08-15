#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::animationmodule {

struct S_LODScopeAnimLayer {
    float m_time;                           // +0x00
    float m_remainingTime;                  // +0x04, -1.0f for terminal looping clip
    float m_previousAnimationRemainingTime; // +0x08
    float m_animationDuration;              // +0x0C
    std::uint32_t m_animationIndex;         // +0x10
    bool m_looping;                         // +0x14, CA_LOOP_ANIMATION
    std::uint8_t _pad15[3];                 // +0x15
    const char* m_currentAnimationName;      // +0x18, borrowed
    const char* m_previousAnimationName;     // +0x20, borrowed
};
static_assert(sizeof(S_LODScopeAnimLayer) == 0x28,
              "S_LODScopeAnimLayer must be 0x28");
static_assert(offsetof(S_LODScopeAnimLayer, m_currentAnimationName) == 0x18,
              "current LOD animation name must be at 0x18");

}  // namespace wh::animationmodule
