#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::rpgmodule::S_MissileHitData -- payload of C_MissileHitCause (KCD2 WHGame.dll 1.5.6,
// kd7u).
// -----------------------------------------------
// sizeof 0x88 (PROVEN: factory sub_182D226AC tracked-alloc 144 = 8+136; copies 8x _OWORD
// @+0x08..+0x7F then qword @+0x88).  Blob mirror of a hit/damage descriptor (Vec3
// positions/direction, entity handles, damage floats, hit-part id candidates); field
// decomposition UNVERIFIED -- raw blob.  Factory returns the raw cause via *a1; caller
// sub_182D19080 wraps it in C_Event.

namespace wh::rpgmodule {

struct S_MissileHitData {
    uint8_t _raw[136];   // +0x00  hit descriptor (8x _OWORD + qword) [U fields]
};
static_assert(sizeof(S_MissileHitData) == 0x88, "S_MissileHitData must be 0x88 (136-byte ctor copy)");

}  // namespace wh::rpgmodule
