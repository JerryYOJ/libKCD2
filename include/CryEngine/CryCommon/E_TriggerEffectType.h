#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

struct E_TriggerEffectType {
    enum Type : std::uint8_t {
        Attack = 1,
        Basic  = 0,
        Block  = 2,
    };
};
static_assert(sizeof(E_TriggerEffectType::Type) == 1, "E_TriggerEffectType::Type size mismatch");
