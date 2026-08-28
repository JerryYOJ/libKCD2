#pragma once

#include <cstddef>
#include <cstdint>

#include "C_ItemHealthProvider.h"
#include "C_PresetItemBase.h"

namespace wh::entitymodule {

class S_ItemClass;

class C_PresetItem : public C_PresetItemBase, public C_ItemHealthProvider {
public:
    ~C_PresetItem() override;                             // [0] 0x182A1DF6C; secondary thunk 0x182139B08
    void GenerateItems(
        S_InventoryPresetGenerationContext& context,
        std::vector<S_ItemInstanceData>& items,
        std::uint32_t amount) override;                   // [1] 0x1804537C4
    bool IsValid() override;                              // [2] 0x180A2E744
    std::uint32_t GetAmount() const override;             // [3] 0x181A73A40
    RTTR_ENABLE(C_PresetItemBase, C_ItemHealthProvider)    // Primary [4..6], secondary [1..3]

    std::uint32_t m_amount;                               // +0x38 RTTR "Amount", initialized 1
    std::uint32_t m_padding3C;                            // +0x3C
    S_ItemClass* m_itemClass;                             // +0x40 borrowed lazy cache, allocation-zeroed
};

static_assert(offsetof(C_PresetItem, m_amount) == 0x38,
              "C_PresetItem::m_amount offset mismatch");
static_assert(offsetof(C_PresetItem, m_itemClass) == 0x40,
              "C_PresetItem::m_itemClass offset mismatch");
static_assert(sizeof(C_PresetItem) == 0x48,
              "C_PresetItem size mismatch");

}  // namespace wh::entitymodule
