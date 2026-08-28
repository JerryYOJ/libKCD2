#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

struct E_DialogInitiator {
    enum Type : std::uint8_t {
        Anyone    = 0,
        Player    = 1,
        NonPlayer = 2,
    };
};
static_assert(sizeof(E_DialogInitiator::Type) == 1, "E_DialogInitiator::Type size mismatch");

}  // namespace wh::dialogmodule::data
