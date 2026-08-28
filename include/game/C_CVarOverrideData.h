#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::game {
class C_CVarOverrideData {
public:
    RTTR_ENABLE()  // [0..2]
    CryStringT<char> m_gameContext;  // +0x8 RTTR "GameContext"
    std::int32_t m_cVarOverride;  // +0x10 RTTR "wh::game::CVarOverride"
    std::uint8_t m_unknown14[0x4];                  // +0x14
    CryStringT<char> m_overrideFile;  // +0x18 RTTR "OverrideFile"
};

static_assert(offsetof(C_CVarOverrideData, m_overrideFile) == 0x18, "C_CVarOverrideData::m_overrideFile offset mismatch");
static_assert(offsetof(C_CVarOverrideData, m_cVarOverride) == 0x10, "C_CVarOverrideData::m_cVarOverride offset mismatch");
static_assert(offsetof(C_CVarOverrideData, m_gameContext) == 0x8, "C_CVarOverrideData::m_gameContext offset mismatch");
static_assert(sizeof(C_CVarOverrideData) == 0x20, "C_CVarOverrideData size mismatch");

}  // namespace wh::game
