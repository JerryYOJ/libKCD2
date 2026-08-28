#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_AddDefaultItemMode {
    enum Type : std::int32_t {
        Create            = 0,
        Reclaim           = 1,
        EnsureThenDestroy = 2,
        EnsureThenKeep    = 3,
    };
};
static_assert(sizeof(E_AddDefaultItemMode::Type) == 4, "E_AddDefaultItemMode::Type size mismatch");

}  // namespace wh::entitymodule
