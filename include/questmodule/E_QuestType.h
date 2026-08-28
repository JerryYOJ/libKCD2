#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::questmodule {

enum class E_QuestType : std::int32_t {
    Main     = 0,
    Side     = 1,
    Activity = 2,
    Event    = 3,
    Micro    = 4,
    Racing   = 5,
};
static_assert(sizeof(E_QuestType) == 4, "E_QuestType size mismatch");

}  // namespace wh::questmodule
