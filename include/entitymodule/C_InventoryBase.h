#pragma once
#include <cstdint>
#include <vector>
#include "C_ItemHolder.h"
#include "I_InventoryListener.h"
#include "../framework/WUID.h"
#include "../framework/C_Listeners.h"

// -----------------------------------------------
// wh::entitymodule::C_InventoryBase : C_ItemHolder -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0xE8.
// -----------------------------------------------
// Primary base of C_Inventory (shares the vtable @+0x00 via C_ItemHolder). Holds the item lists and the
// inventory listener registry. base-ctor sub_1803A4BF0.

namespace wh::entitymodule {

class C_InventoryBase : public C_ItemHolder {
public:
    std::vector<C_ItemHolder*> m_items;        // +0x08  held items  VERIFIED layout
    std::vector<C_ItemHolder*> m_items2;       // +0x20  secondary list (role UNVERIFIED)
    // Keyed listener registry (0xB0): delegate vector @+0x40, primary/secondary WUID guard stacks.
    wh::shared::C_DependentListeners<I_InventoryListener, wh::framework::WUID, 4> m_listeners;  // +0x38
};
static_assert(sizeof(C_InventoryBase) == 0xE8, "C_InventoryBase must be 0xE8");

}  // namespace wh::entitymodule
