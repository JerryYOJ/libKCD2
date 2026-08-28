#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"
#include "E_PhotomodeHDRVisibility.h"

namespace wh::game {

class C_PhotomodeUIElementBase {
public:
    virtual ~C_PhotomodeUIElementBase();                    // [0]
    RTTR_ENABLE()                                           // [1..3]

    CryStringT<char> m_unknown08;                           // +0x08 RTTR duplicate owner label
    int m_unknown10;                                        // +0x10 RTTR duplicate owner label
    bool m_unknown14;                                       // +0x14 RTTR duplicate owner label
    E_PhotomodeHDRVisibility::Type m_unknown15;             // +0x15 RTTR duplicate owner label
    std::uint8_t _pad16[2];                                 // +0x16
};

static_assert(offsetof(C_PhotomodeUIElementBase, m_unknown08) == 0x08,
              "C_PhotomodeUIElementBase::m_unknown08 offset mismatch");
static_assert(offsetof(C_PhotomodeUIElementBase, m_unknown10) == 0x10,
              "C_PhotomodeUIElementBase::m_unknown10 offset mismatch");
static_assert(offsetof(C_PhotomodeUIElementBase, m_unknown15) == 0x15,
              "C_PhotomodeUIElementBase::m_unknown15 offset mismatch");
static_assert(sizeof(C_PhotomodeUIElementBase) == 0x18,
              "C_PhotomodeUIElementBase size mismatch");

}  // namespace wh::game
