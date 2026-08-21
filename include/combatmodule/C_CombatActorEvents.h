#pragma once
#include <cstddef>
#include "C_CombatActorUpdatedObject.h"
#include "I_CombatActorEvents.h"
#include "../CryEngine/CryCommon/TimeValue.h"
#include "../framework/C_Signal.h"

namespace wh::combatmodule {

class C_CombatActor;
class I_CombatActor;

class C_CombatActorEvents final
    : public C_CombatActorUpdatedObject
    , public I_CombatActorEvents {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatActorEvents;
    explicit C_CombatActorEvents(C_CombatActor* pOwner);
    ~C_CombatActorEvents() override;

    void Reset() override {} // primary [1] nullsub_1
    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::EVENTS;
    }
    const char* GetName() const override { return "EVENTS"; }
    void UpdatePhase2() override;

    void ConnectClinch(const Delegate& callback) override;
    void DisconnectClinch(const Delegate& callback) override;
    void ConnectMissedTarget(const Delegate& callback) override;
    void DisconnectMissedTarget(const Delegate& callback) override;
    void ConnectAttack(const Delegate& callback) override;
    void DisconnectAttack(const Delegate& callback) override;
    void ConnectPlayerDodge(const Delegate& callback) override;
    void DisconnectPlayerDodge(const Delegate& callback) override;
    void ConnectCombatIdle(const Delegate& callback) override;
    void DisconnectCombatIdle(const Delegate& callback) override;

    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&> m_onClinch;       // +0x20
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&> m_onMissedTarget; // +0x30
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&> m_onAttack;       // +0x40
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&> m_onPlayerDodge;  // +0x50
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&> m_onCombatIdle;   // +0x60
    CTimeValue m_combatIdleDeadline;                                        // +0x70
};
static_assert(sizeof(C_CombatActorEvents) == 0x78);
static_assert(offsetof(C_CombatActorEvents, m_onClinch) == 0x20);
static_assert(offsetof(C_CombatActorEvents, m_onCombatIdle) == 0x60);
static_assert(offsetof(C_CombatActorEvents, m_combatIdleDeadline) == 0x70);

}  // namespace wh::combatmodule
