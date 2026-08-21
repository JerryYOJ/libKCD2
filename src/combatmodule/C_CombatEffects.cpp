#include "combatmodule/C_CombatEffects.h"
#include "Offsets/Offsets.h"

#include <new>
#include <type_traits>
#include <utility>

namespace wh::combatmodule {

wh::entitymodule::S_CombatShoutContext C_CombatEffects::BuildCombatShoutContext(
    C_CombatActor& actor,
    I_CombatActor* pOtherActor,
    bool received)
{
    using Result = wh::entitymodule::S_CombatShoutContext;
    using Storage = std::aligned_storage_t<sizeof(Result), alignof(Result)>;
    using Fn = Result*(__fastcall*)(C_CombatEffects*, Result*, C_CombatActor&,
                                    I_CombatActor*, bool);
    static REL::Relocation<Fn> fn{ REL::ID(71569) };

    Storage storage;
    auto* pResult = reinterpret_cast<Result*>(&storage);
    fn(this, pResult, actor, pOtherActor, received);

    Result result(std::move(*pResult));
    pResult->~Result();
    return result;
}

void C_CombatEffects::DispatchCombatShout(
    wh::rpgmodule::E_CombatShoutType::Type type,
    const wh::entitymodule::S_CombatShoutContext& context)
{
    using Fn = void(__fastcall*)(C_CombatEffects*,
                                 wh::rpgmodule::E_CombatShoutType::Type,
                                 const wh::entitymodule::S_CombatShoutContext&);
    static REL::Relocation<Fn> fn{ REL::ID(59989) };
    fn(this, type, context);
}

}  // namespace wh::combatmodule
