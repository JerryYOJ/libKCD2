#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"

namespace wh::rpgmodule::storm {
class C_HasCombatLevel : public I_Selector {
public:
    ~C_HasCombatLevel() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    float m_minValue;  // +0x8 RTTR "minValue"
    float m_maxValue;  // +0xC RTTR "maxValue"
};

static_assert(offsetof(C_HasCombatLevel, m_maxValue) == 0xc, "C_HasCombatLevel::m_maxValue offset mismatch");
static_assert(offsetof(C_HasCombatLevel, m_minValue) == 0x8, "C_HasCombatLevel::m_minValue offset mismatch");
static_assert(sizeof(C_HasCombatLevel) == 0x10, "C_HasCombatLevel size mismatch");

}  // namespace wh::rpgmodule::storm
