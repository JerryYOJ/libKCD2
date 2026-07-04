#pragma once
#include <cstdint>
#include "C_Perk.h"

// -----------------------------------------------
// wh::rpgmodule::C_CombatTechniquePerk -- perk unlocking a combat technique
// (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// RTTI TD 0x184D53DA8  vtable 0x183B562D0.  sizeof 0x40 (PROVEN: factory sub_1812E9240
// operator new(64)). Ctor snapshots C_PerkCombatTechniqueDatabase's sorted-index END pointer
// (qword @db+0xA0) into BOTH +0x30 and +0x38 -- an initially-empty row range over the
// perk_combat_technique index [range reading INFERRED].

namespace wh::rpgmodule {

class C_CombatTechniquePerk : public C_Perk {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatTechniquePerk;
    void* m_rowsBegin;   // +0x30  ctor: db index end (empty range) [INFERRED]
    void* m_rowsEnd;     // +0x38  ctor: db index end
};
static_assert(sizeof(C_CombatTechniquePerk) == 0x40, "C_CombatTechniquePerk must be 0x40 (operator new(64))");

}  // namespace wh::rpgmodule
