#pragma once
#include <cstdint>
#include <cstddef>
#include "S_HorseRaycast.h"

// -----------------------------------------------
// wh::entitymodule::S_HorseCollisionGrid -- KCD2 WHGame.dll.  sizeof 0x230.
// -----------------------------------------------
// ctor sub_180BE0D80. Embedded at S_HorseCollisionAvoider+0x10 (S_HorseData+0x1F0).
// Group timers are 8-byte FLT_MAX stores (float + pad), not packed floats.

namespace wh::entitymodule {

class S_HorseData;

struct S_HorseAvoidTimer {
    float    m_value;   // FLT_MAX
    uint32_t _pad;
};
static_assert(sizeof(S_HorseAvoidTimer) == 8, "avoid timer is a qword store");

class S_HorseCollisionGrid {
public:
    S_HorseData*      m_pHorseData;      // +0x00
    S_HorseRaycast    m_rays[12];        // +0x08
    S_HorseAvoidTimer m_groupTimer[3];   // +0x1E8
    uint64_t          m_clear200;        // +0x200
    uint64_t          m_clear208;        // +0x208
    uint64_t          m_clear210;        // +0x210
    uint32_t          m_clear218[3];     // +0x218
    uint32_t          m_clear224;        // +0x224  qword-low
    uint32_t          m_clear228;        // +0x228  qword-high
    uint32_t          _pad22C;           // +0x22C
};
static_assert(sizeof(S_HorseCollisionGrid) == 0x230, "S_HorseCollisionGrid must be 0x230");
static_assert(offsetof(S_HorseCollisionGrid, m_rays) == 0x08, "rays");
static_assert(offsetof(S_HorseCollisionGrid, m_groupTimer) == 0x1E8, "group timers");
static_assert(offsetof(S_HorseCollisionGrid, m_clear224) == 0x224, "tail qword");

}  // namespace wh::entitymodule
