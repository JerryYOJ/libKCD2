#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "E_LODRootMotionMode.h"
#include "S_LODRootMotionAnimation.h"
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../Offsets/vtables/IEntity.h"

namespace wh::animationmodule {

class C_AnimationController;
class C_LODAnimationController;

// Source-reconstructed name; exact non-polymorphic 0xC0 runtime state.
struct S_LODAnimationRuntimeState {
    C_LODAnimationController* m_pController;             // +0x00
    EntityId m_entityId;                                  // +0x08
    Matrix34 m_worldTMAtSetup;                            // +0x0C, exact role retained from writer
    QuatT m_fragmentRootMotion;                           // +0x3C
    QuatT m_lastRootMotion;                               // +0x58
    float m_scopePlaybackScale;                           // +0x74, source name OPEN
    float m_elapsedTime;                                  // +0x78
    float m_rootMotionModeTime;                           // +0x7C
    float m_fragmentDuration;                             // +0x80
    bool m_suppressRootMotion;                            // +0x84
    std::uint8_t _pad85[3];                               // +0x85
    std::vector<S_LODRootMotionAnimation> m_animations;   // +0x88
    E_LODRootMotionMode m_mode;                           // +0xA0
    std::uint32_t _padA4;                                 // +0xA4
    C_LODAnimationController* m_pUpdateAdapterController; // +0xA8, role name reconstructed
    C_LODAnimationController* m_pLayerAdapterController;  // +0xB0, role name reconstructed
    C_AnimationController* m_pOwner;                      // +0xB8
};
static_assert(sizeof(S_LODAnimationRuntimeState) == 0xC0,
              "LOD animation runtime state must be 0xC0");
static_assert(offsetof(S_LODAnimationRuntimeState, m_worldTMAtSetup) == 0x0C,
              "LOD setup transform must be at 0x0C");
static_assert(offsetof(S_LODAnimationRuntimeState, m_fragmentRootMotion) == 0x3C,
              "LOD fragment root motion must be at 0x3C");
static_assert(offsetof(S_LODAnimationRuntimeState, m_animations) == 0x88,
              "LOD root-motion animation vector must be at 0x88");
static_assert(offsetof(S_LODAnimationRuntimeState, m_mode) == 0xA0,
              "LOD root-motion mode must be at 0xA0");

}  // namespace wh::animationmodule
