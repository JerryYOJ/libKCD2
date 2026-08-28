#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

struct E_TriggerEffectMode {
    enum Type : std::uint8_t {
        Off                       = 0,
        Feedback                  = 1,
        Weapon                    = 2,
        Vibration                 = 3,
        MultiplePositionFeedback  = 4,
        SlopeFeedback             = 5,
        MultiplePositionVibration = 6,
    };
};
static_assert(sizeof(E_TriggerEffectMode::Type) == 1, "E_TriggerEffectMode::Type size mismatch");
