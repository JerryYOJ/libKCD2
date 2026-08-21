#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "S_CombatRPGHitSample.h"
#include "../entitymodule/E_HandSlot.h"

namespace wh::combatmodule {

class C_CombatActor;
struct S_CombatCollisionDetails;

struct S_CombatRPGHitRequest {
    explicit S_CombatRPGHitRequest(S_CombatCollisionDetails* pDetails) noexcept;

    bool                         m_bypassRepeatHitTimeout;    // +0x00
    bool                         m_collisionPairFlag;         // +0x01, producer metadata
    bool                         m_allowUnarmedWeakBlockPath; // +0x02
    bool                         m_forceTargetParryInPlace;   // +0x03
    std::int32_t                 m_itemBreakRngSeed;          // +0x04
    wh::entitymodule::E_HandSlot m_victimHandSlot;            // +0x08, None uses live blocking hand
    wh::entitymodule::E_HandSlot m_attackerHandSlot;          // +0x0C, None uses live attacking hand
    C_CombatActor*               m_pTarget;                    // +0x10, borrowed
    S_CombatCollisionDetails*    m_pDetails;                   // +0x18, borrowed
    std::vector<S_CombatRPGHitSample> m_samples;               // +0x20, owned
};
static_assert(sizeof(S_CombatRPGHitRequest) == 0x38);
static_assert(alignof(S_CombatRPGHitRequest) == 0x08);
static_assert(offsetof(S_CombatRPGHitRequest, m_bypassRepeatHitTimeout) == 0x00);
static_assert(offsetof(S_CombatRPGHitRequest, m_itemBreakRngSeed) == 0x04);
static_assert(offsetof(S_CombatRPGHitRequest, m_victimHandSlot) == 0x08);
static_assert(offsetof(S_CombatRPGHitRequest, m_attackerHandSlot) == 0x0C);
static_assert(offsetof(S_CombatRPGHitRequest, m_pTarget) == 0x10);
static_assert(offsetof(S_CombatRPGHitRequest, m_pDetails) == 0x18);
static_assert(offsetof(S_CombatRPGHitRequest, m_samples) == 0x20);

}  // namespace wh::combatmodule
