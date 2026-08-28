#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule::NPCState {

struct E_HumanHandHelperItemMode {
    enum Type : std::uint8_t {
        Ignore                = 0,
        AllowEmptyHandContent = 1,
        Include               = 2,
    };
};
static_assert(sizeof(E_HumanHandHelperItemMode::Type) == 1, "E_HumanHandHelperItemMode::Type size mismatch");

}  // namespace wh::xgenaimodule::NPCState
