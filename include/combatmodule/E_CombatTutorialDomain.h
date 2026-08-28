#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::combatmodule {

struct E_CombatTutorialDomain {
    enum Type : std::uint8_t {
        Basic        = 0,
        Advanced     = 1,
        MasterStrike = 2,
        Generic      = 3,
    };
};
static_assert(sizeof(E_CombatTutorialDomain::Type) == 1, "E_CombatTutorialDomain::Type size mismatch");

}  // namespace wh::combatmodule
