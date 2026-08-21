#pragma once
#include <cstddef>
#include <cstdint>
#include "C_CombatActorUpdatedObject.h"
#include "E_GuardVariationState.h"
#include "I_CombatActorAction.h"
#include "../CryEngine/CryCommon/TimeValue.h"

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatActorGuardVarSystem final : public C_CombatActorUpdatedObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatActorGuardVarSystem;
    explicit C_CombatActorGuardVarSystem(C_CombatActor* pOwner);
    ~C_CombatActorGuardVarSystem() override;

    void Reset() override {} // [1] nullsub_1
    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::GUARD_VARIATION_SYSTEM;
    }
    const char* GetName() const override { return ""; }
    S_CombatActorObjectDebugLine GetDebugInfo() override;
    void UpdatePhase2() override;

    I_CombatActorActionPtr m_currentAction; // +0x18, owning
    CTimeValue m_oneShotAt;                 // +0x20
    CTimeValue m_nextUpdateAt;              // +0x28
    CTimeValue m_inhibitUntil;              // +0x30
    bool m_modelListenerRegistered;         // +0x38
    std::uint8_t _pad39[3];                 // +0x39
    E_GuardVariationState m_state;          // +0x3C
};
static_assert(sizeof(C_CombatActorGuardVarSystem) == 0x40);
static_assert(offsetof(C_CombatActorGuardVarSystem, m_currentAction) == 0x18);
static_assert(offsetof(C_CombatActorGuardVarSystem, m_oneShotAt) == 0x20);
static_assert(offsetof(C_CombatActorGuardVarSystem, m_inhibitUntil) == 0x30);
static_assert(offsetof(C_CombatActorGuardVarSystem, m_state) == 0x3C);

}  // namespace wh::combatmodule
