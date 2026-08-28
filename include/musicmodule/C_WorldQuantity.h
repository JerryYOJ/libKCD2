#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"

namespace wh::musicmodule {

class C_WorldQuantity {
public:
    virtual ~C_WorldQuantity();                             // [0]
    RTTR_ENABLE()                                           // [1..3]

    std::uint32_t m_nameId;                                 // +0x08 accessor backing "Name"
    std::uint8_t _pad0C[4];                                 // +0x0C
    float m_defaultValue;                                   // +0x10 accessor backing "DefaultValue"
    std::uint8_t m_unknown14[8];                            // +0x14
    float m_thresholdDifference;                            // +0x1C RTTR "ThresholdDifference"
    CryStringT<char> m_atlRtpcName;                         // +0x20 RTTR "AtlRtpcName"
    std::uint8_t m_unknown28[8];                            // +0x28
};

static_assert(offsetof(C_WorldQuantity, m_nameId) == 0x08,
              "C_WorldQuantity::m_nameId offset mismatch");
static_assert(offsetof(C_WorldQuantity, m_defaultValue) == 0x10,
              "C_WorldQuantity::m_defaultValue offset mismatch");
static_assert(offsetof(C_WorldQuantity, m_thresholdDifference) == 0x1C,
              "C_WorldQuantity::m_thresholdDifference offset mismatch");
static_assert(offsetof(C_WorldQuantity, m_atlRtpcName) == 0x20,
              "C_WorldQuantity::m_atlRtpcName offset mismatch");
static_assert(sizeof(C_WorldQuantity) == 0x30,
              "C_WorldQuantity size mismatch");

}  // namespace wh::musicmodule
