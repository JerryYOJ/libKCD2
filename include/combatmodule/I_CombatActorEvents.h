#pragma once
#include <cstddef>
#include "../framework/C_Signal.h"

namespace wh::combatmodule {

class I_CombatActor;

class I_CombatActorEvents {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_CombatActorEvents;
    using Delegate = wh::shared::S_Delegate<I_CombatActor&, I_CombatActor&>;

    virtual ~I_CombatActorEvents() = default; // [0]
    virtual void ConnectClinch(const Delegate& callback) = 0; // [1]
    virtual void DisconnectClinch(const Delegate& callback) = 0; // [2]
    virtual void ConnectMissedTarget(const Delegate& callback) = 0; // [3]
    virtual void DisconnectMissedTarget(const Delegate& callback) = 0; // [4]
    virtual void ConnectAttack(const Delegate& callback) = 0; // [5]
    virtual void DisconnectAttack(const Delegate& callback) = 0; // [6]
    virtual void ConnectPlayerDodge(const Delegate& callback) = 0; // [7]
    virtual void DisconnectPlayerDodge(const Delegate& callback) = 0; // [8]
    virtual void ConnectCombatIdle(const Delegate& callback) = 0; // [9]
    virtual void DisconnectCombatIdle(const Delegate& callback) = 0; // [10]
};
static_assert(sizeof(I_CombatActorEvents) == 0x08);

}  // namespace wh::combatmodule
