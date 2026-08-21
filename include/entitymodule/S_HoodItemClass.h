#pragma once
#include <cstddef>
#include <memory>
#include "S_ArmorItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_HoodItemClass -- KCD2 1.5.6. sizeof 0x128.
// -----------------------------------------------
// E_ItemType::Hood (29). Vtable 0x183B83420, Clone sub_182A42750 alloc 0x128 (Armor copy-ctor +
// shared_ptr copy at +0x118). Direct base is ARMOR, not Helmet -- 0x118 + 0x10 = 0x128 pins it.
// OnRegister vf[51] = 0x1811555CC (IDA mislabels it _DeleteExceptionPtr): calls Armor OnRegister
// 0x180970684, then 0x1811555F0 resolves clothing "{Name}_up" among clothing m_derivedComponents
// (exact-C_Clothing type-gate) and move-assigns it into +0x118; null when clothing absent.

namespace wh::entitymodule {

namespace clothing { class C_Clothing; }

class S_HoodItemClass : public S_ArmorItemClass {
public:
    S_HoodItemClass* GetAsHoodItemClass() override { return this; } // [50]

    // +0x118  raised-hood clothing variant ("{Name}_up" derived component). Member spelling UNVERIFIED.
    std::shared_ptr<clothing::C_Clothing> m_raisedHoodClothing;
};
static_assert(sizeof(S_HoodItemClass) == 0x128, "S_HoodItemClass must be 0x128 (Clone alloc)");
static_assert(offsetof(S_HoodItemClass, m_raisedHoodClothing) == 0x118, "raised-hood shared_ptr at 0x118");

}  // namespace wh::entitymodule
