#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "C_ItemCollection.h"

namespace wh::entitymodule {

class C_ItemIndexer : public C_ItemCollection {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ItemIndexer;

    const framework::WUID& GetCollectionWuid() const override; // [0] 0x181A7FAF0
    void VisitItems(const ItemVisitor& visitor) const override; // [1] 0x1808F46C4
    bool ContainsWuid(const framework::WUID& itemWuid) const override; // [2] 0x182A1F7DC
    bool ContainsItem(const C_Item* item) const override;       // [3] 0x1808F3AA0
    void* CreateIterator() const override;                      // [4] 0x182A1ECB8
    bool Empty() const override;                               // [5] 0x1808C5510
    ~C_ItemIndexer() override;                                 // [9] 0x180D12298

    framework::WUID m_wuid;                                   // +0x70
    std::vector<C_Item*> m_items;                             // +0x78
};

static_assert(offsetof(C_ItemIndexer, m_wuid) == 0x70,
              "C_ItemIndexer::m_wuid offset mismatch");
static_assert(offsetof(C_ItemIndexer, m_items) == 0x78,
              "C_ItemIndexer::m_items offset mismatch");
static_assert(sizeof(C_ItemIndexer) == 0x90,
              "C_ItemIndexer size mismatch");

}  // namespace wh::entitymodule
