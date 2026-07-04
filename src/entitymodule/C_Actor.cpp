#include "entitymodule/C_Actor.h"
#include "Offsets/Offsets.h"

// C_Actor engine-function forwarders (KCD2 WHGame.dll 1.5.6 RVAs, verified in kd7u).

namespace wh::entitymodule {

wh::combatmodule::C_CombatActor* C_Actor::GetOrCreateCombatActor()
{
    // sub_18072DC90: returns m_pCombatActor (+0x278), allocating the 0x448 C_CombatActor
    // on first use.
    using Fn = wh::combatmodule::C_CombatActor* (__fastcall*)(C_Actor*);
    static REL::Relocation<Fn> fn{ REL::Offset(0x72DC90) };
    return fn(this);
}

}  // namespace wh::entitymodule
