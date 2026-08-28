#pragma once
#include <cstddef>
#include "C_CombatAnimationStepData.h"
#include "C_CombatTreeKeyIndexedDatabase.h"

namespace wh::combatmodule {

class C_CombatAnimationStepDatabase
    : public C_CombatTreeKeyIndexedDatabase<C_CombatAnimationStepData> {
public:
    ~C_CombatAnimationStepDatabase() override;                  // [0] 0x1827A4DD0
    RTTR_ENABLE(C_CombatTreeKeyIndexedDatabase<
        C_CombatAnimationStepData>)                             // [18..20]
};

static_assert(sizeof(C_CombatTreeKeyIndexedDatabase<
                  C_CombatAnimationStepData>) == 0x78,
              "C_CombatAnimationStepData database base size mismatch");
static_assert(sizeof(C_CombatAnimationStepDatabase) == 0x78,
              "C_CombatAnimationStepDatabase size mismatch");

}  // namespace wh::combatmodule
