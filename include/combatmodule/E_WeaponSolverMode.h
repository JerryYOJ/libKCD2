#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::combatmodule {

struct E_WeaponSolverMode {
    enum Type : std::uint8_t {
        normal                = 0,
        normalWithPenetration = 1,
        stuck                 = 2,
        stuckWithPenetration  = 3,
        recoil                = 4,
        recoilWithPenetration = 5,
    };
};
static_assert(sizeof(E_WeaponSolverMode::Type) == 1, "E_WeaponSolverMode::Type size mismatch");

}  // namespace wh::combatmodule
