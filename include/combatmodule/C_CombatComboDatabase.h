#pragma once
#include <cstddef>
#include "C_CombatCombo.h"
#include "C_CombatTreeKeyIndexedDatabase.h"

namespace wh::combatmodule {

class C_CombatComboDatabase
    : public C_CombatTreeKeyIndexedDatabase<C_CombatCombo> {
public:
    ~C_CombatComboDatabase() override;                          // [0] 0x1827A4E04
    RTTR_ENABLE(C_CombatTreeKeyIndexedDatabase<C_CombatCombo>) // [18..20]
};

static_assert(sizeof(C_CombatTreeKeyIndexedDatabase<
                  C_CombatCombo>) == 0x78,
              "C_CombatCombo database base size mismatch");
static_assert(sizeof(C_CombatComboDatabase) == 0x78,
              "C_CombatComboDatabase size mismatch");

}  // namespace wh::combatmodule
