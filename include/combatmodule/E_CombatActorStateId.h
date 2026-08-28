#pragma once
#include <cstdint>

namespace wh::combatmodule {

struct E_CombatActorStateId {
    enum Type : std::int32_t {
        Idle             = 0x001,
        Guard            = 0x002,
        ReadingToStrike  = 0x004,
        Striking         = 0x008,
        FailedAttack     = 0x010,
        Withdraw         = 0x020,
        Hit              = 0x040,
        PreparingToParry = 0x080,
        ParryInPlace     = 0x100,
        Dodge            = 0x200,
        Transition       = 0x400,
    };
};
static_assert(sizeof(E_CombatActorStateId::Type) == 4,
              "E_CombatActorStateId::Type size mismatch");

}  // namespace wh::combatmodule
