#pragma once
#include <cstddef>
#include <cstdint>
#include "E_ActorGender.h"
#include "E_Race.h"

// -----------------------------------------------
// wh::entitymodule::S_Genderace
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------

namespace wh::entitymodule {

struct S_Genderace {
    E_ActorGender m_unisex;                               // +0x00 RTTR "Unisex"
    std::uint8_t _pad01[3];                               // +0x01
    E_Race::Type m_race;                                  // +0x04 RTTR "Race"
};

static_assert(offsetof(S_Genderace, m_unisex) == 0x00,
              "S_Genderace::m_unisex offset mismatch");
static_assert(offsetof(S_Genderace, m_race) == 0x04,
              "S_Genderace::m_race offset mismatch");
static_assert(sizeof(S_Genderace) == 0x08,
              "S_Genderace size mismatch");

}  // namespace wh::entitymodule
