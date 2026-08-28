#pragma once

#include <cstddef>
#include <cstdint>

#include "../../rttr/rttr_enable.h"

namespace wh::xgenaimodule::BehaviorTree {

class C_Node {
public:
    virtual ~C_Node();                                                       // [0]
    RTTR_ENABLE()                                                            // [5..7], vtable 0x183A361C8, 68 slots

    std::uint8_t m_unknown08[0x10];                                          // +0x08
    CryStringT<char> m_name;                                                 // +0x18
    std::uint8_t m_unknown20[0x10];                                          // +0x20
};

static_assert(offsetof(C_Node, m_name) == 0x18,
              "BehaviorTree::C_Node::m_name offset mismatch");
static_assert(sizeof(C_Node) == 0x30,
              "BehaviorTree::C_Node size mismatch");

} // namespace wh::xgenaimodule::BehaviorTree
