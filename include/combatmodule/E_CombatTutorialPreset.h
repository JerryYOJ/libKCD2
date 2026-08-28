#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::combatmodule {

struct E_CombatTutorialPreset {
    enum Type : std::uint8_t {
        TutorAutomations = 0,
    };
};
static_assert(sizeof(E_CombatTutorialPreset::Type) == 1, "E_CombatTutorialPreset::Type size mismatch");

}  // namespace wh::combatmodule
