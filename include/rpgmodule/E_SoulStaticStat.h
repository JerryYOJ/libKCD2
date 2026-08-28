#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

enum class E_SoulStaticStat : std::uint32_t {
    shadiness        = 0,
    combatLevel      = 1,
    initialDirtiness = 2,
};
static_assert(sizeof(E_SoulStaticStat) == 4, "E_SoulStaticStat size mismatch");

}  // namespace wh::rpgmodule
