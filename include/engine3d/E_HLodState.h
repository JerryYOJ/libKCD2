#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::engine3d {

struct E_HLodState {
    enum Type : std::uint8_t {
        Hidden         = 0,
        Far            = 1,
        LoadingNear    = 2,
        DissolveToNear = 3,
        Near           = 4,
        LoadingFar     = 5,
        DissolveToFar  = 6,
    };
};
static_assert(sizeof(E_HLodState::Type) == 1, "E_HLodState::Type size mismatch");

}  // namespace wh::engine3d
