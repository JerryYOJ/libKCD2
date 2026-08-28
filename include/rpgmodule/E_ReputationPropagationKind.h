#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_ReputationPropagationKind {
    enum Type : std::uint8_t {
        Own        = 0,
        Ancestral  = 1,
        Relational = 2,
        Spatial    = 3,
    };
};
static_assert(sizeof(E_ReputationPropagationKind::Type) == 1, "E_ReputationPropagationKind::Type size mismatch");

}  // namespace wh::rpgmodule
