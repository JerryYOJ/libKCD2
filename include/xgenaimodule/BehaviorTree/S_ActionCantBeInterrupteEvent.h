#pragma once
#include <cstddef>
#include "S_Event.h"

namespace wh::xgenaimodule::BehaviorTree {

struct S_ActionCantBeInterrupteEvent : S_Event {
    ~S_ActionCantBeInterrupteEvent() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    void unk_04() override;
    RTTR_ENABLE(S_Event)
};

static_assert(sizeof(S_ActionCantBeInterrupteEvent) == 0x10,
              "S_ActionCantBeInterrupteEvent size mismatch");

}  // namespace wh::xgenaimodule::BehaviorTree
