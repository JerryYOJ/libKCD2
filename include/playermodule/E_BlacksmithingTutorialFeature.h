#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_BlacksmithingTutorialFeature {
    enum Type : std::uint8_t {
        InspectActionDisabled        = 0,
        InspectActionInvisible       = 1,
        MoveToAnvilActionDisabled    = 2,
        MoveToAnvilActionInvisible   = 3,
        MoveToForgeActionDisabled    = 4,
        MoveToForgeActionInvisible   = 5,
        ForgebagActionDisabled       = 6,
        ForgebagActionInvisible      = 7,
        ExitActionDisabled           = 8,
        ExitActionInvisible          = 9,
        FlipWorkpieceActionDisabled  = 10,
        FlipWorkpieceActionInvisible = 11,
        HeatLossDisabled             = 12,
    };
};
static_assert(sizeof(E_BlacksmithingTutorialFeature::Type) == 1, "E_BlacksmithingTutorialFeature::Type size mismatch");

}  // namespace wh::playermodule
