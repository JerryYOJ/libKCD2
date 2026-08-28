#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

enum class E_SequenceChatPosition : std::uint8_t {
    First           = 0,
    Second          = 1,
    Third           = 2,
    Fourth          = 3,
    Refusal         = 4,
    RefusalTimeout  = 5,
    RefusalDistance = 6,
    Any             = 7,
};
static_assert(sizeof(E_SequenceChatPosition) == 1, "E_SequenceChatPosition size mismatch");

}  // namespace wh::dialogmodule::data
