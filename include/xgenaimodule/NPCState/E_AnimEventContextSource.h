#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule::NPCState {

struct E_AnimEventContextSource {
    enum Type : std::uint8_t {
        CurrentRequest = 0,
        Stance         = 1,
        Unstance       = 2,
        ActionSpecific = 3,
    };
};
static_assert(sizeof(E_AnimEventContextSource::Type) == 1, "E_AnimEventContextSource::Type size mismatch");

}  // namespace wh::xgenaimodule::NPCState
