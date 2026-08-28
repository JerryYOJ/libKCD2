#pragma once
#include <cstddef>
#include <cstdint>
#include "C_PhotomodeSettingBase.h"

namespace wh::game {

class C_PhotomodeSettingHiddenFloat : public C_PhotomodeSettingBase {
public:
    ~C_PhotomodeSettingHiddenFloat() override;
    RTTR_ENABLE(C_PhotomodeSettingBase)

    float m_value;                                          // +0x40 RTTR "Value"
    std::uint8_t _pad44[4];                                 // +0x44
};

static_assert(offsetof(C_PhotomodeSettingHiddenFloat, m_value) == 0x40,
              "C_PhotomodeSettingHiddenFloat::m_value offset mismatch");
static_assert(sizeof(C_PhotomodeSettingHiddenFloat) == 0x48,
              "C_PhotomodeSettingHiddenFloat size mismatch");

}  // namespace wh::game
