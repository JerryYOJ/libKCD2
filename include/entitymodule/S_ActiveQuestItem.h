#pragma once

#include <cstddef>

#include "S_ExistingQuestItem.h"
#include "S_ItemInstanceData.h"

namespace wh::entitymodule {

class S_ActiveQuestItem : public S_ExistingQuestItem {
public:
    ~S_ActiveQuestItem() override;                          // [0] 0x182A87CA8
    RTTR_ENABLE(S_ExistingQuestItem)                        // [1..3], vtable 0x183A3D690

    S_ItemInstanceData m_itemData;                          // +0x10
};

static_assert(offsetof(S_ActiveQuestItem, m_itemData) == 0x10,
              "S_ActiveQuestItem::m_itemData offset mismatch");
static_assert(sizeof(S_ActiveQuestItem) == 0x108,
              "S_ActiveQuestItem size mismatch");

}  // namespace wh::entitymodule
