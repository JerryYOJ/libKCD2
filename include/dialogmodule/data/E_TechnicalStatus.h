#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

struct E_TechnicalStatus {
    enum Type : std::uint8_t {
        Disabled = 0,
        Enabled  = 1,
    };
};
static_assert(sizeof(E_TechnicalStatus::Type) == 1, "E_TechnicalStatus::Type size mismatch");

}  // namespace wh::dialogmodule::data
