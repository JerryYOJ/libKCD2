#pragma once

#include <cstddef>
#include <cstdint>

#include "C_Node.h"

namespace wh::xgenaimodule::BehaviorTree {

template <int N>
class C_FixedComposite : public C_Node {
public:
    ~C_FixedComposite() override;
    RTTR_ENABLE(C_Node)

    std::uint8_t m_unknown30[0x38];                                          // +0x30, N=2 size 0x68
};

static_assert(sizeof(C_FixedComposite<2>) == 0x68,
              "BehaviorTree::C_FixedComposite<2> size mismatch");

} // namespace wh::xgenaimodule::BehaviorTree
