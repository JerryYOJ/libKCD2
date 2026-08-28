#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::entitymodule::S_ArmorSurfaceName
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------
// Strong string id: type-data sizeof 8, RTTR string converter, no extra members.

namespace wh {
namespace entitymodule {

struct S_ArmorSurfaceName {
    CryStringT<char> m_name;                              // +0x00
};

static_assert(offsetof(S_ArmorSurfaceName, m_name) == 0x00,
              "S_ArmorSurfaceName::m_name offset mismatch");
static_assert(sizeof(S_ArmorSurfaceName) == 0x08,
              "S_ArmorSurfaceName size mismatch");

}  // namespace entitymodule
}  // namespace wh
