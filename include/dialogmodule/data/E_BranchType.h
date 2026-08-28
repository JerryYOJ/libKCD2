#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

enum class E_BranchType : std::uint8_t {
    normal         = 0,
    obsolete       = 1,
    greeting       = 2,
    monolog        = 3,
    ingame         = 4,
    ingame_monolog = 5,  // RTTR label "ingame monolog"
    denial         = 6,
    chat           = 7,
};
static_assert(sizeof(E_BranchType) == 1, "E_BranchType size mismatch");

}  // namespace wh::dialogmodule::data
