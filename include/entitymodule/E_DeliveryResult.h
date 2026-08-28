#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_DeliveryResult {
    enum Type : std::uint8_t {
        Success         = 0,
        Canceled        = 1,
        WrongItems      = 2,
        MissingItems    = 3,
        StolenMismatch  = 4,
        QualityMismatch = 5,
        PriceMismatch   = 6,
        Invalid         = 7,
    };
};
static_assert(sizeof(E_DeliveryResult::Type) == 1, "E_DeliveryResult::Type size mismatch");

}  // namespace wh::entitymodule
