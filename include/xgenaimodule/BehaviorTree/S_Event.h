#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"

namespace wh::xgenaimodule::BehaviorTree {

struct S_Event {
    virtual ~S_Event();                                     // [0]
    virtual void unk_01() = 0;                              // [1]
    virtual void unk_02() = 0;                              // [2]
    virtual void unk_03() = 0;                              // [3]
    virtual void unk_04() = 0;                              // [4]
    RTTR_ENABLE()                                           // [5..7]

    std::uint8_t m_unknown08[8];                            // +0x08
};

static_assert(sizeof(S_Event) == 0x10, "S_Event size mismatch");

}  // namespace wh::xgenaimodule::BehaviorTree
