#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

struct E_ClashPriority {
    enum Type : std::uint8_t {
        Flavor                    = 0,
        OpenWorld                 = 1,
        BumpHitReaction           = 2,
        Quest                     = 3,
        CrimeLow                  = 4,
        Crime                     = 5,
        CrimeHigh                 = 6,
        CombatShout               = 7,
        Combat                    = 8,
        HitReaction               = 9,
        CombatChat                = 10,
        CombatChatOverride        = 11,
        CombatInstructions        = 12,
        NonFaderDialogAfterCombat = 13,
        DeathLow                  = 14,
        Death                     = 15,
        Technical                 = 16,
        Max                       = 17,
    };
};
static_assert(sizeof(E_ClashPriority::Type) == 1, "E_ClashPriority::Type size mismatch");

}  // namespace wh::dialogmodule::data
