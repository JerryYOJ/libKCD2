#pragma once
#include <cstdint>
#include "../crysystem/CScriptableBase.h"

// -----------------------------------------------
// wh::shopmodule::C_ScriptBindShop -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x78 (CONFIRMED: alloc 120).
// -----------------------------------------------
// RTTI .?AVC_ScriptBindShop@shopmodule@wh@@ (TD 0x184E1D3A8, COL 0x184117AE0; CHD = [self,
// CScriptableBase])  vftable 0x183B629A0  ctor sub_1813368D0  factory sub_1813366D4
// (= C_ShopModule ctor).
//
// GLOBAL Lua table "Shops" (SetGlobalName sub_180B85140; m_bInstanceMethods=0). Handlers are
// DIRECT function pointers (no vtable thunks -- Shop keeps only the base vtable slots).
//
// Lua fn table `Shops` (12 fns; registrar sub_180B639C8):
//   OpenInventory              0x182EFE8FC  (entityId)
//   OpenInventoryForItem       0x180C820A0  (itemId)
//   AcceptTransaction          0x18152EA94  (shopkeeperId, finalPrice, playGoodbyeBark)
//   DoMoneyTransaction         0x182EFE260  (shopkeeperId, amount, playGoodbyeBark)   CHEAT-adjacent
//   CancelTransaction          0x182EFE1D4  (entityId)
//   GetShopMoney               0x18152EBFC  (entityId)
//   IsLinkedWithShop           0x182EFE664  (entityId)
//   FindItemInShop             0x182EFE344  (entityId)
//   FindShopInventoryForItem   0x182EFE3D0  (entityId)
//   IsShopOpened               0x182EFE6B0  (linkedEntityId)
//   GetShopDBIdByLinkedEntityId 0x182EFE608 (entityId)
//   GetShopDBIdByKeeper        0x18152EC44  (entityId)

namespace wh::shopmodule {

class C_ScriptBindShop : public ::CScriptableBase   // +0x00  (0x60)
{
public:
    Offsets::IScriptSystem* m_pSS2;          // +0x60  raw ctor pScriptSystem
    void*                   m_pSubsystem;    // +0x68  = pScriptSys->vf79() result (pointee unresolved)
    void*                   m_pShopManager;  // +0x70  0 at ctor; populated during module wiring --
                                             //        OpenInventory reads it as the shop-manager ptr (sub_18152EDA4)
};
static_assert(sizeof(C_ScriptBindShop) == 0x78, "C_ScriptBindShop must be 0x78");

}  // namespace wh::shopmodule
