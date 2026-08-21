#pragma once
#include <cstdint>
#include <cstddef>
#include "../CryEngine/CryCommon/Cry_Math.h"

// -----------------------------------------------
// wh::entitymodule::S_HorseFollowStick -- KCD2 WHGame.dll.  sizeof 0x20.
// -----------------------------------------------
// ctor sub_180BE0D44. Embedded at S_HorseRoadFollow+0x10.
// A03994 writes 2 floats at +0 from dword_183A83AA0.

namespace wh::entitymodule {

struct S_HorseFollowStick {
    Vec2      m_stick;       // +0x00
    float     m_delta;       // +0x08  ctor 0; cleared when magnetism drops
    float     m_negOne;      // +0x0C  -1.0
    int32_t   m_zero10;      // +0x10
    uint32_t  _pad14;        // +0x14
    uint64_t* m_pUser;       // +0x18  points at S_HorseRoadFollow+0x08
};
static_assert(sizeof(S_HorseFollowStick) == 0x20, "S_HorseFollowStick must be 0x20");

}  // namespace wh::entitymodule
