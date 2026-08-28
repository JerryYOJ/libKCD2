#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::entitymodule::S_ShieldIngredientName
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------
// Strong string id: type-data sizeof 8, RTTR string converter, no extra members.

namespace wh {
namespace entitymodule {

struct S_ShieldIngredientName {
    CryStringT<char> m_name;                              // +0x00
};

static_assert(offsetof(S_ShieldIngredientName, m_name) == 0x00,
              "S_ShieldIngredientName::m_name offset mismatch");
static_assert(sizeof(S_ShieldIngredientName) == 0x08,
              "S_ShieldIngredientName size mismatch");

}  // namespace entitymodule
}  // namespace wh
