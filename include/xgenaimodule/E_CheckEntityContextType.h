#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule {

struct E_CheckEntityContextType {
    enum Type : std::uint8_t {
        All = 0,
        Any = 1,
    };
};
static_assert(sizeof(E_CheckEntityContextType::Type) == 1, "E_CheckEntityContextType::Type size mismatch");

}  // namespace wh::xgenaimodule
