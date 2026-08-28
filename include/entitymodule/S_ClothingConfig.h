#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"
#include "E_ActorGender.h"
#include "E_Race.h"

// -----------------------------------------------
// wh::entitymodule::S_ClothingConfig
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x50. No vtable.
// -----------------------------------------------

namespace wh::entitymodule {

struct S_ClothingConfig {
    CryStringT<char> m_name;                              // +0x00 RTTR "Name"
    E_Race::Type m_race;                                  // +0x08 RTTR "Race"
    E_ActorGender m_gender;                               // +0x0C RTTR "Gender"
    std::uint8_t _pad0D[3];                               // +0x0D
    CryStringT<char> m_uberlodRoot;                       // +0x10 RTTR "UberlodRoot"
    CryStringT<char> m_defaultBody;                       // +0x18 RTTR "DefaultBody"
    CryStringT<char> m_defaultHead;                       // +0x20 RTTR "DefaultHead"
    CryStringT<char> m_defaultHair;                       // +0x28 RTTR "DefaultHair"
    CryStringT<char> m_defaultBeard;                      // +0x30 RTTR "DefaultBeard"
    CryStringT<char> m_defaultClothingPreset;             // +0x38 RTTR "DefaultClothingPreset"
    CryStringT<char> m_carcass;                           // +0x40 RTTR "Carcass"
    bool m_headIsNeeded;                                  // +0x48 RTTR "HeadIsNeeded"
    bool m_removeHelmet;                                  // +0x49 RTTR "RemoveHelmet"
    std::uint8_t _pad4A[6];                               // +0x4A
};

static_assert(offsetof(S_ClothingConfig, m_name) == 0x00,
              "S_ClothingConfig::m_name offset mismatch");
static_assert(offsetof(S_ClothingConfig, m_carcass) == 0x40,
              "S_ClothingConfig::m_carcass offset mismatch");
static_assert(sizeof(S_ClothingConfig) == 0x50,
              "S_ClothingConfig size mismatch");

}  // namespace wh::entitymodule
