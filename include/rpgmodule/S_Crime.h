#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::rpgmodule::S_Crime
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x40. No vtable.
// -----------------------------------------------

namespace wh::rpgmodule {

struct S_Crime {
    CryStringT<char> m_label;                             // +0x00 RTTR "label"
    bool m_isCrime;                                       // +0x08 RTTR "isCrime"
    std::uint8_t _pad09[3];                               // +0x09
    std::int32_t m_importance;                            // +0x0C RTTR "importance"
    std::int32_t m_fine;                                  // +0x10 RTTR "fine"
    std::int32_t m_jail;                                  // +0x14 RTTR "jail"
    bool m_confiscation;                                  // +0x18 RTTR "confiscation"
    std::uint8_t _pad19[7];                               // +0x19
    CryStringT<char> m_metaroleLabel;                     // +0x20 RTTR "metaroleLabel"
    bool m_isViolent;                                     // +0x28 RTTR "isViolent"
    bool m_scalingWithSocialClass;                        // +0x29 RTTR "scalingWithSocialClass"
    std::uint8_t _pad2A[2];                               // +0x2A
    float m_expiration;                                   // +0x2C RTTR "expiration"
    bool m_isSpreadable;                                  // +0x30 RTTR "isSpreadable"
    std::uint8_t _pad31[7];                               // +0x31
    CryStringT<char> m_ui_name;                           // +0x38 RTTR "ui_name"
};

static_assert(offsetof(S_Crime, m_label) == 0x00,
              "S_Crime::m_label offset mismatch");
static_assert(offsetof(S_Crime, m_metaroleLabel) == 0x20,
              "S_Crime::m_metaroleLabel offset mismatch");
static_assert(offsetof(S_Crime, m_ui_name) == 0x38,
              "S_Crime::m_ui_name offset mismatch");
static_assert(sizeof(S_Crime) == 0x40,
              "S_Crime size mismatch");

}  // namespace wh::rpgmodule
