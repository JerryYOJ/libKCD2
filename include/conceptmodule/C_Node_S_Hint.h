#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"
#include "C_Node.h"
#include "E_HintType.h"

namespace wh::conceptmodule {

struct C_Node::S_Hint {
    std::uint64_t m_unknown00;                              // +0x00 unreflected
    E_HintType m_type;                                      // +0x08 RTTR "Type"
    std::uint32_t m_unknown0C;                              // +0x0C
    std::int64_t m_timeStamp;                               // +0x10 RTTR "TimeStamp"
    CryStringT<char> m_message;                             // +0x18 RTTR "Msg"
};

static_assert(offsetof(C_Node::S_Hint, m_type) == 0x08,
              "C_Node::S_Hint::m_type offset mismatch");
static_assert(offsetof(C_Node::S_Hint, m_timeStamp) == 0x10,
              "C_Node::S_Hint::m_timeStamp offset mismatch");
static_assert(offsetof(C_Node::S_Hint, m_message) == 0x18,
              "C_Node::S_Hint::m_message offset mismatch");
static_assert(sizeof(C_Node::S_Hint) == 0x20,
              "C_Node::S_Hint size mismatch");

}  // namespace wh::conceptmodule
