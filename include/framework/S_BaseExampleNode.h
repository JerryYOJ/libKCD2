#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"

namespace wh::framework {

struct S_BaseExampleNode {
    virtual ~S_BaseExampleNode();                           // [0]
    virtual S_BaseExampleNode* Clone();                     // [1]
    RTTR_ENABLE()                                           // [2..4]

    CryStringT<char> m_baseContent;                         // +0x08 RTTR "BaseContent"
};

static_assert(offsetof(S_BaseExampleNode, m_baseContent) == 0x08,
              "S_BaseExampleNode::m_baseContent offset mismatch");
static_assert(sizeof(S_BaseExampleNode) == 0x10,
              "S_BaseExampleNode size mismatch");

}  // namespace wh::framework
