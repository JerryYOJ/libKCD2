#pragma once
#include <cstddef>
#include "../../rttr/rttr_enable.h"

namespace wh::xgenaimodule::BehaviorTree {

struct S_BaseNodeContext {
    virtual ~S_BaseNodeContext();                           // [0]
    virtual void* unk_01();                                 // [1] returns +0x10
    virtual void unk_02(void* value);                       // [2] writes +0x10
    RTTR_ENABLE()                                           // [3..5]

    void* m_unknown08;                                      // +0x08
    void* m_unknown10;                                      // +0x10
};

static_assert(offsetof(S_BaseNodeContext, m_unknown10) == 0x10,
              "S_BaseNodeContext::m_unknown10 offset mismatch");
static_assert(sizeof(S_BaseNodeContext) == 0x18,
              "S_BaseNodeContext size mismatch");

}  // namespace wh::xgenaimodule::BehaviorTree
