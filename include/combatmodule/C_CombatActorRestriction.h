#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include "C_CombatActorObject.h"
#include "E_CombatActionType.h"
#include "E_CombatAttackType.h"
#include "E_CombatInputClass.h"
#include "E_CombatZoneId.h"

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatActorRestriction final : public C_CombatActorObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatActorRestriction;
    explicit C_CombatActorRestriction(C_CombatActor* pOwner);
    ~C_CombatActorRestriction() override;

    void Reset() override;
    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::RESTRICTION;
    }
    const char* GetName() const override { return "Restriction"; }
    S_CombatActorObjectDebugLine GetDebugInfo() override;

    std::unordered_map<E_CombatActionType, std::uint32_t> m_rebuildStamps; // +0x10
};
static_assert(sizeof(C_CombatActorRestriction) == 0x50);
static_assert(alignof(C_CombatActorRestriction) == 0x08);
static_assert(offsetof(C_CombatActorRestriction, m_rebuildStamps) == 0x10);

}  // namespace wh::combatmodule
