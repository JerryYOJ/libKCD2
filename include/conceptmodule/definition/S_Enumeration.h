#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"

namespace wh::conceptmodule::definition {
class S_Enumeration {
public:
    RTTR_ENABLE()  // [0..2]
    CryStringT<char> m_name;  // +0x8 RTTR "Name"
};

static_assert(offsetof(S_Enumeration, m_name) == 0x8, "S_Enumeration::m_name offset mismatch");
static_assert(sizeof(S_Enumeration) == 0x10, "S_Enumeration size mismatch");

}  // namespace wh::conceptmodule::definition
