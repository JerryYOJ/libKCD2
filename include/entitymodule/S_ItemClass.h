#pragma once
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "E_HandContextSerializationMode.h"
#include "E_ItemType.h"
#include "rttr/rttr_enable.h"

// -----------------------------------------------
// wh::entitymodule::S_ItemClass -- the item CLASS-definition root (KCD2 WHGame.dll 1.5.6).
// sizeof 0x38.  KCD2's rename of KCD1's S_ItemData (RTTI .?AUS_ItemClass@entitymodule@wh@@).
// -----------------------------------------------
// 30-type polymorphic tree (root + optional S_TypedItemClass mixin + 28 CRTP leaves via
// S_ItemClassWrapper<Derived, Parent, TypeId>, RTTR-registered -- NO integer-switch factory).
// The mixin is NOT on every concrete leaf (Money/Die/KeyRing/Poison/Key have none).
// Tree: analysis/item_data/s_itemdata_re.md (copy-ctor IPs in that doc are often Clone/GetAs
// stores -- do not treat them as in-place copy-ctors).
//
// Instances live in the global item-class database 0x185325820 (GUID-sorted vector keyed by
// m_guid). Reached from a live item via C_Item::m_pClassData (+0x48).
// Base vtable 0x183A4EC78 (55 slots), ctor sub_180754CE4, copy sub_180D290F8, dtor sub_181AB90BC.
// GetAs [24..50]: introducing class (and descendants) override with `return this`; root returns
// a TLS-lazy static default. S_MoneyItemClass has no own GetAs (inherits Divisible).
namespace wh::entitymodule {

class C_Item;
struct S_ItemInstanceData;   // 0xF8 create/save blob (SYNTHETIC name) -- see S_ItemInstanceData.h.
                             // NOT C_ItemClassDescriptor: that is the 0x50 RTTR match-filter class.

class S_AlchemyBaseItemClass;
class S_AmmoItemClass;
class S_ArmorItemClass;
class S_ConsumableItemClass;
class S_CraftingMaterialItemClass;
class S_DiceBadgeItemClass;
class S_DieItemClass;
class S_DivisibleItemClass;
class S_DocumentItemClass;
class S_EquippableItemClass;
class S_FoodItemClass;
class S_HelmetItemClass;
class S_HerbItemClass;
class S_HoodItemClass;
class S_KeyItemClass;
class S_KeyRingItemClass;
class S_MeleeWeaponItemClass;
class S_MiscItemClass;
class S_MissileWeaponItemClass;
class S_NPCToolItemClass;
class S_OintmentItemClass;
class S_PickableItemClass;
class S_PlayerItemClass;
class S_PoisonItemClass;
class S_QuickSlotContainerItemClass;
class S_WeaponEquipItemClass;
class S_WeaponItemClass;

class S_ItemClass {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_S_ItemClass;

    virtual ~S_ItemClass();                                                                  // [0]
    virtual E_ItemType::Type GetTypeId() const;                                              // [1]  root returns Root(21)
    virtual S_ItemClass* Clone() const;                                                      // [2]  alloc(sizeof(T)) + copy -- sizeof proof
    virtual bool IsType(E_ItemType::Type type) const;                                        // [3]  IsKindOf: self + ancestors
    virtual uint32_t GetTypeDistance(E_ItemType::Type type) const;                           // [4]
    virtual bool HasQuality() const;                                                         // [5]  root false
    virtual int32_t GetMaxQuality() const;                                                   // [6]  root returns 1
    virtual bool IsDivisible() const;                                                        // [7]
    virtual bool unk8() const;                                                               // [8]  root false; Pickable reads +0x89
    virtual int32_t unk9() const;                                                            // [9]  root -1; bitset-index id (name UNVERIFIED)
    virtual int32_t unk10() const;                                                           // [10] root -1; TypedItemClass +8 candidate
    virtual int32_t unk11() const;                                                           // [11] root -1; TypedItemClass +0xC candidate
    virtual float GetPrice(uint32_t price) const;                                            // [12] root = (float)price identity
    virtual float unk13() const;                                                             // [13] root 0; combat-stat-ish float, no named consumer
    virtual std::vector<std::string>* GetProperties();                                       // [14] &m_properties
    virtual void OnItemFlagsChanged(C_Item* item, uint32_t mask, bool bitSet);               // [15]
    virtual void DiffItemInstanceData();                                                     // [16] 0x180B56DA4 emits patch tags old->new; sig (collector, old, new) UNVERIFIED
    virtual void PatchItemInstanceData();                                                    // [17] 0x180B5B134 tag-switch applicator (tags 0/1/2/3/5/6/0xA/0x12); sig UNVERIFIED
    virtual S_ItemInstanceData* FillItemInstanceData(S_ItemInstanceData* out, C_Item* item); // [18] 0x180B56CA8 snapshot C_Item -> blob
    virtual void InitItemInstance(void* notifyCtx, S_ItemInstanceData* src, C_Item* item);   // [19] 0x180468B70
    virtual void InitItemDefaults(S_ItemInstanceData* data);                                 // [20] 0x180467FFC (flags &= 0xFFE7FFFE, amount/quality defaults)
    virtual uint8_t unk21() const;                                                           // [21] 3-state 0/1/2 getter, name UNVERIFIED
    virtual E_HandContextSerializationMode::Type GetHandContextSerializationMode() const;    // [22]
    virtual bool unk23() const;                                                              // [23] Pickable +0x88 bool, name UNVERIFIED

    virtual S_PickableItemClass* GetAsPickableItemClass();                                   // [24] default 0x1855DD170
    virtual S_PlayerItemClass* GetAsPlayerItemClass();                                       // [25] default 0x1855DD210
    virtual S_EquippableItemClass* GetAsEquippableItemClass();                               // [26] default 0x1855DD2D0
    virtual S_DivisibleItemClass* GetAsDivisibleItemClass();                                 // [27] default 0x1855DD3C0
    virtual S_NPCToolItemClass* GetAsNPCToolItemClass();                                     // [28] default 0x1855DD490
    virtual S_ArmorItemClass* GetAsArmorItemClass();                                         // [29] default 0x1855DD540
    virtual S_AmmoItemClass* GetAsAmmoItemClass();                                           // [30] default 0x1855DD660
    virtual S_WeaponItemClass* GetAsWeaponItemClass();                                       // [31] default 0x1855DD7B0
    virtual S_WeaponEquipItemClass* GetAsWeaponEquipItemClass();                             // [32]
    virtual S_MissileWeaponItemClass* GetAsMissileWeaponItemClass();                         // [33]
    virtual S_MeleeWeaponItemClass* GetAsMeleeWeaponItemClass();                             // [34]
    virtual S_ConsumableItemClass* GetAsConsumableItemClass();                               // [35]
    virtual S_FoodItemClass* GetAsFoodItemClass();                                           // [36]
    virtual S_PoisonItemClass* GetAsPoisonItemClass();                                       // [37]
    virtual S_OintmentItemClass* GetAsOintmentItemClass();                                   // [38]
    virtual S_HerbItemClass* GetAsHerbItemClass();                                           // [39] default 0x1855DE0D0
    virtual S_DocumentItemClass* GetAsDocumentItemClass();                                   // [40]
    virtual S_CraftingMaterialItemClass* GetAsCraftingMaterialItemClass();                   // [41]
    virtual S_AlchemyBaseItemClass* GetAsAlchemyBaseItemClass();                             // [42]
    virtual S_DieItemClass* GetAsDieItemClass();                                             // [43]
    virtual S_DiceBadgeItemClass* GetAsDiceBadgeItemClass();                                 // [44]
    virtual S_HelmetItemClass* GetAsHelmetItemClass();                                       // [45]
    virtual S_KeyItemClass* GetAsKeyItemClass();                                             // [46] default 0x1855DE720
    virtual S_KeyRingItemClass* GetAsKeyRingItemClass();                                     // [47] default 0x1855DE7E0
    virtual S_QuickSlotContainerItemClass* GetAsQuickSlotContainerItemClass();               // [48]
    virtual S_MiscItemClass* GetAsMiscItemClass();                                           // [49]
    virtual S_HoodItemClass* GetAsHoodItemClass();                                           // [50] default 0x1855DEAD0

    virtual void OnRegister();                                                               // [51] registrar pre-insert; base nullsub
    RTTR_ENABLE()  // [52..54]: get_type 0x181A6DB4C, get_derived 0x182A23F6C

    CryGUID m_guid;                                 // +0x08  registry key
    CryStringT<char> m_name;                        // +0x18  internal class name/key
    std::vector<std::string> m_properties;          // +0x20  MSVC SSO string (0x20), NOT a custom S_Property
};
static_assert(sizeof(S_ItemClass) == 0x38, "S_ItemClass must be 0x38");
static_assert(offsetof(S_ItemClass, m_guid) == 0x08, "class guid at 0x08");
static_assert(offsetof(S_ItemClass, m_properties) == 0x20, "properties at 0x20");

}  // namespace wh::entitymodule
