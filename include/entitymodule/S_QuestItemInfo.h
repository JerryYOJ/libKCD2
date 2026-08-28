#pragma once

#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

class S_QuestItemInfo {
public:
    virtual ~S_QuestItemInfo() = default;                   // [0]
    RTTR_ENABLE()                                           // [1..3]
};

static_assert(sizeof(S_QuestItemInfo) == 0x08,
              "S_QuestItemInfo size mismatch");

}  // namespace wh::entitymodule
