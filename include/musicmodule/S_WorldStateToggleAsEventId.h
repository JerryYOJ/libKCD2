#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::musicmodule::S_WorldStateToggleAsEventId
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------
// Strong string id: type-data sizeof 8, RTTR string converter, no extra members.

namespace wh {
namespace musicmodule {

struct S_WorldStateToggleAsEventId {
    CryStringT<char> m_name;                              // +0x00
};

static_assert(offsetof(S_WorldStateToggleAsEventId, m_name) == 0x00,
              "S_WorldStateToggleAsEventId::m_name offset mismatch");
static_assert(sizeof(S_WorldStateToggleAsEventId) == 0x08,
              "S_WorldStateToggleAsEventId size mismatch");

}  // namespace musicmodule
}  // namespace wh
