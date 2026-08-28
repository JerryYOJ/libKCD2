#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

struct E_DecisionEntryGrayOutMode {
    enum Type : std::uint8_t {
        All   = 0,
        Any   = 1,
        Never = 2,
    };
};
static_assert(sizeof(E_DecisionEntryGrayOutMode::Type) == 1, "E_DecisionEntryGrayOutMode::Type size mismatch");

}  // namespace wh::dialogmodule::data
