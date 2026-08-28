#pragma once
#include <cstddef>
#include "S_BaseExampleNode.h"

namespace wh::framework {

struct S_DerivedExampleNode : S_BaseExampleNode {
    ~S_DerivedExampleNode() override;
    S_BaseExampleNode* Clone() override;
    RTTR_ENABLE(S_BaseExampleNode)

    CryStringT<char> m_derivedContent;                      // +0x10 RTTR "DerivedContent"
};

static_assert(offsetof(S_DerivedExampleNode, m_derivedContent) == 0x10,
              "S_DerivedExampleNode::m_derivedContent offset mismatch");
static_assert(sizeof(S_DerivedExampleNode) == 0x18,
              "S_DerivedExampleNode size mismatch");

}  // namespace wh::framework
