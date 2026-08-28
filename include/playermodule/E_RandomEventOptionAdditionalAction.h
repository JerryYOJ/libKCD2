#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_RandomEventOptionAdditionalAction {
    enum Type : std::uint8_t {
        DismountHorse = 0,
    };
};
static_assert(sizeof(E_RandomEventOptionAdditionalAction::Type) == 1, "E_RandomEventOptionAdditionalAction::Type size mismatch");

}  // namespace wh::playermodule
