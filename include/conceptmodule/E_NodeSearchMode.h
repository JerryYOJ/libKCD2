#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::conceptmodule {

struct E_NodeSearchMode {
    enum Type : std::uint8_t {
        NonRecursive = 0,
        BFS          = 1,
        DFS          = 2,
    };
};
static_assert(sizeof(E_NodeSearchMode::Type) == 1, "E_NodeSearchMode::Type size mismatch");

}  // namespace wh::conceptmodule
