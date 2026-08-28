#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_BlacksmithConceptEvent {
    enum Type : std::uint8_t {
        Start         = 0,
        BeforeSuccess = 1,
        Success       = 2,
        Failed        = 3,
    };
};
static_assert(sizeof(E_BlacksmithConceptEvent::Type) == 1, "E_BlacksmithConceptEvent::Type size mismatch");

}  // namespace wh::playermodule
