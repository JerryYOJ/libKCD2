#pragma once

#include "S_ExistingQuestItem.h"

namespace wh::entitymodule {

class S_DeactivatingItem : public S_ExistingQuestItem {
public:
    ~S_DeactivatingItem() override;                         // [0], ICF 0x180515DE0
    RTTR_ENABLE(S_ExistingQuestItem)                        // [1..3], vtable 0x183A3D4C0
};

static_assert(sizeof(S_DeactivatingItem) == 0x10,
              "S_DeactivatingItem size mismatch");

}  // namespace wh::entitymodule
