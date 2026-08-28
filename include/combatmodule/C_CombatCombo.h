#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"
#include "C_CombatComboStep.h"
#include "E_UIComboGroup.h"

namespace wh::combatmodule {

class C_CombatCombo {
public:
    RTTR_ENABLE()                                               // [0..2]

    CryStringT<char> GetLeftWeapon() const;                    // 0x181437814
    void SetLeftWeapon(CryStringT<char> value);                // 0x180C5D508
    CryStringT<char> GetRightWeapon() const;                   // 0x181437814
    void SetRightWeapon(CryStringT<char> value);               // 0x180C5D54C
    CryStringT<char> GetId() const;                            // 0x1808F7CA0
    void SetId(CryStringT<char> value);                        // 0x180C5D6B0

    std::uint32_t m_idHash;                                    // +0x08 case-insensitive Id CRC
    std::uint8_t m_unknown0C[4];                               // +0x0C
    CryStringT<char> m_id;                                     // +0x10 accessor backing "Id"
    std::int32_t m_rightWeaponId;                              // +0x18 RightWeapon setter
    std::int32_t m_leftWeaponId;                               // +0x1C LeftWeapon setter
    std::int32_t m_rightWeaponVariantId;                       // +0x20 RightWeapon alternate context
    std::int32_t m_leftWeaponVariantId;                        // +0x24 LeftWeapon alternate context
    CryGUID m_combatTechniqueId;                               // +0x28 RTTR "CombatTechniqueId"
    E_UIComboGroup::Type m_uiGroup;                            // +0x38 RTTR "UIGroup"
    std::uint8_t m_unknown39[3];                               // +0x39
    int m_uiOrder;                                             // +0x3C RTTR "UIOrder"
    std::vector<C_CombatComboStep> m_combatComboSteps;         // +0x40 RTTR "CombatComboSteps"
};

static_assert(offsetof(C_CombatCombo, m_idHash) == 0x08,
              "C_CombatCombo::m_idHash offset mismatch");
static_assert(offsetof(C_CombatCombo, m_id) == 0x10,
              "C_CombatCombo::m_id offset mismatch");
static_assert(offsetof(C_CombatCombo, m_combatTechniqueId) == 0x28,
              "C_CombatCombo::m_combatTechniqueId offset mismatch");
static_assert(offsetof(C_CombatCombo, m_uiGroup) == 0x38,
              "C_CombatCombo::m_uiGroup offset mismatch");
static_assert(offsetof(C_CombatCombo, m_combatComboSteps) == 0x40,
              "C_CombatCombo::m_combatComboSteps offset mismatch");
static_assert(sizeof(C_CombatCombo) == 0x58,
              "C_CombatCombo size mismatch");

}  // namespace wh::combatmodule
