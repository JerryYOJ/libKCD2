#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::rpgmodule::S_CombatHitData -- payload of C_CombatHitCause (KCD2 WHGame.dll 1.5.6,
// kd7u).  Largest cause payload.
// -----------------------------------------------
// sizeof 0x90 (PROVEN: ctor sub_180726F08 tracked-alloc 152 = 8+144; bulk copy of
// 9x _OWORD @0x180726F73..FB7).  Verified fact: a 144-byte POD copied wholesale from a
// hit descriptor built above create-site sub_180726DF4; byte-level field breakdown
// UNVERIFIED -- mirrored as a raw blob.

namespace wh::rpgmodule {

struct S_CombatHitData {
    uint8_t _raw[144];   // +0x00  9x _OWORD hit descriptor [U fields]
};
static_assert(sizeof(S_CombatHitData) == 0x90, "S_CombatHitData must be 0x90 (144-byte ctor copy)");

}  // namespace wh::rpgmodule
