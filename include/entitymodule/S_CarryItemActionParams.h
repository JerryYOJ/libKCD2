#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryString.h"

namespace wh::entitymodule {

struct S_CarryItemActionParams {
    std::uint64_t m_token;                                               // +0x00 ctor copies qword_1853228D8
    CryStringT<char> m_name;                                             // +0x08
    bool m_flag;                                                         // +0x10
    std::uint8_t m_padding11[7];                                         // +0x11
};

static_assert(offsetof(S_CarryItemActionParams, m_token) == 0x00,
              "S_CarryItemActionParams::m_token offset mismatch");
static_assert(offsetof(S_CarryItemActionParams, m_name) == 0x08,
              "S_CarryItemActionParams::m_name offset mismatch");
static_assert(offsetof(S_CarryItemActionParams, m_flag) == 0x10,
              "S_CarryItemActionParams::m_flag offset mismatch");
static_assert(sizeof(S_CarryItemActionParams) == 0x18,
              "S_CarryItemActionParams size mismatch");

} // namespace wh::entitymodule
