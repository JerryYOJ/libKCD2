#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/Cry_Math.h"

namespace wh::combatmodule {

struct S_CombatActorDataSolveInput {
    Vec2  m_control;          // +0x00, x tangential/orbital; y radial
    Vec3  m_targetPosition;   // +0x08
    float m_speedOverride;    // +0x14, zero uses combat movement settings
    float m_frameTime;        // +0x18
};
static_assert(sizeof(S_CombatActorDataSolveInput) == 0x1C);
static_assert(offsetof(S_CombatActorDataSolveInput, m_control) == 0x00);
static_assert(offsetof(S_CombatActorDataSolveInput, m_targetPosition) == 0x08);
static_assert(offsetof(S_CombatActorDataSolveInput, m_speedOverride) == 0x14);
static_assert(offsetof(S_CombatActorDataSolveInput, m_frameTime) == 0x18);

}  // namespace wh::combatmodule
