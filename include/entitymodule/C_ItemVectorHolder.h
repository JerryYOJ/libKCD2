#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../Offsets/Offsets_RTTI.h"
#include "C_ItemHolder.h"

namespace wh::entitymodule {

class C_ItemVectorHolder : public C_ItemHolder {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ItemVectorHolder;

    ~C_ItemVectorHolder() override; // [0] 0x1828C1BF4
    E_ItemHolderType GetHolderType() const override; // [1] 0x181A78EB0, returns ItemVectorHolder
    void _vf3(const ItemVisitor& visitor) override; // [3] 0x182A1F120
    void _vf9(C_Item* item, E_ItemHolderChangeFlags flags,
              std::uint32_t amount) override; // [9] 0x1804CB74C
    void _vf10(C_Item* item, E_ItemHolderChangeFlags flags,
               std::uint32_t amount) override; // [10] 0x18161E7A4

    std::vector<C_Item*> m_items; // +0x08
};
static_assert(sizeof(C_ItemVectorHolder) == 0x20,
              "C_ItemVectorHolder must be 0x20");
static_assert(offsetof(C_ItemVectorHolder, m_items) == 0x08,
              "item vector must be at 0x08");

}  // namespace wh::entitymodule
