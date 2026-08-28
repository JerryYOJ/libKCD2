#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_CartFollowerPart {
    enum Type : std::uint8_t {
        horsePivot     = 0,
        frontAxelPivot = 1,
        backAxelPivot  = 2,
    };
};
static_assert(sizeof(E_CartFollowerPart::Type) == 1, "E_CartFollowerPart::Type size mismatch");

}  // namespace wh::entitymodule
