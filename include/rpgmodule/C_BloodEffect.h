#pragma once
#include <cstdint>
#include "C_SoulEffect.h"

// -----------------------------------------------
// wh::rpgmodule::C_BloodEffect -- soul blood/dirt visual state change (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// RTTI TD 0x184D601F0  vtable 0x183A8B830.  sizeof 0x20 (PROVEN: factory sub_180C62C7C
// operator new(32)).  Ctor (owner, targetWuid, a4, a5) -- both 4-byte payloads.

namespace wh::rpgmodule {

class C_BloodEffect : public C_SoulEffect {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_BloodEffect;
    int32_t m_param18;   // +0x18  ctor arg 4 [role UNVERIFIED -- amount candidate]
    int32_t m_param1C;   // +0x1C  ctor arg 5 [role UNVERIFIED]
};
static_assert(sizeof(C_BloodEffect) == 0x20, "C_BloodEffect must be 0x20 (operator new(32))");

}  // namespace wh::rpgmodule
