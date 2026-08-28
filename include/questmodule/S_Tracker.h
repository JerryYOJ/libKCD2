#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"

namespace wh::questmodule {

struct S_Tracker {
    RTTR_ENABLE()                                               // [0..2]

    CryStringT<char> ToString() const;                          // 0x182AEC718

    std::int32_t m_current;                                     // +0x08 RTTR "Current"
    std::int32_t m_total;                                       // +0x0C RTTR "Total"
};

static_assert(offsetof(S_Tracker, m_current) == 0x08,
              "S_Tracker::m_current offset mismatch");
static_assert(offsetof(S_Tracker, m_total) == 0x0C,
              "S_Tracker::m_total offset mismatch");
static_assert(sizeof(S_Tracker) == 0x10,
              "S_Tracker size mismatch");

}  // namespace wh::questmodule
