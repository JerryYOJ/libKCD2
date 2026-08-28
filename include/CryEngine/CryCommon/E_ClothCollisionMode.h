#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

struct E_ClothCollisionMode {
    enum Type : std::uint8_t {
        IterativeShortest  = 0,
        AlongSkinnedNormal = 1,
    };
};
static_assert(sizeof(E_ClothCollisionMode::Type) == 1, "E_ClothCollisionMode::Type size mismatch");
