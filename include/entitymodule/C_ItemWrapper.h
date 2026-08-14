#pragma once
#include <cstdint>
#include "C_ItemHolder.h"
#include "E_ItemHolderChangeFlags.h"
#include "E_ItemHolderType.h"

namespace wh::entitymodule {

class C_ItemWrapper : public C_ItemHolder {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ItemWrapper;

    ~C_ItemWrapper() override; // [0] 0x1808D3E30
    E_ItemHolderType GetHolderType() const override; // [1] 0x181A78ED0
    void _vf2(const ItemVisitor& visitor) override; // [2] 0x182A69548
    void _vf3(const ItemVisitor& visitor) override; // [3] 0x182A695F4
    void _vf9(C_Item* item, E_ItemHolderChangeFlags flags,
              std::uint32_t amount) override; // [9] 0x1819B7D2C
    void _vf10(C_Item* item, E_ItemHolderChangeFlags flags,
               std::uint32_t amount) override; // [10] 0x1819A9F68
    bool _vf13(E_ItemHolderChangeFlags flags, S_ItemClass* itemClass,
               std::uint32_t amount) const override; // [13] 0x1819CBAD4
    bool _vf15() const override; // [15] 0x18041A6A0

    C_Item* m_pItem;                  // +0x08
    bool m_primaryRelationActive;     // +0x10, reconstructed name
    std::uint8_t _pad11[7];           // +0x11
};
static_assert(sizeof(C_ItemWrapper) == 0x18,
              "C_ItemWrapper must be 0x18");

}  // namespace wh::entitymodule
