#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::xgenaimodule::E_SmartBehaviorState::Type -- smart-behavior override state
// (KCD2 WHGame.dll Steam 1.5.6).
// -----------------------------------------------
// Identity, exact labels/values, and unsigned-byte underlying type are RTTR-proven.

namespace wh::xgenaimodule {

struct E_SmartBehaviorState {
    enum Type : std::uint8_t {
        Enabled           = 0,
        NoRequests        = 1,
        Disabled          = 2,
        RequestsByHolders = 3,
    };
};
static_assert(sizeof(E_SmartBehaviorState::Type) == 1,
              "E_SmartBehaviorState::Type size mismatch");

}  // namespace wh::xgenaimodule
