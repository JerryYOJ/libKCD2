#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::playermodule::E_AlchemyState::Type -- reflected alchemy game-state enum
// (KCD2 WHGame.dll Steam 1.5.6).
// -----------------------------------------------
// Identity, exact labels/values, and unsigned-byte underlying type are RTTR-proven.

namespace wh::playermodule {

struct E_AlchemyState {
    enum Type : std::uint8_t {
        E_GS_INIT              = 0,
        E_GS_EXACT_POSITIONING = 1,
        E_GS_IDLE              = 2,
        E_GS_MORTAR            = 3,
        E_GS_READING           = 4,
        E_GS_DISTILLATION      = 5,
        E_GS_CLEANUP_REQUEST   = 6,
        E_GS_CLEANING          = 7,
        E_GS_ENDED             = 8,
        E_GS_OPEN_INVENTORY    = 9,
        E_GS_LAST              = 10,
    };
};
static_assert(sizeof(E_AlchemyState::Type) == 1,
              "E_AlchemyState::Type size mismatch");

}  // namespace wh::playermodule
