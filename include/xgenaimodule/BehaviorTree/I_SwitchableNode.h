#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"

namespace wh::xgenaimodule::BehaviorTree {

class I_SwitchableNode {
public:
    RTTR_ENABLE()                                           // [0..2]
    virtual ~I_SwitchableNode();                            // [3]
    virtual void unk_04() = 0;                              // [4]
    virtual bool unk_05() const;                            // [5] reads +0x08
    virtual void unk_06();                                  // [6] writes true to +0x08

    bool m_unknown08;                                       // +0x08
    std::uint8_t _pad09[7];                                 // +0x09
};

static_assert(offsetof(I_SwitchableNode, m_unknown08) == 0x08,
              "I_SwitchableNode::m_unknown08 offset mismatch");
static_assert(sizeof(I_SwitchableNode) == 0x10,
              "I_SwitchableNode size mismatch");

}  // namespace wh::xgenaimodule::BehaviorTree
