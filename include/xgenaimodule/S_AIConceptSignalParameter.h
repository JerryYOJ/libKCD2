#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::xgenaimodule::S_AIConceptSignalParameter
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x10. No vtable.
// -----------------------------------------------

namespace wh::xgenaimodule {

struct S_AIConceptSignalParameter {
    CryStringT<char> m_name;                              // +0x00 RTTR "Name"
    CryStringT<char> m_type;                              // +0x08 RTTR "Type"
};

static_assert(offsetof(S_AIConceptSignalParameter, m_name) == 0x00,
              "S_AIConceptSignalParameter::m_name offset mismatch");
static_assert(sizeof(S_AIConceptSignalParameter) == 0x10,
              "S_AIConceptSignalParameter size mismatch");

}  // namespace wh::xgenaimodule
