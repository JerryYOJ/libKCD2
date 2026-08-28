#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

enum class E_SequenceEndType : std::uint8_t {
    EndTopic    = 0,
    EndDialogue = 1,
    GoTo        = 2,
    Decision    = 3,
};
static_assert(sizeof(E_SequenceEndType) == 1, "E_SequenceEndType size mismatch");

}  // namespace wh::dialogmodule::data
