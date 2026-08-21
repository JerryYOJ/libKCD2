#pragma once
#include <cstddef>
#include <cstdint>
#include "S_CatWaypointDefinition.h"

namespace wh::entitymodule {

struct S_CatWaypointRecord {
    inline static constexpr auto RTTI = Offsets::RTTI_S_CatWaypointRecord;
    std::uint8_t m_prefix00[0x10];           // +0x00, uint64 member offsets OPEN
    S_CatWaypointDefinition m_waypoint;      // +0x10, reflected as Waypoint
    std::uint8_t m_tail28[0x08];             // +0x28, field identity OPEN
};

static_assert(sizeof(S_CatWaypointRecord) == 0x30,
              "S_CatWaypointRecord must be 0x30");
static_assert(offsetof(S_CatWaypointRecord, m_waypoint) == 0x10,
              "cat waypoint definition must be at 0x10");

}  // namespace wh::entitymodule
