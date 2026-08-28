#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::xgenaimodule::S_GameScriptContext
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------
// Strong string id: type-data sizeof 8, RTTR string converter, no extra members.

namespace wh {
namespace xgenaimodule {

struct S_GameScriptContext {
    CryStringT<char> m_name;                              // +0x00
};

static_assert(offsetof(S_GameScriptContext, m_name) == 0x00,
              "S_GameScriptContext::m_name offset mismatch");
static_assert(sizeof(S_GameScriptContext) == 0x08,
              "S_GameScriptContext size mismatch");

}  // namespace xgenaimodule
}  // namespace wh
