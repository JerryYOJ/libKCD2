#pragma once

// -----------------------------------------------
// wh::entitymodule::I_EquipmentManagerListener -- KCD2 WHGame.dll 1.5.6 (kd7u)
// -----------------------------------------------
// Equipment-change listener interface. Secondary base of C_Player (@+0xA60) and implemented by other
// equipment consumers. Contributes one vtable pointer. Slot names carried from KCD1; the KCD2 vtable
// slot order/signatures were not independently re-verified (only the vptr matters for the layout).

namespace wh::entitymodule {

class I_EquipmentManagerListener {
public:
    virtual ~I_EquipmentManagerListener() = default;   // [0]
    virtual void OnEquipmentChanged() {}               // [1]  (KCD1-derived name; KCD2 slots unverified)
    virtual void OnEquipmentSlotUpdated() {}           // [2]
};

}  // namespace wh::entitymodule
