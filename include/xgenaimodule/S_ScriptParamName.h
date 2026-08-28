#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::xgenaimodule::S_ScriptParamName
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------

namespace wh::xgenaimodule {

struct S_ScriptParamName {
    CryStringT<char> m_name;                              // +0x00 RTTR "Name"
};

static_assert(offsetof(S_ScriptParamName, m_name) == 0x00,
              "S_ScriptParamName::m_name offset mismatch");
static_assert(sizeof(S_ScriptParamName) == 0x08,
              "S_ScriptParamName size mismatch");

}  // namespace wh::xgenaimodule
