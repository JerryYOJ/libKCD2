#pragma once
#include <cstdint>
#include <functional>
#include "I_ItemCollectionListener.h"
#include "../framework/WUID.h"
#include "../framework/C_Listeners.h"

namespace wh::entitymodule {

class C_Item;

class C_ItemCollection {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ItemCollection;
    using ItemVisitor = std::function<void(C_Item&)>;

    virtual const framework::WUID& GetCollectionWuid() const = 0; // [0]
    virtual void VisitItems(const ItemVisitor& visitor) const = 0; // [1]
    virtual bool ContainsWuid(const framework::WUID& itemWuid) const = 0; // [2]
    virtual bool ContainsItem(const C_Item* item) const = 0;       // [3]
    virtual void* CreateIterator() const = 0;                      // [4]
    virtual bool Empty() const = 0;                               // [5]
    virtual bool IsAvailable() const;                             // [6] 0x181EDEF80
    virtual void AddCollectionListener(I_ItemCollectionListener* listener); // [7] 0x180A30B80
    virtual void RemoveCollectionListener(I_ItemCollectionListener* listener); // [8] 0x1809669AC
    virtual ~C_ItemCollection();                                  // [9] 0x182A1DF20

    wh::shared::C_DependentListeners<
        I_ItemCollectionListener,
        wh::framework::WUID,
        2> m_collectionListeners;                                // +0x08
};

static_assert(offsetof(C_ItemCollection, m_collectionListeners) == 0x08,
              "C_ItemCollection::m_collectionListeners offset mismatch");
static_assert(sizeof(C_ItemCollection) == 0x70,
              "C_ItemCollection size mismatch");

}  // namespace wh::entitymodule
