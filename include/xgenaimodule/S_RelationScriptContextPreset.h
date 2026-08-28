#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::xgenaimodule::S_RelationScriptContextPreset
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------
// Strong string id: type-data sizeof 8, RTTR string converter, no extra members.

namespace wh {
namespace xgenaimodule {

struct S_RelationScriptContextPreset {
    CryStringT<char> m_name;                              // +0x00
};

static_assert(offsetof(S_RelationScriptContextPreset, m_name) == 0x00,
              "S_RelationScriptContextPreset::m_name offset mismatch");
static_assert(sizeof(S_RelationScriptContextPreset) == 0x08,
              "S_RelationScriptContextPreset size mismatch");

}  // namespace xgenaimodule
}  // namespace wh
