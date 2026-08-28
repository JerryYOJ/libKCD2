#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::conceptmodule {
class S_TypeConversion {
public:
    RTTR_ENABLE()  // [0..2]
    CryStringT<char> m_typeName;  // +0x8 RTTR "TypeName"
};

static_assert(offsetof(S_TypeConversion, m_typeName) == 0x8, "S_TypeConversion::m_typeName offset mismatch");
static_assert(sizeof(S_TypeConversion) == 0x10, "S_TypeConversion size mismatch");

}  // namespace wh::conceptmodule
