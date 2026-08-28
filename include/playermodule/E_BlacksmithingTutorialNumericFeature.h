#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_BlacksmithingTutorialNumericFeature {
    enum Type : std::uint8_t {
        QualityLossFactor     = 0,
        CompletiongGainFactor = 1,
        TemperatureLossFactor = 2,
        MaxZoneTemperature    = 3,
        MoveWorkpieceInForge  = 4,
        MoveWorkpieceOnAnvil  = 5,
        StrokeEnabled         = 6,
        ForgeBagEnabled       = 7,
        WorkpieceCannotBreak  = 8,
    };
};
static_assert(sizeof(E_BlacksmithingTutorialNumericFeature::Type) == 1, "E_BlacksmithingTutorialNumericFeature::Type size mismatch");

}  // namespace wh::playermodule
