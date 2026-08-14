#pragma once
#include <cstdint>
#include "../framework/WUID.h"

namespace wh::entitymodule {

class C_Item;
struct S_ItemClass;

// KCD2 inventory-change listener. Retail vtable 0x183A65058 has seven callbacks
// followed by the deleting destructor; original method spellings are not emitted.
class I_InventoryListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_InventoryListener;

    virtual void InventoryListenerUnk0(C_Item* item, std::uint32_t amount) {} // [0]
    virtual void InventoryListenerUnk1(C_Item* item, std::uint32_t amount) {} // [1]
    virtual void InventoryListenerUnk2(S_ItemClass* itemClass,
                                       std::uint32_t amount,
                                       framework::WUID itemWuid) {} // [2]
    virtual void InventoryListenerUnk3(C_Item* item,
                                       std::uint32_t changeMask) {} // [3], item changed
    virtual void InventoryListenerUnk4(C_Item* consumedItem,
                                       C_Item* survivingItem) {} // [4], pre-merge replacement
    virtual void InventoryListenerUnk5(C_Item* sourceItem,
                                       C_Item* splitItem) {} // [5], split item added
    virtual void InventoryListenerUnk6() {} // [6], inventory teardown
    virtual ~I_InventoryListener() = default; // [7] 0x1829A820C
};
static_assert(sizeof(I_InventoryListener) == 0x08,
              "I_InventoryListener must be vptr-only");

}  // namespace wh::entitymodule
