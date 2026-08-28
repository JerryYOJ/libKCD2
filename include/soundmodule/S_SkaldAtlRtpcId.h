#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::soundmodule::S_SkaldAtlRtpcId
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------
// Strong string id: type-data sizeof 8, RTTR string converter, no extra members.

namespace wh {
namespace soundmodule {

struct S_SkaldAtlRtpcId {
    CryStringT<char> m_name;                              // +0x00
};

static_assert(offsetof(S_SkaldAtlRtpcId, m_name) == 0x00,
              "S_SkaldAtlRtpcId::m_name offset mismatch");
static_assert(sizeof(S_SkaldAtlRtpcId) == 0x08,
              "S_SkaldAtlRtpcId size mismatch");

}  // namespace soundmodule
}  // namespace wh
