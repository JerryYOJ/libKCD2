#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_SaveGameWithNotificationState {
    enum Type : std::uint8_t {
        None    = 0,
        Pending = 1,
        Done    = 2,
    };
};
static_assert(sizeof(E_SaveGameWithNotificationState::Type) == 1, "E_SaveGameWithNotificationState::Type size mismatch");

}  // namespace wh::playermodule
