#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

// -----------------------------------------------
// wh::entitymodule::C_ItemHealthProvider -- item quality/health generator base
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x20, vtable 0x183A9DC88.
// -----------------------------------------------
// Vtable: [0] destructor, [1..3] own RTTR trio. All five fields are exact
// RTTR member-object pointers and duplicate registrations agree.

namespace wh::entitymodule {

class C_ItemHealthProvider {
public:
    virtual ~C_ItemHealthProvider();                  // [0] 0x180F857B8
    RTTR_ENABLE()                                     // [1..3], get_type 0x180D203A8

    std::uint32_t m_quality;                          // +0x08 RTTR "Quality"
    float m_health;                                   // +0x0C RTTR "Health"
    float m_healthVariation;                          // +0x10 RTTR "HealthVariation"
    float m_condition;                                // +0x14 RTTR "Condition"
    float m_conditionVariation;                       // +0x18 RTTR "ConditionVariation"
    std::uint8_t _pad1C[4];                          // +0x1C
};

static_assert(offsetof(C_ItemHealthProvider, m_quality) == 0x08,
              "C_ItemHealthProvider::m_quality offset mismatch");
static_assert(offsetof(C_ItemHealthProvider, m_conditionVariation) == 0x18,
              "C_ItemHealthProvider::m_conditionVariation offset mismatch");
static_assert(sizeof(C_ItemHealthProvider) == 0x20,
              "C_ItemHealthProvider size mismatch");

}  // namespace wh::entitymodule
