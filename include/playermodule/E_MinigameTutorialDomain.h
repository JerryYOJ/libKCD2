#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_MinigameTutorialDomain {
    enum Type : std::uint8_t {
        Blacksmithing = 0,
        Alchemy       = 1,
    };
};
static_assert(sizeof(E_MinigameTutorialDomain::Type) == 1, "E_MinigameTutorialDomain::Type size mismatch");

}  // namespace wh::playermodule
