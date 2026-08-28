#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule::scheduler {

struct E_InitializationMode {
    enum Type : std::uint8_t {
        Required = 0,
        Optional = 1,
    };
};
static_assert(sizeof(E_InitializationMode::Type) == 1, "E_InitializationMode::Type size mismatch");

}  // namespace wh::xgenaimodule::scheduler
