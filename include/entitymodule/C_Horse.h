#pragma once
#include <cstdint>
#include "C_Animal.h"
#include "S_MountAnimState.h"
#include "S_HorseData.h"

// -----------------------------------------------
// wh::entitymodule::C_Horse : C_Animal  (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof 0xA60.
// -----------------------------------------------
// RTTI .?AVC_Horse@entitymodule@wh@@  primary vtable 0x183A6E508 (280 slots)
// factory 0x180A70924  Init sub_180BE0A18 (vtable slot 7)  dtor sub_180BDFA70.
// Own members occupy +0x9E8..+0xA60 (0x78); base is C_Animal.
//
// [FUNDAMENTAL vs KCD1] KCD1 C_Horse inlined all the bridle/rope/rein/rider/anim state up to 0xE38;
// KCD2 is a thin shell -- that state moved into a heap-allocated 0x4C8 controller (m_pHorseData @+0x9E8).
// Only the controller pointer and a POD mount-anim block remain directly on C_Horse.

namespace wh::entitymodule {

class C_Horse : public C_Animal {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Horse;
    S_HorseData* m_pHorseData;                         // +0x9E8  (0x4C8 heap controller, OWNED: dtor frees via sub_181AB5160(.,0x4C8))  VERIFIED offset/size
    S_MountAnimState m_mountAnimState;                 // +0x9F0  last frame-movement request (0x70, ctor 0x180A709E8)
};
static_assert(sizeof(C_Horse) == 0xA60, "C_Horse must be 0xA60");

}  // namespace wh::entitymodule
