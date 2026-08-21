#pragma once
#include <cstdint>
#include <cstddef>

// -----------------------------------------------
// wh::entitymodule::S_HorseAnimBind -- KCD2 WHGame.dll.  sizeof 0x50.
// -----------------------------------------------
// ctor sub_180BE0E30. Embedded at S_HorseData+0x448. Subscribes to horse
// C_HitDeathReactions (+0x240) and property +0x98.

namespace wh::entitymodule {

class S_HorseData;

class S_HorseAnimBind {
public:
    S_HorseData* m_pHorseData;     // +0x00
    uint32_t     m_fragmentId;     // +0x08  from sub_180BE1538(horse)
    uint32_t     _pad0C;           // +0x0C
    int32_t      m_unk10;          // +0x10
    float        m_blendIn;        // +0x14  -1.0
    float        m_blendOut;       // +0x18  -1.0
    uint8_t      m_flags1C;        // +0x1C  bit0 set in ctor
    uint8_t      _pad1D[3];        // +0x1D
    uint8_t      m_block20[0x20];  // +0x20
    uint64_t     m_unk40;          // +0x40
    int32_t      m_tagA;           // +0x48  -1
    int32_t      m_tagB;           // +0x4C  -1
};
static_assert(sizeof(S_HorseAnimBind) == 0x50, "S_HorseAnimBind must be 0x50");

}  // namespace wh::entitymodule
