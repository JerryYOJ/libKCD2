#pragma once
#include <cstdint>
#include <cstddef>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "S_HorseRoadPoint.h"

// -----------------------------------------------
// wh::entitymodule::S_HorseMagnetismSample -- KCD2 WHGame.dll.  sizeof 0x38.
// -----------------------------------------------
// Filled by sub_180A0A124 (a5). Tick phases read it; sub_180A4DE5C copies
// m_hit / m_yawFrom / m_hasHit onto S_HorseData +0x13C / +0x130 / +0x138.
// Stack object in sub_180A4E5AC is this layout (v17..v23).

namespace wh::entitymodule {

struct S_HorseMagnetismSample {
    Vec3              m_hit;       // +0x00  a5+0 / +8
    Vec3              m_along;     // +0x0C  a5+0x0C / +0x14
    S_HorseRoadPoint* m_pFrom;     // +0x18
    S_HorseRoadPoint* m_pTo;       // +0x20
    float             m_yawFrom;   // +0x28  atan2
    float             m_yawTo;     // +0x2C  atan2
    uint8_t           m_hasHit;    // +0x30
    uint8_t           m_failed;    // +0x31  OnPress phase 5
    uint16_t          _pad32;      // +0x32
    uint32_t          _pad34;      // +0x34  stack slack to 0x38
};
static_assert(sizeof(S_HorseMagnetismSample) == 0x38, "magnetism sample is 0x38");
static_assert(offsetof(S_HorseMagnetismSample, m_pFrom) == 0x18, "from");
static_assert(offsetof(S_HorseMagnetismSample, m_yawFrom) == 0x28, "yawFrom");
static_assert(offsetof(S_HorseMagnetismSample, m_hasHit) == 0x30, "hasHit");

}  // namespace wh::entitymodule
