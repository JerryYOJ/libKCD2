#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../rttr/rttr_enable.h"
#include "C_SkirmishEventRole.h"
#include "E_SkirmishEventType.h"

namespace wh::rpgmodule {

class C_SkirmishEventTypeData {
public:
    RTTR_ENABLE()                                         // [0..2]
    E_SkirmishEventType::Type m_eventType;                // +0x08 RTTR "EventType"
    std::uint8_t m_unknown09[0xF];                        // +0x09
    float m_barkingCooldown;                              // +0x18 RTTR "BarkingCooldown"
    std::uint8_t _pad1C[4];                               // +0x1C
    std::vector<C_SkirmishEventRole> m_roles;             // +0x20 RTTR "Roles"
    std::int32_t m_barkingPriority;                       // +0x38 RTTR "BarkingPriority"
    std::uint8_t _pad3C[4];                               // +0x3C
};

static_assert(offsetof(C_SkirmishEventTypeData, m_eventType) == 0x08,
              "C_SkirmishEventTypeData::m_eventType offset mismatch");
static_assert(offsetof(C_SkirmishEventTypeData, m_roles) == 0x20,
              "C_SkirmishEventTypeData::m_roles offset mismatch");
static_assert(sizeof(C_SkirmishEventTypeData) == 0x40,
              "C_SkirmishEventTypeData size mismatch");

}  // namespace wh::rpgmodule
