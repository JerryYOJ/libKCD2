#pragma once
#include <cstddef>
#include <cstdint>
#include "C_CombatActorObject.h"
#include "S_NextGuardRequest.h"
#include "../CryEngine/CryCommon/TimeValue.h"

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatActorNextGuardSelector final : public C_CombatActorObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatActorNextGuardSelector;
    explicit C_CombatActorNextGuardSelector(C_CombatActor* pOwner);
    ~C_CombatActorNextGuardSelector() override;

    void Reset() override;
    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::NEXT_GUARD_SELECTOR;
    }
    const char* GetName() const override { return "NEXT_GUARD_SELECTOR"; }

    CTimeValue   m_zoneChangeAllowedAt;     // +0x10
    bool         m_useCommittedAttackZone;  // +0x18
    bool         m_applyingGuardZone;       // +0x19, recursion barrier
    bool         m_forceNextGuard;          // +0x1A
    std::uint8_t _pad1B[5];                 // +0x1B
};
static_assert(sizeof(C_CombatActorNextGuardSelector) == 0x20);
static_assert(offsetof(C_CombatActorNextGuardSelector, m_zoneChangeAllowedAt) == 0x10);
static_assert(offsetof(C_CombatActorNextGuardSelector, m_useCommittedAttackZone) == 0x18);
static_assert(offsetof(C_CombatActorNextGuardSelector, m_applyingGuardZone) == 0x19);

}  // namespace wh::combatmodule
