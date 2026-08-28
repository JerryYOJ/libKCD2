#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"
#include "../CryEngine/CryCommon/Cry_Color.h"

namespace wh::playermodule {
class C_BlacksmithTemperature {
public:
    RTTR_ENABLE()  // [0..2]
    float m_temperature;  // +0x8 RTTR "Temperature"
    ColorB m_color;  // +0xC RTTR "Color"
    float m_intensity;  // +0x10 RTTR "Intensity"
    float m_qualityLoss;  // +0x14 RTTR "QualityLoss"
};

static_assert(offsetof(C_BlacksmithTemperature, m_qualityLoss) == 0x14, "C_BlacksmithTemperature::m_qualityLoss offset mismatch");
static_assert(offsetof(C_BlacksmithTemperature, m_intensity) == 0x10, "C_BlacksmithTemperature::m_intensity offset mismatch");
static_assert(offsetof(C_BlacksmithTemperature, m_color) == 0xc, "C_BlacksmithTemperature::m_color offset mismatch");
static_assert(offsetof(C_BlacksmithTemperature, m_temperature) == 0x8, "C_BlacksmithTemperature::m_temperature offset mismatch");
static_assert(sizeof(C_BlacksmithTemperature) == 0x18, "C_BlacksmithTemperature size mismatch");

}  // namespace wh::playermodule
