#pragma once
#include <cstddef>
#include "I_SwitchableNode.h"

namespace wh::xgenaimodule::BehaviorTree {

class I_ContinuousSwitchableNode : public I_SwitchableNode {
public:
    RTTR_ENABLE(I_SwitchableNode)                           // [0..2]
    ~I_ContinuousSwitchableNode() override;                 // [3]
    void unk_04() override;                                 // [4]
    virtual bool unk_07();                                  // [7]
    virtual void unk_08() = 0;                              // [8]
    virtual void unk_09();                                  // [9]
    virtual void* unk_10(void* out);                        // [10]
    virtual void* unk_11(void* out);                        // [11]
};

static_assert(sizeof(I_ContinuousSwitchableNode) == 0x10,
              "I_ContinuousSwitchableNode size mismatch");

}  // namespace wh::xgenaimodule::BehaviorTree
