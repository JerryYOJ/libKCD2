#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::dialogmodule::S_DecisionAlias
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------
// Strong string id: type-data sizeof 8, RTTR string converter, no extra members.

namespace wh {
namespace dialogmodule {

struct S_DecisionAlias {
    CryStringT<char> m_name;                              // +0x00
};

static_assert(offsetof(S_DecisionAlias, m_name) == 0x00,
              "S_DecisionAlias::m_name offset mismatch");
static_assert(sizeof(S_DecisionAlias) == 0x08,
              "S_DecisionAlias size mismatch");

}  // namespace dialogmodule
}  // namespace wh
