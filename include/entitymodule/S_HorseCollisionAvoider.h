#pragma once
#include <cstdint>
#include <cstddef>
#include "S_HorseCollisionGrid.h"

// -----------------------------------------------
// wh::entitymodule::S_HorseCollisionAvoider -- KCD2 WHGame.dll.  sizeof 0x240.
// -----------------------------------------------
// Tick sub_1806CF09C(S_HorseData+0x1E0). Grid ctor is sub_180BE0D80 at +0x10.
// +0x08 caches I_HorseHeadingSource::IsLive. On change, writes S_HorseData+0x90
// (m_avoiding) and emits its signal.

namespace wh::entitymodule {

class S_HorseData;

class S_HorseCollisionAvoider {
public:
    S_HorseData*         m_pHorseData;    // +0x00
    uint8_t              m_headingLive;   // +0x08
    uint8_t              _pad09[3];       // +0x09
    int32_t              m_zero0C;        // +0x0C
    S_HorseCollisionGrid m_grid;          // +0x10  0x230
};
static_assert(sizeof(S_HorseCollisionAvoider) == 0x240, "S_HorseCollisionAvoider must be 0x240");
static_assert(offsetof(S_HorseCollisionAvoider, m_grid) == 0x10, "grid");

}  // namespace wh::entitymodule
