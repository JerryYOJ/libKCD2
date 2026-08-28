#pragma once
#include <cstddef>
#include <cstdint>
#include "C_PhotomodeSettingBase.h"

namespace wh::game {

class C_PhotomodeSettingHiddenInt : public C_PhotomodeSettingBase {
public:
    ~C_PhotomodeSettingHiddenInt() override;
    RTTR_ENABLE(C_PhotomodeSettingBase)

    int m_value;                                            // +0x40 RTTR "Value"
    std::uint8_t _pad44[4];                                 // +0x44
};

static_assert(offsetof(C_PhotomodeSettingHiddenInt, m_value) == 0x40,
              "C_PhotomodeSettingHiddenInt::m_value offset mismatch");
static_assert(sizeof(C_PhotomodeSettingHiddenInt) == 0x48,
              "C_PhotomodeSettingHiddenInt size mismatch");

}  // namespace wh::game
