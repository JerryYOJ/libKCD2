#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

class S_CatWaypointDefinition {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_S_CatWaypointDefinition;

    RTTR_ENABLE() // [0..2]

    Vec3 m_position;          // +0x08, reflected as Position
    bool m_flag14;            // +0x14, role OPEN
    bool m_flag15;            // +0x15, role OPEN
    std::uint8_t _pad16[2];   // +0x16
};

static_assert(sizeof(S_CatWaypointDefinition) == 0x18,
              "S_CatWaypointDefinition must be 0x18");
static_assert(offsetof(S_CatWaypointDefinition, m_position) == 0x08,
              "cat waypoint position must be at 0x08");
static_assert(offsetof(S_CatWaypointDefinition, m_flag14) == 0x14,
              "cat waypoint flag must be at 0x14");

}  // namespace wh::entitymodule
