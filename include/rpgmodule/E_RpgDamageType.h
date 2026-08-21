#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::rpgmodule::E_RpgDamageType -- KCD2 1.5.6 (kd7u).  4-byte enum.
// -----------------------------------------------
// rpg_damage_type row id from Libs/Tables/rpg/rpg_damage_type.xml. Distinct from
// E_DamageTypeMask (3-bit stab/slash/smash component mask). Id 3 is unused.
// C_CombatActor::GetRpgDamageTypeId resolves via combat_damage_type_mapping
// then C_CombatAttackTypeData::rpg_damage_type_id.

namespace wh::rpgmodule {

enum class E_RpgDamageType : int32_t {
    Invalid       = 0,  // "invalid"
    Stab          = 1,  // "stab"
    Slash         = 2,  // "slash"
    Smash         = 4,  // "smash"
    StabAndSmash  = 5,  // "stab&smash"
    SlashAndSmash = 6,  // "slash&smash"
};

}  // namespace wh::rpgmodule
