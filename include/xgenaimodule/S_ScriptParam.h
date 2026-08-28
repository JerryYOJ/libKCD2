#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::xgenaimodule::S_ScriptParam
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x18. No vtable.
// -----------------------------------------------

namespace wh::xgenaimodule {

struct S_ScriptParam {
    CryStringT<char> m_name;                              // +0x00 RTTR "Name"
    float m_value;                                        // +0x08 RTTR "Value"
    std::uint8_t _pad0C[4];                               // +0x0C
    CryStringT<char> m_comment;                           // +0x10 RTTR "Comment"
};

static_assert(offsetof(S_ScriptParam, m_name) == 0x00,
              "S_ScriptParam::m_name offset mismatch");
static_assert(offsetof(S_ScriptParam, m_value) == 0x08,
              "S_ScriptParam::m_value offset mismatch");
static_assert(sizeof(S_ScriptParam) == 0x18,
              "S_ScriptParam size mismatch");

}  // namespace wh::xgenaimodule
