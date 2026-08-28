#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule::NPCState {

enum class E_DataSource : std::int32_t {
    CurrentState  = 0,
    RequiredState = 1,
};
static_assert(sizeof(E_DataSource) == 4, "E_DataSource size mismatch");

}  // namespace wh::xgenaimodule::NPCState
