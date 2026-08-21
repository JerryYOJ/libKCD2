#pragma once
#include <cstddef>
#include <cstdint>
#include "C_CombatActorUpdatedObject.h"
#include "I_CombatActorAction.h"
#include "../CryEngine/CryCommon/TimeValue.h"

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatActorClinch final : public C_CombatActorUpdatedObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatActorClinch;
    explicit C_CombatActorClinch(C_CombatActor* pOwner);
    ~C_CombatActorClinch() override;

    void Reset() override {} // [1] nullsub_1
    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::CLINCH;
    }
    const char* GetName() const override { return "CLINCH"; }
    void UpdatePhase2() override;
    void UpdatePhase3() override;

    bool m_isMaster;               // +0x18
    bool m_pairCreationInProgress; // +0x19
    bool m_retryPairCreation;      // +0x1A
    bool m_syncTransitionPending;  // +0x1B
    bool m_forceAvailable;         // +0x1C
    std::uint8_t _pad1D[3];        // +0x1D
    CTimeValue m_backoffAt;         // +0x20
};
static_assert(sizeof(C_CombatActorClinch) == 0x28);
static_assert(offsetof(C_CombatActorClinch, m_isMaster) == 0x18);
static_assert(offsetof(C_CombatActorClinch, m_forceAvailable) == 0x1C);
static_assert(offsetof(C_CombatActorClinch, m_backoffAt) == 0x20);

}  // namespace wh::combatmodule
