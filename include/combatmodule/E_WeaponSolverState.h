#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::combatmodule {

struct E_WeaponSolverState {
    enum Type : std::uint8_t {
        none    = 0,
        recoil  = 1,
        sliding = 2,
        recover = 3,
    };
};
static_assert(sizeof(E_WeaponSolverState::Type) == 1, "E_WeaponSolverState::Type size mismatch");

}  // namespace wh::combatmodule
