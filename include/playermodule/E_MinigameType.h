#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::playermodule::E_MinigameType -- KCD2 WHGame.dll 1.5.6 (kd7u).
// -----------------------------------------------
// Nested-Type enum wrapper (RTTR enumeration_wrapper<...E_MinigameType::Type,14,0>).
// The session factory sub_1809F0234 consumes the type as uint8_t, and every constant
// GetMinigameType override writes AL only (for example C_HerbGathering sub_181A78EA0).

namespace wh::playermodule {

struct E_MinigameType {
    enum Type : uint8_t {
        Undefined     = 0,
        Sharpening    = 1,
        Reading       = 2,
        Alchemy       = 3,
        HerbGathering = 4,
        LockPicking   = 5,
        HoleDigging   = 6,
        Dice          = 7,
        Pickpocketing = 8,
        StoneThrowing = 9,
        BattleArchery = 10,
        Distract      = 11,
        Blacksmithing = 12,
        ForgeBuilder  = 13,
    };
};
static_assert(sizeof(E_MinigameType::Type) == 1,
              "E_MinigameType::Type must match AL-only virtual returns");

}  // namespace wh::playermodule
