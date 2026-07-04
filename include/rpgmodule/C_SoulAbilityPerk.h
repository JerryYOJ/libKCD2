#pragma once
#include <cstdint>
#include "C_Perk.h"

// -----------------------------------------------
// wh::rpgmodule::C_SoulAbilityPerk -- perk granting a soul ability (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// RTTI TD 0x184D53D08  vtable 0x183A38B28.  sizeof 0x40 (PROVEN: factory sub_18046B920
// operator new(64)). Ctor snapshots C_PerkSoulAbilityDatabase's sorted-index END pointer
// (qword @db+0xA0) into +0x30/+0x38 -- an initially-empty row range over the perk_soul_ability
// index [range reading INFERRED]. The abilities feed C_Soul's sorted ability block (+0x320).

namespace wh::rpgmodule {

class C_SoulAbilityPerk : public C_Perk {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_SoulAbilityPerk;
    void* m_rowsBegin;   // +0x30  ctor: db index end (empty range) [INFERRED]
    void* m_rowsEnd;     // +0x38  ctor: db index end
};
static_assert(sizeof(C_SoulAbilityPerk) == 0x40, "C_SoulAbilityPerk must be 0x40 (operator new(64))");

}  // namespace wh::rpgmodule
