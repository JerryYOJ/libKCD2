#pragma once
#include <cstdint>
#include <cstddef>

// -----------------------------------------------
// wh::entitymodule::S_HorseRaycast -- KCD2 WHGame.dll.  sizeof 0x28.
// -----------------------------------------------
// ctor sub_181532CD0. Filled by sub_180BDFF48 from S_HorseCVars height/width triples.
// 9 slots (kind=1) are the 3x3 height x width grid; 3 trailing slots are kind=2.

namespace wh::entitymodule {

struct S_HorseRaycast {
    int32_t m_tagId;      // +0x00
    float   m_width;      // +0x04  CVars width[group]
    float   m_half;       // +0x08  0.5
    float   m_height;     // +0x0C  CVars height[rank], or (i+1)/3 for kind 2
    float   m_hit[3];     // +0x10  default 0
    int32_t m_group;      // +0x1C  0..2
    int32_t m_rank;       // +0x20  0..2
    uint8_t m_kind;       // +0x24  1 = grid, 2 = extra
    uint8_t _pad25[3];    // +0x25
};
static_assert(sizeof(S_HorseRaycast) == 0x28, "S_HorseRaycast must be 0x28");

}  // namespace wh::entitymodule
