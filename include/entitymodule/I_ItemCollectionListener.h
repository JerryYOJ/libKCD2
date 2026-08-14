#pragma once
#include <cstdint>
#include "../framework/WUID.h"

// -----------------------------------------------
// wh::entitymodule::I_ItemCollectionListener -- KCD2 WHGame.dll 1.5.6 (kd7u)
// -----------------------------------------------
// Standalone item-collection listener. RTTI CHD 0x1842B1140 contains no base
// classes; vtable 0x183A65020 has five callbacks and a deleting destructor.

namespace wh::entitymodule {

class C_Item;
class C_ItemCollection;
struct S_ItemClass;

class I_ItemCollectionListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_ItemCollectionListener;

    virtual void ItemCollectionListenerUnk0(C_Item* splitItem) {} // [0], split item added
    virtual void ItemCollectionListenerUnk1(C_Item* consumedItem) {} // [1], merged item removed
    virtual void ItemCollectionListenerUnk2(S_ItemClass* itemClass,
                                            std::uint32_t amount,
                                            framework::WUID itemWuid) {} // [2], post-merge summary
    virtual void ItemCollectionListenerUnk3(C_Item* item,
                                            std::int32_t amountDelta,
                                            std::uint32_t changeMask) {} // [3], item changed
    virtual void ItemCollectionListenerUnk4(C_ItemCollection* collection) {} // [4], collection teardown
    virtual ~I_ItemCollectionListener() = default; // [5] 0x1829174F8
};
static_assert(sizeof(I_ItemCollectionListener) == 0x08,
              "I_ItemCollectionListener must be vptr-only");

}  // namespace wh::entitymodule
