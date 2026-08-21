#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/Cry_Math.h"

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatActorData {
public:
    explicit C_CombatActorData(C_CombatActor* pOwner) noexcept;
    ~C_CombatActorData() = default;

    C_CombatActor* m_pOwner;                     // +0x00, borrowed
    Vec3           m_previousWorldPosition;      // +0x08
    Vec3           m_smoothedMovementCorrection; // +0x14
    Vec3           m_solvedMovementDirection;    // +0x20
    float          m_radialMovementInput;         // +0x2C
};
static_assert(sizeof(C_CombatActorData) == 0x30);
static_assert(alignof(C_CombatActorData) == 0x08);
static_assert(offsetof(C_CombatActorData, m_pOwner) == 0x00);
static_assert(offsetof(C_CombatActorData, m_previousWorldPosition) == 0x08);
static_assert(offsetof(C_CombatActorData, m_smoothedMovementCorrection) == 0x14);
static_assert(offsetof(C_CombatActorData, m_solvedMovementDirection) == 0x20);
static_assert(offsetof(C_CombatActorData, m_radialMovementInput) == 0x2C);

}  // namespace wh::combatmodule
