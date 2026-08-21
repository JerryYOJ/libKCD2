#pragma once
#include <cstddef>
#include <cstdint>
#include "C_CombatActorUpdatedObject.h"

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatModifierAim final : public C_CombatActorUpdatedObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatModifierAim;
    explicit C_CombatModifierAim(C_CombatActor* pOwner);
    ~C_CombatModifierAim() override;

    void Reset() override {} // [1] nullsub_1
    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::AIM;
    }
    const char* GetName() const override { return "Aim"; }
    S_CombatActorObjectDebugLine GetDebugInfo() override;
    void UpdatePhase2() override;

    bool         m_isActive;                // +0x18
    bool         m_hasActorCounter174Lease; // +0x19, no true writer found
    std::uint8_t _pad1A[6];                 // +0x1A
};
static_assert(sizeof(C_CombatModifierAim) == 0x20);
static_assert(offsetof(C_CombatModifierAim, m_isActive) == 0x18);
static_assert(offsetof(C_CombatModifierAim, m_hasActorCounter174Lease) == 0x19);

}  // namespace wh::combatmodule
