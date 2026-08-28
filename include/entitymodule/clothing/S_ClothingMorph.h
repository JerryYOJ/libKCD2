#pragma once
#include <cstddef>
#include "../../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::entitymodule::clothing::S_ClothingMorph
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------

namespace wh::entitymodule::clothing {

struct S_ClothingMorph {
    CryStringT<char> m_name;                              // +0x00 RTTR "Name"
};

static_assert(offsetof(S_ClothingMorph, m_name) == 0x00,
              "S_ClothingMorph::m_name offset mismatch");
static_assert(sizeof(S_ClothingMorph) == 0x08,
              "S_ClothingMorph size mismatch");

}  // namespace wh::entitymodule::clothing
