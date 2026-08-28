#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule::NPCState {

struct E_ValidationMode {
    enum Type : std::uint8_t {
        ApplyNPCState   = 0,
        ApplyActorModel = 1,
        Validate        = 2,
    };
};
static_assert(sizeof(E_ValidationMode::Type) == 1, "E_ValidationMode::Type size mismatch");

}  // namespace wh::xgenaimodule::NPCState
