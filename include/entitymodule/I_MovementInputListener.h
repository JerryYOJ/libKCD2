#pragma once
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"

// -----------------------------------------------
// wh::entitymodule::I_MovementInputListener -- KCD2 WHGame.dll.  sizeof 8.  3 slots.
// -----------------------------------------------
// RTTI .?AVI_MovementInputListener@entitymodule@wh@@. Secondary base of
// C_RiderPlayerInput at +8 (vt 0x183EAADF8, COL offset=8). Slot bodies see
// the +8 this; OnMovementInput stores into complete+0x9CC etc.

namespace wh::entitymodule {

class I_MovementInputListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_MovementInputListener;
    virtual bool OnMovementInput(uint32_t* mask, const Vec3* move, const Vec3* look) = 0; // [0] 0x18059BB20
    virtual bool AlwaysFalse() const = 0;                                                 // [1] 0x180838AE0  ICF stub
    virtual void Destroy(uint8_t dealloc) = 0;                                            // [2] 0x182139A84  this-8
};
static_assert(sizeof(I_MovementInputListener) == 8, "I_MovementInputListener is vtable-only");

}  // namespace wh::entitymodule
