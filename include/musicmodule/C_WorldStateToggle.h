#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::musicmodule {

class C_WorldStateToggle {
public:
    virtual ~C_WorldStateToggle();                        // [0]
    RTTR_ENABLE()                                         // [1..3]
    std::uint8_t m_unknown08[4];                          // +0x08
    bool m_overriding;                                    // +0x0C RTTR "Overriding"
    std::uint8_t _pad0D[3];                               // +0x0D
    float m_priority;                                     // +0x10 RTTR "Priority"
    bool m_visibleInSkald;                                // +0x14 RTTR "VisibleInSkald"
    bool m_useAsEvent;                                    // +0x15 RTTR "UseAsEvent"
    std::uint8_t _pad16[2];                               // +0x16
    std::int32_t m_defaultFlagCount;                      // +0x18 RTTR "DefaultFlagCount"
    std::uint8_t _pad1C[4];                               // +0x1C
    double m_flagDownDeferredBy;                          // +0x20 RTTR "FlagDownDeferredBy"
    std::uint8_t m_unknown28[0x10];                       // +0x28
};

static_assert(offsetof(C_WorldStateToggle, m_overriding) == 0x0C,
              "C_WorldStateToggle::m_overriding offset mismatch");
static_assert(offsetof(C_WorldStateToggle, m_flagDownDeferredBy) == 0x20,
              "C_WorldStateToggle::m_flagDownDeferredBy offset mismatch");
static_assert(sizeof(C_WorldStateToggle) == 0x38,
              "C_WorldStateToggle size mismatch");

}  // namespace wh::musicmodule
