#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"

namespace wh::musicmodule {

class C_AddressKeyword {
public:
    virtual ~C_AddressKeyword();                            // [0]
    RTTR_ENABLE()                                           // [1..3]

    std::uint32_t m_nameId;                                 // +0x08 accessor backing "Name"
    std::uint32_t m_labelInLevelId;                         // +0x0C accessor backing "LabelInLevel"
    int m_weight;                                           // +0x10 RTTR "Weight"
    std::uint8_t _pad14[4];                                 // +0x14
    CryStringT<char> m_toggle;                              // +0x18 accessor backing "Toggle"
};

static_assert(offsetof(C_AddressKeyword, m_nameId) == 0x08,
              "C_AddressKeyword::m_nameId offset mismatch");
static_assert(offsetof(C_AddressKeyword, m_labelInLevelId) == 0x0C,
              "C_AddressKeyword::m_labelInLevelId offset mismatch");
static_assert(offsetof(C_AddressKeyword, m_weight) == 0x10,
              "C_AddressKeyword::m_weight offset mismatch");
static_assert(offsetof(C_AddressKeyword, m_toggle) == 0x18,
              "C_AddressKeyword::m_toggle offset mismatch");
static_assert(sizeof(C_AddressKeyword) == 0x20,
              "C_AddressKeyword size mismatch");

}  // namespace wh::musicmodule
