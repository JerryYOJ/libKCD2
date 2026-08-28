#pragma once

#include <cstddef>

#include "S_QuestItemInfo.h"

namespace wh::entitymodule {

class C_Item;

class S_ExistingQuestItem : public S_QuestItemInfo {
public:
    ~S_ExistingQuestItem() override;                        // [0] 0x180515DE0
    RTTR_ENABLE(S_QuestItemInfo)                            // [1..3], vtable 0x183A3D668

    C_Item* m_item;                                         // +0x08, borrowed
};

static_assert(offsetof(S_ExistingQuestItem, m_item) == 0x08,
              "S_ExistingQuestItem::m_item offset mismatch");
static_assert(sizeof(S_ExistingQuestItem) == 0x10,
              "S_ExistingQuestItem size mismatch");

}  // namespace wh::entitymodule
