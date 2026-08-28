#pragma once
#include <cstddef>
#include <cstdint>
#include "C_PhotomodeSettingBase.h"

namespace wh::game {

class C_PhotomodeSettingValue : public C_PhotomodeSettingBase {
public:
    ~C_PhotomodeSettingValue() override;
    RTTR_ENABLE(C_PhotomodeSettingBase)

    float m_default;                                        // +0x40 RTTR "Default"
    float m_min;                                            // +0x44 RTTR "Min"
    float m_max;                                            // +0x48 RTTR "Max"
    std::uint8_t _pad4C[4];                                 // +0x4C
};

static_assert(offsetof(C_PhotomodeSettingValue, m_default) == 0x40,
              "C_PhotomodeSettingValue::m_default offset mismatch");
static_assert(offsetof(C_PhotomodeSettingValue, m_max) == 0x48,
              "C_PhotomodeSettingValue::m_max offset mismatch");
static_assert(sizeof(C_PhotomodeSettingValue) == 0x50,
              "C_PhotomodeSettingValue size mismatch");

}  // namespace wh::game
