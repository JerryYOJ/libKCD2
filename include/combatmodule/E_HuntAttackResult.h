#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::combatmodule::E_HuntAttackResult -- KCD2 WHGame.dll 1.5.6. 4-byte enum.
// -----------------------------------------------
// Eligibility helper sub_18275CEA8 returns all three values; Request proceeds only on Approved.

namespace wh::combatmodule {

enum class E_HuntAttackResult : std::int32_t {
    Blocked  = 0,
    Denied   = 1,
    Approved = 2,
};

}  // namespace wh::combatmodule
