#pragma once

#include <cstddef>

#include "S_ItemInstanceData.h"
#include "S_QuestItemInfo.h"

namespace wh::entitymodule {

class S_DeactivatedItem : public S_QuestItemInfo {
public:
    ~S_DeactivatedItem() override;                          // [0] 0x180515664
    RTTR_ENABLE(S_QuestItemInfo)                            // [1..3], vtable 0x183C1E168

    S_ItemInstanceData m_itemData;                          // +0x08
};

static_assert(offsetof(S_DeactivatedItem, m_itemData) == 0x08,
              "S_DeactivatedItem::m_itemData offset mismatch");
static_assert(sizeof(S_DeactivatedItem) == 0x100,
              "S_DeactivatedItem size mismatch");

}  // namespace wh::entitymodule
