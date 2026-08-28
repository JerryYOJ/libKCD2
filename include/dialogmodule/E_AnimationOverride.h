#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule {

struct E_AnimationOverride {
    enum Type : std::int32_t {
        UserControlled               = 0,
        DialogControlled             = 1,
        NoOverride                   = 2,
        DialogControlledItemsAllowed = 3,
    };
};
static_assert(sizeof(E_AnimationOverride::Type) == 4, "E_AnimationOverride::Type size mismatch");

}  // namespace wh::dialogmodule
