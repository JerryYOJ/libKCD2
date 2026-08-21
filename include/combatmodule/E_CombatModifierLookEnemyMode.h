#pragma once
#include <cstdint>

namespace wh::combatmodule {

// Reconstructed source spelling; the three-state domain and behavior are exact.
enum class E_CombatModifierLookEnemyMode : std::int32_t {
    Inactive       = 0,
    LookAtOpponent = 1,
    LookAtWeapon   = 2,
};
static_assert(sizeof(E_CombatModifierLookEnemyMode) == 0x04);

}  // namespace wh::combatmodule
