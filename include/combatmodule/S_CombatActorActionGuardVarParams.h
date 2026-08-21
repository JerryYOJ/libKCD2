#pragma once
#include <cstddef>

namespace wh::combatmodule {

struct S_CombatActionVariationData;

struct S_CombatActorActionGuardVarParams {
    const S_CombatActionVariationData* m_pVariation; // +0x00, borrowed database row
};
static_assert(sizeof(S_CombatActorActionGuardVarParams) == 0x08);
static_assert(offsetof(S_CombatActorActionGuardVarParams, m_pVariation) == 0x00);

}  // namespace wh::combatmodule
