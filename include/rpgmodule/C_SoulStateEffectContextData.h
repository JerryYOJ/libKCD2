#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"
#include "E_SoulStateEffectContext.h"

namespace wh::rpgmodule {
class C_SoulStateEffectContextData {
public:
    RTTR_ENABLE()  // [0..2]
    E_SoulStateEffectContext::Type m_id;  // +0x8 RTTR "Id"
    std::uint8_t m_unknown09[0x3];                  // +0x9
    float m_staminaRegenCooldown;  // +0xC RTTR "StaminaRegenCooldown"
};

static_assert(offsetof(C_SoulStateEffectContextData, m_staminaRegenCooldown) == 0xc, "C_SoulStateEffectContextData::m_staminaRegenCooldown offset mismatch");
static_assert(offsetof(C_SoulStateEffectContextData, m_id) == 0x8, "C_SoulStateEffectContextData::m_id offset mismatch");
static_assert(sizeof(C_SoulStateEffectContextData) == 0x10, "C_SoulStateEffectContextData size mismatch");

}  // namespace wh::rpgmodule
