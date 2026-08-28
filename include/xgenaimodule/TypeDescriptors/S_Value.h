#pragma once
#include <cstddef>
#include <cstdint>
#include "../../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::xgenaimodule::TypeDescriptors::S_Value
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x10. No vtable.
// -----------------------------------------------

namespace wh::xgenaimodule::TypeDescriptors {

struct S_Value {
    CryStringT<char> m_name;                              // +0x00 RTTR "Name"
    std::int32_t m_value;                                 // +0x08 RTTR "Value"
    std::uint8_t _pad0C[4];                               // +0x0C
};

static_assert(offsetof(S_Value, m_name) == 0x00,
              "S_Value::m_name offset mismatch");
static_assert(sizeof(S_Value) == 0x10,
              "S_Value size mismatch");

}  // namespace wh::xgenaimodule::TypeDescriptors
