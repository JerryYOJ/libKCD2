#pragma once
#include <cstddef>
#include <cstdint>
#include <map>
#include "C_CombatActorObject.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "../entitymodule/S_CombatShoutContext.h"
#include "../rpgmodule/E_CombatShoutType.h"

namespace wh::combatmodule {

class C_CombatActor;
class I_CombatActor;

class C_CombatEffects final : public C_CombatActorObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatEffects;
    explicit C_CombatEffects(C_CombatActor* pOwner);
    ~C_CombatEffects() override;

    void Reset() override {} // [1] nullsub_1
    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::EFFECTS;
    }
    const char* GetName() const override { return "Effects"; }

    wh::entitymodule::S_CombatShoutContext BuildCombatShoutContext(
        C_CombatActor& actor,
        I_CombatActor* pOtherActor,
        bool received);
    void DispatchCombatShout(
        wh::rpgmodule::E_CombatShoutType::Type type,
        const wh::entitymodule::S_CombatShoutContext& context);

    std::map<CryStringT<char>, std::uint32_t> m_materialAudioSwitchStateIds; // +0x10
    std::uint32_t m_specialTimeSlowdownTriggerId; // +0x20
    std::uint32_t m_specialTimeToNormalTriggerId; // +0x24
    std::uint32_t m_masterStrikeTriggerId;        // +0x28
    std::uint32_t m_perfectBlockTriggerId;        // +0x2C
};
static_assert(sizeof(C_CombatEffects) == 0x30);
static_assert(alignof(C_CombatEffects) == 0x08);
static_assert(offsetof(C_CombatEffects, m_materialAudioSwitchStateIds) == 0x10);
static_assert(offsetof(C_CombatEffects, m_specialTimeSlowdownTriggerId) == 0x20);
static_assert(offsetof(C_CombatEffects, m_specialTimeToNormalTriggerId) == 0x24);
static_assert(offsetof(C_CombatEffects, m_masterStrikeTriggerId) == 0x28);
static_assert(offsetof(C_CombatEffects, m_perfectBlockTriggerId) == 0x2C);

}  // namespace wh::combatmodule
