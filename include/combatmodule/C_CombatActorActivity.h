#pragma once
#include <cstddef>
#include "C_CombatActorObject.h"

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatActorActivity final : public C_CombatActorObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatActorActivity;
    explicit C_CombatActorActivity(C_CombatActor* pOwner);
    ~C_CombatActorActivity() override;

    void Reset() override {} // [1] nullsub_1
    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::COMBAT_ACTIVITY;
    }
    const char* GetName() const override { return "COMBAT_ACTIVITY"; }
};
static_assert(sizeof(C_CombatActorActivity) == 0x10);

}  // namespace wh::combatmodule
