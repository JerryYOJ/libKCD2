#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::playermodule::E_AlchemyInteractionState -- synthetic RE name for the
// 32-bit brewing interaction/station state used by C_Alchemy::GetEffectiveState.
// -----------------------------------------------
// This is deliberately distinct from the binary-reflected E_AlchemyState::Type.
// Values are recovered from the (state, verb) action factory and live consumers.

namespace wh::playermodule {

struct E_AlchemyInteractionState {
    enum Type : std::int32_t {
        HoldingBowl     = 0,
        HoldingMortar   = 2,
        HoldingMortar2  = 3,
        HoldingPot      = 5,
        HoldingHerb1    = 7,
        HoldingHerb2    = 8,
        HoldingHerb3    = 9,
        HoldingSpecial1 = 10,
        HoldingSpecial2 = 11,
        HoldingSpecial3 = 12,
        Idle            = 21,
    };
};
static_assert(sizeof(E_AlchemyInteractionState::Type) == 4,
              "E_AlchemyInteractionState::Type size mismatch");

}  // namespace wh::playermodule
