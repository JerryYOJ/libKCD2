#pragma once
#include <cstdint>
#include <vector>
#include "C_ItemHolder.h"
#include "I_InventoryListener.h"
#include "../framework/WUID.h"
#include "../framework/C_Listeners.h"
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

// -----------------------------------------------
// wh::entitymodule::C_InventoryBase : C_ItemHolder -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0xE8.
// -----------------------------------------------
// Primary base of C_Inventory (shares the vtable @+0x00 via C_ItemHolder). Holds the item lists and the
// inventory listener registry. base-ctor sub_1803A4BF0.
// m_items element type CORRECTED C_ItemHolder* -> C_Item*: the class-guid finder 0x1808D315C reads
// each element's class record via sub_1804695B4 = *(elem+0x48) -- C_Item::m_pClassData (VERIFIED
// member; C_ItemHolder is vptr-only) -- and the alchemy gather consumes elem->m_wuid (+0x30).

namespace wh::entitymodule {

class C_Item;

class C_InventoryBase : public C_ItemHolder {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_InventoryBase;

    // First item whose CLASS guid (S_ItemClass +0x08) equals classId; null if none (0x1808D315C,
    // an alchemy-TU helper walking m_items).  EXACT match only -- the autocook gather callback
    // (0x181FFE040) adds a one-hop substitute retry via the item-class registry
    // (sub_180468340(qword_185325820) -> class vf+0x138 -> +0x100 guid) that is NOT wired yet.
    C_Item* FindItemByClass(const CryGUID& classId);

    std::vector<C_Item*>       m_items;        // +0x08  held items  VERIFIED layout
    std::vector<C_ItemHolder*> m_items2;       // +0x20  secondary list (role/elem type UNVERIFIED)
    // Keyed listener registry (0xB0): delegate vector @+0x40, primary/secondary WUID guard stacks.
    wh::shared::C_DependentListeners<I_InventoryListener, wh::framework::WUID, 4> m_listeners;  // +0x38
};
static_assert(sizeof(C_InventoryBase) == 0xE8, "C_InventoryBase must be 0xE8");

}  // namespace wh::entitymodule
