#pragma once
#include <cstddef>
#include <cstdint>
#include "E_CombatGuardType.h"

// -----------------------------------------------
// wh::combatmodule::S_OptionalCombatGuardType -- KCD2 1.5.6 (kd7u).  sizeof 8.
// -----------------------------------------------
// Arg of C_CombatActor::TryEnterCombat (vt[106] sub_180C5A1BC): if hasValue the
// id at +4 is used, else dword_185320CD4 ("none" / E_CombatGuardType::None).

namespace wh::combatmodule {

struct S_OptionalCombatGuardType {
    bool              hasValue;  // +0x00
    std::uint8_t      _pad[3];   // +0x01
    E_CombatGuardType value;     // +0x04
};
static_assert(sizeof(S_OptionalCombatGuardType) == 8);
static_assert(offsetof(S_OptionalCombatGuardType, hasValue) == 0);
static_assert(offsetof(S_OptionalCombatGuardType, value) == 4);

}  // namespace wh::combatmodule
