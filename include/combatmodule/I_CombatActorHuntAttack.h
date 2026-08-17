#pragma once
#include <cstdint>
#include "E_HuntAttackResult.h"

// -----------------------------------------------
// wh::combatmodule::I_CombatActorHuntAttack -- KCD2 WHGame.dll 1.5.6 (kd7u).
// -----------------------------------------------
// Secondary MI base of C_CombatActorHuntAttack (vtable 0x183A62DD0, 3 slots). TryHuntAttack runs
// the speed/distance/angle/RPG gates. Eligibility helper sub_18275CEA8 proves verdicts 0/1/2;
// Request re-checks for Approved, dispatches the sync attack, and returns boolean success.

namespace wh::combatmodule {

class I_CombatActorHuntAttack {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_CombatActorHuntAttack;
    virtual ~I_CombatActorHuntAttack() = default;                             // [0] thunk to primary dtor
    virtual E_HuntAttackResult TryHuntAttack(uint32_t victimEntityId) = 0;    // [1] sub_180A512B0
    virtual bool Request(uint32_t victimEntityId) = 0;                        // [2] sub_18275EB64
};

}  // namespace wh::combatmodule
