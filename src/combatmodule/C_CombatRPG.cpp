#include "combatmodule/C_CombatRPG.h"
#include "Offsets/Offsets.h"

namespace wh::combatmodule {

bool C_CombatRPG::ProcessCollisionHit(
    S_HitInfo& hitInfo,
    const S_CombatRPGHitRequest& request,
    S_MeleeHitDetails& details)
{
    using Fn = bool(__fastcall*)(C_CombatRPG*, S_HitInfo&,
                                  const S_CombatRPGHitRequest&,
                                  S_MeleeHitDetails&);
    static REL::Relocation<Fn> fn{ REL::ID(71501) };
    return fn(this, hitInfo, request, details);
}

bool C_CombatRPG::BuildAndSubmitMeleeHit(
    S_HitInfo& hitInfo,
    const float& attackStrength,
    bool& applyAttackerPostHitEffects,
    const S_CombatRPGHitRequest& request,
    bool processSecondary,
    E_CombatAttackType attackType,
    S_MeleeHitDetails& details)
{
    using Fn = bool(__fastcall*)(C_CombatRPG*, S_HitInfo&, const float&, bool&,
                                  const S_CombatRPGHitRequest&, bool,
                                  E_CombatAttackType, S_MeleeHitDetails&);
    static REL::Relocation<Fn> fn{ REL::ID(71599) };
    return fn(this, hitInfo, attackStrength, applyAttackerPostHitEffects,
              request, processSecondary, attackType, details);
}

}  // namespace wh::combatmodule
