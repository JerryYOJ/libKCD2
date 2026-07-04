#pragma once
#include "I_InventoryListener.h"

// -----------------------------------------------
// wh::entitymodule::I_ItemCollectionListener : I_InventoryListener -- KCD2 1.5.6 (kd7u)
// -----------------------------------------------
// Item-collection change listener (vtable only). Primary base of C_EquipmentManager (@+0x00). Derives
// I_InventoryListener. KCD2 vtable slots not fully re-verified.

namespace wh::entitymodule {

class I_ItemCollectionListener : public I_InventoryListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_ItemCollectionListener;
    virtual void OnItemCollectionChanged() {}   // (KCD1-derived; KCD2 slots unverified)
};

}  // namespace wh::entitymodule
