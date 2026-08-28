#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::entitymodule::S_DoorAnimData
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x28. No vtable.
// -----------------------------------------------

namespace wh::entitymodule {

struct S_DoorAnimData {
    CryStringT<char> m_actorClassName;                    // +0x00 RTTR "ActorClassName"
    bool m_isStealth;                                     // +0x08 RTTR "IsStealth"
    std::uint8_t _pad09[7];                               // +0x09
    CryStringT<char> m_anim;                              // +0x10 RTTR "Anim"
    CryStringT<char> m_directionTag;                      // +0x18 RTTR "DirectionTag"
    float m_pseudoSpeed;                                  // +0x20 RTTR "PseudoSpeed"
    float m_distance;                                     // +0x24 RTTR "Distance"
};

static_assert(offsetof(S_DoorAnimData, m_actorClassName) == 0x00,
              "S_DoorAnimData::m_actorClassName offset mismatch");
static_assert(offsetof(S_DoorAnimData, m_pseudoSpeed) == 0x20,
              "S_DoorAnimData::m_pseudoSpeed offset mismatch");
static_assert(sizeof(S_DoorAnimData) == 0x28,
              "S_DoorAnimData size mismatch");

}  // namespace wh::entitymodule
