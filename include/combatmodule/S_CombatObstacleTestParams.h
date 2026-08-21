#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Geo.h"

namespace wh::combatmodule {

struct S_CombatObstacleTestParams {
    std::int32_t  m_variant;      // +0x00
    std::uint32_t m_entityId;     // +0x04
    Vec3          m_position;     // +0x08
    Vec3          m_direction;    // +0x14
    OBB           m_shape;        // +0x20, caller-provided for kind 2
    float         m_extentPadding;// +0x5C, default 2
    float         m_probeRange;   // +0x60, default 0
};
static_assert(sizeof(OBB) == 0x3C);
static_assert(sizeof(S_CombatObstacleTestParams) == 0x64);
static_assert(offsetof(S_CombatObstacleTestParams, m_variant) == 0x00);
static_assert(offsetof(S_CombatObstacleTestParams, m_entityId) == 0x04);
static_assert(offsetof(S_CombatObstacleTestParams, m_position) == 0x08);
static_assert(offsetof(S_CombatObstacleTestParams, m_direction) == 0x14);
static_assert(offsetof(S_CombatObstacleTestParams, m_shape) == 0x20);
static_assert(offsetof(S_CombatObstacleTestParams, m_extentPadding) == 0x5C);
static_assert(offsetof(S_CombatObstacleTestParams, m_probeRange) == 0x60);

}  // namespace wh::combatmodule
