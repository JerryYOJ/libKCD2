#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::rpgmodule::S_CharacterBodyDescription
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x28. No vtable.
// -----------------------------------------------

namespace wh::rpgmodule {

struct S_CharacterBodyDescription {
    CryStringT<char> m_body;                              // +0x00 RTTR "Body"
    CryStringT<char> m_head;                              // +0x08 RTTR "Head"
    CryStringT<char> m_hair;                              // +0x10 RTTR "Hair"
    CryStringT<char> m_beard;                             // +0x18 RTTR "Beard"
    CryStringT<char> m_underwear;                         // +0x20 RTTR "Underwear"
};

static_assert(offsetof(S_CharacterBodyDescription, m_body) == 0x00,
              "S_CharacterBodyDescription::m_body offset mismatch");
static_assert(offsetof(S_CharacterBodyDescription, m_head) == 0x08,
              "S_CharacterBodyDescription::m_head offset mismatch");
static_assert(offsetof(S_CharacterBodyDescription, m_hair) == 0x10,
              "S_CharacterBodyDescription::m_hair offset mismatch");
static_assert(offsetof(S_CharacterBodyDescription, m_beard) == 0x18,
              "S_CharacterBodyDescription::m_beard offset mismatch");
static_assert(offsetof(S_CharacterBodyDescription, m_underwear) == 0x20,
              "S_CharacterBodyDescription::m_underwear offset mismatch");
static_assert(sizeof(S_CharacterBodyDescription) == 0x28,
              "S_CharacterBodyDescription size mismatch");

}  // namespace wh::rpgmodule
