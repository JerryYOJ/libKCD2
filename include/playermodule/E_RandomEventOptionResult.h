#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_RandomEventOptionResult {
    enum Type : std::uint8_t {
        None    = 0,
        Fail    = 1,
        Success = 2,
    };
};
static_assert(sizeof(E_RandomEventOptionResult::Type) == 1, "E_RandomEventOptionResult::Type size mismatch");

}  // namespace wh::playermodule
