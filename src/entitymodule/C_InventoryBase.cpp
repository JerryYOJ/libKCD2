#include "entitymodule/C_InventoryBase.h"
#include "Offsets/Offsets.h"

// C_InventoryBase engine-function forwarders (KCD2 WHGame.dll 1.5.6 RVAs, utem;
// ids = kcd2 address library).

namespace wh::entitymodule {

C_Item* C_InventoryBase::FindItemByClass(const CryGUID& classId)
{
    // 0x1808D315C: linear walk of m_items comparing each item's class guid
    // (*(item+0x48) = S_ItemClass, guid at +0x08).
    using Fn = C_Item* (__fastcall*)(C_InventoryBase*, const CryGUID*);
    static REL::Relocation<Fn> fn{ REL::ID(48187) };  // 0x1808D315C
    return fn(this, &classId);
}

}  // namespace wh::entitymodule
