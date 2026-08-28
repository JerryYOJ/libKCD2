#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

enum class E_ResponseVolume : std::uint8_t {
    Default = 0,
    Whisper = 1,
    Quietly = 2,
    Loudly  = 3,
    Shout   = 4,
    Roar    = 5,
};
static_assert(sizeof(E_ResponseVolume) == 1, "E_ResponseVolume size mismatch");

}  // namespace wh::dialogmodule::data
