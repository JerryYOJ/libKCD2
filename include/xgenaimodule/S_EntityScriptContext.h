#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::xgenaimodule::S_EntityScriptContext
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------
// Strong string id: type-data sizeof 8, RTTR string converter, no extra members.

namespace wh {
namespace xgenaimodule {

struct S_EntityScriptContext {
    CryStringT<char> m_name;                              // +0x00
};

static_assert(offsetof(S_EntityScriptContext, m_name) == 0x00,
              "S_EntityScriptContext::m_name offset mismatch");
static_assert(sizeof(S_EntityScriptContext) == 0x08,
              "S_EntityScriptContext size mismatch");

}  // namespace xgenaimodule
}  // namespace wh
