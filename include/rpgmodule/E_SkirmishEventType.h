#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_SkirmishEventType {
    enum Type : std::uint8_t {
        SoulAdded            = 0,
        SoulRemoved          = 1,
        SoulDied             = 2,
        SoulUnconscious      = 3,
        SoulFlee             = 4,
        SoulSurrender        = 5,
        HitTarget            = 6,
        MissedTarget         = 7,
        Attack               = 8,
        Clinch               = 9,
        Combo                = 10,
        MasterStrike         = 11,
        NormalBlock          = 12,
        PerfectBlock         = 13,
        TargetEscaped        = 14,
        TargetChanged        = 15,
        WeaponChanged        = 16,
        AimingOnFriend       = 17,
        SkirmishVictory      = 18,
        CombatIdle           = 19,
        PlayerFlee           = 20,
        WeaponDestroyed      = 21,
        GettingArmedSkirmish = 22,
        PlayerDodge          = 23,
        ChangingTorch        = 24,
    };
};
static_assert(sizeof(E_SkirmishEventType::Type) == 1, "E_SkirmishEventType::Type size mismatch");

}  // namespace wh::rpgmodule
