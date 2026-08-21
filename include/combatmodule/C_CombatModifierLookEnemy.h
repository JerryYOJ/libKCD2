#pragma once
#include <cstddef>
#include <cstdint>
#include "C_CombatActorUpdatedObject.h"
#include "E_CombatModifierLookEnemyMode.h"

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatModifierLookEnemy final : public C_CombatActorUpdatedObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatModifierLookEnemy;
    explicit C_CombatModifierLookEnemy(C_CombatActor* pOwner);
    ~C_CombatModifierLookEnemy() override;

    void Reset() override {} // [1] nullsub_1
    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::LOOK;
    }
    const char* GetName() const override { return "Look"; }
    S_CombatActorObjectDebugLine GetDebugInfo() override;
    void UpdatePhase2() override;

    E_CombatModifierLookEnemyMode m_mode;  // +0x18
    std::uint32_t                 _pad1C;   // +0x1C
};
static_assert(sizeof(C_CombatModifierLookEnemy) == 0x20);
static_assert(offsetof(C_CombatModifierLookEnemy, m_mode) == 0x18);

}  // namespace wh::combatmodule
