#pragma once
#include <cstddef>
#include <cstdint>
#include <map>
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"

namespace wh::musicmodule {

class C_Address {
public:
    RTTR_ENABLE()                                           // [0..2]

    std::map<std::uint32_t, CryStringT<char>> m_parts;     // +0x08 ctor/render traversal
};

static_assert(offsetof(C_Address, m_parts) == 0x08,
              "C_Address::m_parts offset mismatch");
static_assert(sizeof(C_Address) == 0x18, "C_Address size mismatch");

}  // namespace wh::musicmodule
