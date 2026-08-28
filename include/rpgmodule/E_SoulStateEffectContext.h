#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_SoulStateEffectContext {
    enum Type : std::uint8_t {
        Default                       = 0,
        WeaponRaised                  = 1,
        Attack                        = 2,
        Dodge                         = 3,
        Hit                           = 4,
        Block                         = 5,
        BrokenBlock                   = 6,
        CollisionHit                  = 7,
        Jump                          = 8,
        FallDamage                    = 9,
        ArcherySelfHarm               = 10,
        SharpeningDoPedal             = 11,
        BlacksmithingStroke           = 12,
        BlacksmithingExhaustingStroke = 13,
    };
};
static_assert(sizeof(E_SoulStateEffectContext::Type) == 1, "E_SoulStateEffectContext::Type size mismatch");

}  // namespace wh::rpgmodule
