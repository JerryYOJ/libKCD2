#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::playermodule {
class C_BlacksmithTempo {
public:
    RTTR_ENABLE()  // [0..2]
    std::int32_t m_range1;  // +0x8 RTTR "Range1"
    std::int32_t m_range2;  // +0xC RTTR "Range2"
    CryStringT<char> m_event;  // +0x10 RTTR "Event"
};

static_assert(offsetof(C_BlacksmithTempo, m_event) == 0x10, "C_BlacksmithTempo::m_event offset mismatch");
static_assert(offsetof(C_BlacksmithTempo, m_range2) == 0xc, "C_BlacksmithTempo::m_range2 offset mismatch");
static_assert(offsetof(C_BlacksmithTempo, m_range1) == 0x8, "C_BlacksmithTempo::m_range1 offset mismatch");
static_assert(sizeof(C_BlacksmithTempo) == 0x18, "C_BlacksmithTempo size mismatch");

}  // namespace wh::playermodule
