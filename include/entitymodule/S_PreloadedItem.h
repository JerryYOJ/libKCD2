#pragma once

#include <cstddef>
#include <cstdint>

#include "S_ExistingQuestItem.h"

namespace wh::entitymodule {

class S_PreloadedItem : public S_ExistingQuestItem {
public:
    ~S_PreloadedItem() override;                            // [0] 0x180EA1C80
    RTTR_ENABLE(S_ExistingQuestItem)                        // [1..3], vtable 0x183EC8570

    bool m_useBackupLocation;                               // +0x10
    std::uint8_t m_padding11[7];                            // +0x11
};

static_assert(offsetof(S_PreloadedItem, m_useBackupLocation) == 0x10,
              "S_PreloadedItem::m_useBackupLocation offset mismatch");
static_assert(sizeof(S_PreloadedItem) == 0x18,
              "S_PreloadedItem size mismatch");

}  // namespace wh::entitymodule
