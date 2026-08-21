#pragma once
#include <cstddef>
#include <cstdint>
#include "C_CombatActorObject.h"

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatOpponentAimingListener final : public C_CombatActorObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatOpponentAimingListener;
    explicit C_CombatOpponentAimingListener(C_CombatActor* pOwner);
    ~C_CombatOpponentAimingListener() override;

    void Reset() override {} // [1] nullsub_1
    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::OPPONENT_AIMING;
    }
    const char* GetName() const override { return "OPPONENT_AIMING"; }

    bool         m_isSubscribed; // +0x10, procedural-aim signal attached
    std::uint8_t _pad11[7];      // +0x11
};
static_assert(sizeof(C_CombatOpponentAimingListener) == 0x18);
static_assert(offsetof(C_CombatOpponentAimingListener, m_isSubscribed) == 0x10);

}  // namespace wh::combatmodule
