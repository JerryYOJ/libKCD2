#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::musicmodule::S_WorldStateToggleId
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------
// Strong string id: type-data sizeof 8, RTTR string converter, no extra members.

namespace wh {
namespace musicmodule {

struct S_WorldStateToggleId {
    CryStringT<char> m_name;                              // +0x00
};

static_assert(offsetof(S_WorldStateToggleId, m_name) == 0x00,
              "S_WorldStateToggleId::m_name offset mismatch");
static_assert(sizeof(S_WorldStateToggleId) == 0x08,
              "S_WorldStateToggleId size mismatch");

}  // namespace musicmodule
}  // namespace wh
