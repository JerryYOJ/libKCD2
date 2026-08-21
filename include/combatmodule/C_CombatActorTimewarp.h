#pragma once
#include <cstddef>
#include <cstdint>
#include "C_CombatActorUpdatedObject.h"
#include "S_CombatActorTimewarpConfiguration.h"
#include "../CryEngine/CryCommon/TimeValue.h"

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatActorTimewarp final : public C_CombatActorUpdatedObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatActorTimewarp;
    explicit C_CombatActorTimewarp(C_CombatActor* pOwner);
    ~C_CombatActorTimewarp() override;

    void Reset() override {} // [1] nullsub_1
    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::TIME_WARP;
    }
    const char* GetName() const override { return "CombatActorTimewarp"; }
    void UpdatePhase3() override;

    bool         m_active;        // +0x18
    std::uint8_t _pad19[7];       // +0x19
    CTimeValue   m_activateAt;     // +0x20
    CTimeValue   m_fadeOutAt;      // +0x28
    S_CombatActorTimewarpConfiguration m_configuration; // +0x30
};
static_assert(sizeof(C_CombatActorTimewarp) == 0x48);
static_assert(offsetof(C_CombatActorTimewarp, m_active) == 0x18);
static_assert(offsetof(C_CombatActorTimewarp, m_activateAt) == 0x20);
static_assert(offsetof(C_CombatActorTimewarp, m_fadeOutAt) == 0x28);
static_assert(offsetof(C_CombatActorTimewarp, m_configuration) == 0x30);

}  // namespace wh::combatmodule
