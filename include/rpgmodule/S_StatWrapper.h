#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::rpgmodule::S_StatWrapper
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------
// Strong string id: type-data sizeof 8, RTTR string converter, no extra members.

namespace wh {
namespace rpgmodule {

struct S_StatWrapper {
    CryStringT<char> m_name;                              // +0x00
};

static_assert(offsetof(S_StatWrapper, m_name) == 0x00,
              "S_StatWrapper::m_name offset mismatch");
static_assert(sizeof(S_StatWrapper) == 0x08,
              "S_StatWrapper size mismatch");

}  // namespace rpgmodule
}  // namespace wh
