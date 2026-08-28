#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"
#include "E_SkirmishEventRole.h"

namespace wh::rpgmodule {
class C_SkirmishEventRole {
public:
    RTTR_ENABLE()  // [0..2]
    E_SkirmishEventRole::Type m_name;  // +0x8 RTTR "Name"
    std::uint8_t m_unknown09[0xF];                  // +0x9
    float m_barkingWeight;  // +0x18 RTTR "BarkingWeight"
    std::int32_t m_moraleChangeId;  // +0x1C RTTR "MoraleChangeId"
    std::uint8_t m_unknown20[0x8];                  // +0x20
};

static_assert(offsetof(C_SkirmishEventRole, m_moraleChangeId) == 0x1c, "C_SkirmishEventRole::m_moraleChangeId offset mismatch");
static_assert(offsetof(C_SkirmishEventRole, m_barkingWeight) == 0x18, "C_SkirmishEventRole::m_barkingWeight offset mismatch");
static_assert(offsetof(C_SkirmishEventRole, m_name) == 0x8, "C_SkirmishEventRole::m_name offset mismatch");
static_assert(sizeof(C_SkirmishEventRole) == 0x28, "C_SkirmishEventRole size mismatch");

}  // namespace wh::rpgmodule
