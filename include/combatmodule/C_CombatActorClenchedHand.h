#pragma once
#include <cstddef>
#include <cstdint>
#include "C_CombatActorUpdatedObject.h"
#include "../CryEngine/CryCommon/TimeValue.h"
#include "../CryEngine/CryCommon/smartptr.h"
#include "../entitymodule/E_HandSlot.h"

namespace wh::combatmodule {

class C_CombatActor;
class C_CombatAnimAction;

class C_CombatActorClenchedHand final : public C_CombatActorUpdatedObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatActorClenchedHand;
    explicit C_CombatActorClenchedHand(C_CombatActor* pOwner);
    ~C_CombatActorClenchedHand() override;

    void Reset() override {} // [1] nullsub_1
    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::CLENCHED_HAND;
    }
    const char* GetName() const override { return "CLENCHED_HAND"; }
    S_CombatActorObjectDebugLine GetDebugLabel() override;
    void UpdatePhase2() override;

    bool m_isActive;                                      // +0x18
    std::uint8_t _pad19[3];                              // +0x19
    wh::entitymodule::E_HandSlot m_activeHandSlot;       // +0x1C
    wh::entitymodule::E_HandSlot m_outgoingHandSlot;     // +0x20
    std::uint8_t _pad24[4];                              // +0x24
    _smart_ptr<C_CombatAnimAction> m_clenchActions[2];   // +0x28, owned
    CTimeValue m_releaseDeadlines[2];                    // +0x38
};
static_assert(sizeof(C_CombatActorClenchedHand) == 0x48);
static_assert(offsetof(C_CombatActorClenchedHand, m_isActive) == 0x18);
static_assert(offsetof(C_CombatActorClenchedHand, m_activeHandSlot) == 0x1C);
static_assert(offsetof(C_CombatActorClenchedHand, m_clenchActions) == 0x28);
static_assert(offsetof(C_CombatActorClenchedHand, m_releaseDeadlines) == 0x38);

}  // namespace wh::combatmodule
