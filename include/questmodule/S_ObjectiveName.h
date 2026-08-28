#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::questmodule::S_ObjectiveName
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------
// Strong string id: type-data sizeof 8, RTTR string converter, no extra members.

namespace wh {
namespace questmodule {

struct S_ObjectiveName {
    CryStringT<char> m_name;                              // +0x00
};

static_assert(offsetof(S_ObjectiveName, m_name) == 0x00,
              "S_ObjectiveName::m_name offset mismatch");
static_assert(sizeof(S_ObjectiveName) == 0x08,
              "S_ObjectiveName size mismatch");

}  // namespace questmodule
}  // namespace wh
