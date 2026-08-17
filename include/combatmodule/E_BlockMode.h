#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::combatmodule::E_BlockMode -- KCD2 WHGame.dll 1.5.6. 4-byte enum.
// -----------------------------------------------
// S_CombatActorState+0x650 value. Writers prove 0 = inactive/reset,
// 1 = normal block context, and 2 = C_CombatActorActionFreeBlock active.

namespace wh::combatmodule::E_BlockMode {

enum Type : std::int32_t {
    None        = 0,
    NormalBlock = 1,
    FreeBlock   = 2,
};

}  // namespace wh::combatmodule::E_BlockMode
