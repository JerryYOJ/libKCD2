#pragma once
#include <cstddef>
#include <unordered_map>
#include "C_CombatActorUpdatedObject.h"
#include "E_CombatTriggerChannel.h"
#include "S_SlotPlan.h"

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatActorSlotPlanner final : public C_CombatActorUpdatedObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatActorSlotPlanner;
    explicit C_CombatActorSlotPlanner(C_CombatActor* pOwner);
    ~C_CombatActorSlotPlanner() override;

    void Reset() override;
    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::SLOT_PLANNER;
    }
    const char* GetName() const override { return ""; }
    void UpdatePhase2() override;

    std::unordered_map<E_CombatTriggerChannel, S_SlotPlan> m_plans; // +0x18
};
static_assert(sizeof(C_CombatActorSlotPlanner) == 0x58);
static_assert(offsetof(C_CombatActorSlotPlanner, m_plans) == 0x18);

}  // namespace wh::combatmodule
