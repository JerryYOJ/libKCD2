#pragma once

#include <cstddef>
#include <cstdint>

#include "C_Node.h"

namespace wh::xgenaimodule::BehaviorTree {

class C_SemiFixedComposite : public C_Node {
public:
    ~C_SemiFixedComposite() override;
    RTTR_ENABLE(C_Node)

    std::uint8_t m_unknown30[0x18];                                          // +0x30
};

static_assert(sizeof(C_SemiFixedComposite) == 0x48,
              "BehaviorTree::C_SemiFixedComposite size mismatch");

} // namespace wh::xgenaimodule::BehaviorTree
