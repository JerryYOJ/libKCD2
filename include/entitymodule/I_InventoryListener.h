#pragma once

// -----------------------------------------------
// wh::entitymodule::I_InventoryListener -- KCD2 WHGame.dll 1.5.6 (kd7u)
// -----------------------------------------------
// Inventory-change listener interface (vtable only). Base of I_ItemCollectionListener. KCD2 vtable
// slots not fully re-verified; slot names carried from KCD1.

namespace wh::entitymodule {

class I_InventoryListener {
public:
    virtual ~I_InventoryListener() = default;   // [0]
    virtual void OnInventoryChanged() {}        // [1]  (KCD1-derived; KCD2 slots unverified)
};

}  // namespace wh::entitymodule
