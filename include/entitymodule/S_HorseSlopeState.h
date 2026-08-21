#pragma once
#include <cstdint>
#include <cstddef>
#include "../CryEngine/CryCommon/Cry_Math.h"

// -----------------------------------------------
// wh::entitymodule::S_HorseSlopeState -- KCD2 WHGame.dll.  sizeof 0x28.
// -----------------------------------------------
// ctor sub_180BE0C14. Embedded at S_HorseData+0x420. Tick sub_1806CC570.

namespace wh::entitymodule {

class S_HorseData;

class S_HorseSlopeState {
public:
    S_HorseData* m_pHorseData;   // +0x00
    int32_t      m_unk08;        // +0x08
    int32_t      m_fragmentId;   // +0x0C  -1
    Vec3         m_normal;       // +0x10
    int32_t      m_unk1C;        // +0x1C
    float        m_scale;        // +0x20  1.0
    uint32_t     _pad24;         // +0x24
};
static_assert(sizeof(S_HorseSlopeState) == 0x28, "S_HorseSlopeState must be 0x28");

}  // namespace wh::entitymodule
