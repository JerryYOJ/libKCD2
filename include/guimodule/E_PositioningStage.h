#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::guimodule {

struct E_PositioningStage {
    enum Type : std::uint8_t {
        None              = 0,
        InProgress        = 1,
        WaitingInPosition = 2,
    };
};
static_assert(sizeof(E_PositioningStage::Type) == 1, "E_PositioningStage::Type size mismatch");

}  // namespace wh::guimodule
