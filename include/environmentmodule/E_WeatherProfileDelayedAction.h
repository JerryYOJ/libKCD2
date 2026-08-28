#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::environmentmodule {

struct E_WeatherProfileDelayedAction {
    enum Type : std::uint8_t {
        Hide           = 0,
        Unhide         = 1,
        DisableEmitter = 2,
    };
};
static_assert(sizeof(E_WeatherProfileDelayedAction::Type) == 1, "E_WeatherProfileDelayedAction::Type size mismatch");

}  // namespace wh::environmentmodule
