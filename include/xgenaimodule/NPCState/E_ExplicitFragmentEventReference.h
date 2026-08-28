#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule::NPCState {

struct E_ExplicitFragmentEventReference {
    enum Type : std::uint8_t {
        SetAsideSlot = 0,
        StanceObject = 1,
    };
};
static_assert(sizeof(E_ExplicitFragmentEventReference::Type) == 1, "E_ExplicitFragmentEventReference::Type size mismatch");

}  // namespace wh::xgenaimodule::NPCState
