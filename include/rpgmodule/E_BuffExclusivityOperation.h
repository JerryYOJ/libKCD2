#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_BuffExclusivityOperation {
    enum Type : std::uint8_t {
        RemovePrevious = 0,
        RemoveNew      = 1,
    };
};
static_assert(sizeof(E_BuffExclusivityOperation::Type) == 1, "E_BuffExclusivityOperation::Type size mismatch");

}  // namespace wh::rpgmodule
