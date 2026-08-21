#include "combatmodule/S_CombatRPGHitRequest.h"
#include "Offsets/Offsets.h"

namespace wh::combatmodule {

S_CombatRPGHitRequest::S_CombatRPGHitRequest(
    S_CombatCollisionDetails* pDetails) noexcept
{
    using Fn = S_CombatRPGHitRequest*(__fastcall*)(
        S_CombatRPGHitRequest*, S_CombatCollisionDetails*);
    static REL::Relocation<Fn> fn{ REL::ID(71505) };
    fn(this, pDetails);
}

}  // namespace wh::combatmodule
