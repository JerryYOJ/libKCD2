#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::xgenaimodule::S_RelationScriptContext
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------
// Strong string id: type-data sizeof 8, RTTR string converter, no extra members.

namespace wh {
namespace xgenaimodule {

struct S_RelationScriptContext {
    CryStringT<char> m_name;                              // +0x00
};

static_assert(offsetof(S_RelationScriptContext, m_name) == 0x00,
              "S_RelationScriptContext::m_name offset mismatch");
static_assert(sizeof(S_RelationScriptContext) == 0x08,
              "S_RelationScriptContext size mismatch");

}  // namespace xgenaimodule
}  // namespace wh
