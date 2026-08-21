#pragma once
#include <cstddef>
#include <cstdint>
#include <map>
#include <unordered_map>
#include "E_CombatAttackType.h"
#include "S_CombatRPGHitRequest.h"
#include "S_HitInfo.h"
#include "S_MeleeHitDetails.h"
#include "../CryEngine/CryCommon/TimeValue.h"

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatRPG final {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatRPG;
    explicit C_CombatRPG(C_CombatActor* pOwner);
    virtual ~C_CombatRPG(); // [0], sole virtual slot

    bool ProcessCollisionHit(S_HitInfo& hitInfo,
                             const S_CombatRPGHitRequest& request,
                             S_MeleeHitDetails& details);
    bool BuildAndSubmitMeleeHit(S_HitInfo& hitInfo,
                                const float& attackStrength,
                                bool& applyAttackerPostHitEffects,
                                const S_CombatRPGHitRequest& request,
                                bool processSecondary,
                                E_CombatAttackType attackType,
                                S_MeleeHitDetails& details);

    C_CombatActor* m_pOwner; // +0x08, borrowed
    std::unordered_map<std::uint32_t, CTimeValue> m_repeatHitDeadlines; // +0x10
    std::map<std::int32_t, float> m_skillProfileCoefficients;           // +0x50
};
static_assert(sizeof(C_CombatRPG) == 0x60);
static_assert(offsetof(C_CombatRPG, m_pOwner) == 0x08);
static_assert(offsetof(C_CombatRPG, m_repeatHitDeadlines) == 0x10);
static_assert(offsetof(C_CombatRPG, m_skillProfileCoefficients) == 0x50);

}  // namespace wh::combatmodule
