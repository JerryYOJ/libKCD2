#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::combatmodule {

struct E_UIComboGroup {
    enum Type : std::uint8_t {
        Longsword        = 0,
        Shortsword       = 1,
        ShortswordShield = 2,
        Blunt            = 3,
        BluntShield      = 4,
        Halberd          = 5,
        Unarmed          = 6,
    };
};
static_assert(sizeof(E_UIComboGroup::Type) == 1, "E_UIComboGroup::Type size mismatch");

}  // namespace wh::combatmodule
