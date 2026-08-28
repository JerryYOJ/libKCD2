#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_GenericRandomEventType {
    enum Type : std::uint8_t {
        Frisk    = 0,
        Arrest   = 1,
        SelfHelp = 2,
        Combat   = 3,
        Enemy    = 4,
    };
};
static_assert(sizeof(E_GenericRandomEventType::Type) == 1, "E_GenericRandomEventType::Type size mismatch");

}  // namespace wh::playermodule
