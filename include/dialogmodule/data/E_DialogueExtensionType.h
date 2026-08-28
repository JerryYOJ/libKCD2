#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

enum class E_DialogueExtensionType : std::uint8_t {
    None              = 0,
    Haggle            = 1,
    Barber            = 2,
    MapPlayerPosition = 3,
    ShieldPainting    = 4,
};
static_assert(sizeof(E_DialogueExtensionType) == 1, "E_DialogueExtensionType size mismatch");

}  // namespace wh::dialogmodule::data
