#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::playermodule::E_OutfitId -- KCD2 WHGame.dll 1.5.6 (kd7u).  Enum wrapper, Type : int32.
// -----------------------------------------------
// Player outfit/loadout slot (RTTR enumeration_wrapper<...E_OutfitId::Type,3,0>).
// Enumerators certified from the RTTR registration sub_18022F870 — the names are
// the single letters "A"/"B"/"C" (loadout slots). Message structs store it
// truncated to a byte (S_PlayerOutfitSwitchedData::m_newOutfit/m_oldOutfit).

namespace wh::playermodule {

struct E_OutfitId {
    enum Type : std::uint8_t {
        A = 0,
        B = 1,
        C = 2,
    };
};
static_assert(sizeof(E_OutfitId::Type) == 1,
              "E_OutfitId::Type size mismatch");

}  // namespace wh::playermodule
