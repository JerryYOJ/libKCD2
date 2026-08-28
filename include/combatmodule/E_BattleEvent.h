#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::combatmodule {

struct E_BattleEvent {
    enum Type : std::uint8_t {
        AddedSoul              = 0,
        RemovedSoul            = 1,
        DeadSoul               = 2,
        TransformationComplete = 3,
    };
};
static_assert(sizeof(E_BattleEvent::Type) == 1, "E_BattleEvent::Type size mismatch");

}  // namespace wh::combatmodule
