#pragma once
#include <cstdint>
#include <cstddef>
#include "C_SoulStateEffect.h"
#include "../framework/WUID.h"

// -----------------------------------------------
// wh::rpgmodule::C_HealthValueEffect -- change soul health (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// RTTI TD 0x184D4EA98  vtable 0x183A8BD00.  sizeof 0x48 (ctor sub_180C66228 write extent;
// in-place ctor, allocation not observed).  : C_SoulStateEffect (m_valueId preset to
// E_SoulState::Health = 0).  Unlike its siblings it carries damage-attribution extras
// (source WUID init = the invalid constant qword_185330810).

namespace wh::rpgmodule {

class C_HealthValueEffect : public C_SoulStateEffect {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_HealthValueEffect;
    int32_t  m_unk30;                  // +0x30  ctor default -1 (DWORD store @0x180C6625E); creation paths (sub_180C66194/sub_180C65E64) leave it default -- no populating writer found, role/type UNVERIFIED
    uint32_t _pad34;                   // +0x34
    wh::framework::WUID m_sourceWuid;  // +0x38  ctor = invalid WUID (attacker/source candidate, UNVERIFIED)
    uint8_t  m_flag40;                 // +0x40  ctor 0
    uint8_t  _pad41[3];                // +0x41
    int32_t  m_unk44;                  // +0x44  ctor 0 (DWORD store @0x180C66276); no populating writer found in creation paths -- role/type UNVERIFIED
};
static_assert(sizeof(C_HealthValueEffect) == 0x48, "C_HealthValueEffect must be 0x48 (ctor write extent)");
static_assert(offsetof(C_HealthValueEffect, m_sourceWuid) == 0x38, "source wuid at 0x38");

}  // namespace wh::rpgmodule
