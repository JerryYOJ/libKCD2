#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::playermodule::E_MinigameType -- KCD2 WHGame.dll 1.5.6 (kd7u).  Enum wrapper, Type : int32.
// -----------------------------------------------
// Nested-Type enum wrapper (RTTR enumeration_wrapper<...E_MinigameType::Type,14,0>).
// Enumerators certified from the RTTR registration sub_180227FD0. Message structs
// may store it truncated to a byte (S_GenericMinigameData::m_minigameType).

namespace wh::playermodule {

struct E_MinigameType {
    enum Type : int32_t {
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

}  // namespace wh::playermodule
