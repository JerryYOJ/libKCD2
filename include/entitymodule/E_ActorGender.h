#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

enum class E_ActorGender : std::uint8_t {
    NotDefined = 0,
    Male       = 1,
    Female     = 2,
    Unisex     = 3,
};
static_assert(sizeof(E_ActorGender) == 1, "E_ActorGender size mismatch");

}  // namespace wh::entitymodule
