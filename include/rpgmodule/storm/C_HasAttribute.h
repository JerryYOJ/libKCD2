#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"
#include "../E_SoulProperty.h"

namespace wh::rpgmodule::storm {
class C_HasAttribute : public I_Selector {
public:
    ~C_HasAttribute() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    float m_minValue;  // +0x8 RTTR "minValue"
    float m_maxValue;  // +0xC RTTR "maxValue"
    E_SoulProperty::Type m_skill;  // +0x10 RTTR "skill"
    std::uint8_t m_unknown14[0x4];                  // +0x14
};

static_assert(offsetof(C_HasAttribute, m_skill) == 0x10, "C_HasAttribute::m_skill offset mismatch");
static_assert(offsetof(C_HasAttribute, m_maxValue) == 0xc, "C_HasAttribute::m_maxValue offset mismatch");
static_assert(offsetof(C_HasAttribute, m_minValue) == 0x8, "C_HasAttribute::m_minValue offset mismatch");
static_assert(sizeof(C_HasAttribute) == 0x18, "C_HasAttribute size mismatch");

}  // namespace wh::rpgmodule::storm
