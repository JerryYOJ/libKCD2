#pragma once
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"

// -----------------------------------------------
// wh::entitymodule::I_HorseMoveAdapter -- KCD2 WHGame.dll.  sizeof 8.  7 slots.
// -----------------------------------------------
// RTTI .?AVI_HorseMoveAdapter@entitymodule@wh@@. Primary of C_RiderPlayerInput
// (vt 0x183EAADB8). Slot 0 is ApplyTurnSlowdown, not a dtor. Destroy is [6].

namespace wh::entitymodule {

class S_HorseData;

class I_HorseMoveAdapter {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_HorseMoveAdapter;
    virtual float ApplyTurnSlowdown(float speed, const S_HorseData* ctx) const = 0; // [0] 0x180A4E404
    virtual float ScaleDesiredSpeed(float speed, const S_HorseData* ctx) const = 0; // [1] 0x181ECC480
    virtual bool  AlwaysTrue() const = 0;                                          // [2] 0x18041A6A0
    virtual void  GetStickMagAndTurn(int32_t* mag, int32_t* turn) const = 0;       // [3] 0x180A4E3F0
    virtual Vec3* GetMoveDir(Vec3* out) const = 0;                                 // [4] 0x1813B7790
    virtual void  Update(S_HorseData* ctx, float dt) = 0;                          // [5] 0x180A4EAB4
    virtual void  Destroy(uint8_t dealloc) = 0;                                    // [6] 0x18100D28C
};
static_assert(sizeof(I_HorseMoveAdapter) == 8, "I_HorseMoveAdapter is vtable-only");

}  // namespace wh::entitymodule
