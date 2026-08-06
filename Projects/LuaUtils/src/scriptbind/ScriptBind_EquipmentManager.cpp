#include "scriptbind/ScriptBind_EquipmentManager.h"

#include <cstdint>

#include "LuaHelpers.h"
#include "REL.h"
#include "ResolveHelpers.h"
#include "rttr/RttrRuntime.h"
#include "rttr/variant.h"

#include "Offsets/vtables/IFunctionHandler.h"
#include "Offsets/vtables/IScriptSystem.h"
#include "Offsets/vtables/IScriptTable.h"
#include "entitymodule/C_Actor.h"
#include "entitymodule/C_EquipmentManager.h"
#include "entitymodule/C_Inventory.h"
#include "entitymodule/C_Item.h"
#include "playermodule/C_OutfitManager.h"
#include "playermodule/C_QAMManager.h"
#include "playermodule/E_OutfitId.h"
#include "playermodule/E_QAM_FoodSlot.h"
#include "playermodule/E_QAM_WeaponSlot.h"
#include "rpgmodule/C_InventorySoul.h"

using namespace wh::entitymodule;
using namespace wh::playermodule;

namespace luautils {

void CScriptBind_EquipmentManager::Init(Offsets::IScriptSystem* pSS)
{
    m_pSS = pSS;
    m_pMethodsTable = pSS->CreateTable(0, 0);
    if (!m_pMethodsTable)
        return;
    m_pMethodsTable->AddRef();   // CreateTable returns refcount 0; pinned for the session

    RegisterFunction("GetEquippedItems", "entityId", functor(*this, &CScriptBind_EquipmentManager::GetEquippedItems));
    RegisterFunction("GetEquippedClothing", "entityId", functor(*this, &CScriptBind_EquipmentManager::GetEquippedClothing));
    RegisterFunction("GetHandSlots", "entityId", functor(*this, &CScriptBind_EquipmentManager::GetHandSlots));
    RegisterFunction("GetItemInSlot", "entityId, slotId", functor(*this, &CScriptBind_EquipmentManager::GetItemInSlot));
    RegisterFunction("GetEquipWeights", "entityId", functor(*this, &CScriptBind_EquipmentManager::GetEquipWeights));
    RegisterFunction("GetInventoryEx", "entityId", functor(*this, &CScriptBind_EquipmentManager::GetInventoryEx));
    RegisterFunction("GetInventoryId", "entityId", functor(*this, &CScriptBind_EquipmentManager::GetInventoryId));
    RegisterFunction("GetInventoryHandle", "entityId", functor(*this, &CScriptBind_EquipmentManager::GetInventoryHandle));
    RegisterFunction("SetItemEquipped", "entityId, itemId, equip", functor(*this, &CScriptBind_EquipmentManager::SetItemEquipped));
    RegisterFunction("GetWeaponQuickSlots", "entityId, [outfitId]", functor(*this, &CScriptBind_EquipmentManager::GetWeaponQuickSlots));
    RegisterFunction("SetWeaponQuickSlot", "entityId, quickSlot, itemId, [outfitId]", functor(*this, &CScriptBind_EquipmentManager::SetWeaponQuickSlot));
    RegisterFunction("ClearWeaponQuickSlot", "entityId, quickSlot, offHand, [outfitId]", functor(*this, &CScriptBind_EquipmentManager::ClearWeaponQuickSlot));
    RegisterFunction("GetConsumableQuickSlots", "entityId, [outfitId]", functor(*this, &CScriptBind_EquipmentManager::GetConsumableQuickSlots));
    RegisterFunction("SetConsumableQuickSlot", "entityId, slotId, itemId, [outfitId]", functor(*this, &CScriptBind_EquipmentManager::SetConsumableQuickSlot));
    RegisterFunction("ClearConsumableQuickSlot", "entityId, slotId, [outfitId]", functor(*this, &CScriptBind_EquipmentManager::ClearConsumableQuickSlot));

    m_pSS->SetGlobalAny("EquipmentManager", ScriptAnyValue(m_pMethodsTable));
}

void CScriptBind_EquipmentManager::RegisterFunction(const char* sName, const char* sParams, const FunctionFunctor& f)
{
    SUserFunctionDesc fd;
    fd.sGlobalName     = "EquipmentManager";
    fd.sFunctionName   = sName;
    fd.sFunctionParams = sParams;
    fd.pFunctor        = f;
    m_pMethodsTable->AddFunction(fd);
}

// ---- shared param helpers -------------------------------------------------

static C_Actor* GetActorParam(Offsets::IFunctionHandler* pH)
{
    uint64_t id = 0;
    if (!GetHandleParam(pH, 1, id))
        return nullptr;
    return ResolveActor(id);
}

struct QAMTarget {
    C_QAMManager* manager;
    E_OutfitId::Type outfit;
};

static bool ResolveQAMTarget(Offsets::IFunctionHandler* pH, C_Actor* actor,
                             int outfitParam, bool weapon, QAMTarget& target)
{
    auto* invSoul = ResolveInventorySoul(actor);
    auto* outfitManager = invSoul ? invSoul->GetOutfitManager() : nullptr;
    if (!outfitManager)
        return false;

    int outfitId = static_cast<int>(outfitManager->GetCurrentOutfit());
    if (pH->GetParamCount() >= outfitParam && !pH->GetParam(outfitParam, outfitId))
        return false;
    if (outfitId < E_OutfitId::A || outfitId > E_OutfitId::C)
        return false;

    target.outfit = static_cast<E_OutfitId::Type>(outfitId);
    target.manager = weapon
        ? outfitManager->GetWeaponQAMManager(target.outfit)
        : outfitManager->GetConsumableQAMManager(target.outfit);
    return target.manager != nullptr;
}

static bool ItemBelongsToActor(C_Actor* actor, C_Item* item)
{
    C_Inventory* inventory = ResolveInventory(actor);
    return inventory && item && item->m_pInventory == inventory;
}

// ---- queries --------------------------------------------------------------

int CScriptBind_EquipmentManager::GetEquippedItems(Offsets::IFunctionHandler* pH)
{
    C_Actor* actor = GetActorParam(pH);
    C_EquipmentManager* em = ResolveEquipment(actor);
    if (!em)
        return pH->EndFunction();
    Offsets::IScriptTable* t = m_pSS->CreateTable(0, 0);
    if (!t)
        return pH->EndFunction();
    int idx = 1;
    for (C_Item* item : em->m_equippedItems) {
        if (item)
            t->SetAtAny(idx++, HandleValue(item->m_wuid.m_value));
    }
    int n = pH->EndFunctionAny(ScriptAnyValue(t));
    t->Release();
    return n;
}

int CScriptBind_EquipmentManager::GetEquippedClothing(Offsets::IFunctionHandler* pH)
{
    C_Actor* actor = GetActorParam(pH);
    C_EquipmentManager* em = ResolveEquipment(actor);
    if (!em)
        return pH->EndFunction();
    Offsets::IScriptTable* t = m_pSS->CreateTable(0, 0);
    if (!t)
        return pH->EndFunction();
    for (const auto& [slotId, itemWuid] : em->m_clothing)
        t->SetAtAny(static_cast<int>(slotId), HandleValue(itemWuid.m_value));
    int n = pH->EndFunctionAny(ScriptAnyValue(t));
    t->Release();
    return n;
}

int CScriptBind_EquipmentManager::GetHandSlots(Offsets::IFunctionHandler* pH)
{
    C_Actor* actor = GetActorParam(pH);
    C_EquipmentManager* em = ResolveEquipment(actor);
    if (!em)
        return pH->EndFunction();
    Offsets::IScriptTable* t = m_pSS->CreateTable(0, 0);
    if (!t)
        return pH->EndFunction();
    for (int i = 0; i < 8; ++i) {
        if (em->m_weaponEquipSlots[i])
            t->SetAtAny(i + 1, HandleValue(em->m_weaponEquipSlots[i]->m_wuid.m_value));
    }
    int n = pH->EndFunctionAny(ScriptAnyValue(t));
    t->Release();
    return n;
}

int CScriptBind_EquipmentManager::GetItemInSlot(Offsets::IFunctionHandler* pH)
{
    C_Actor* actor = GetActorParam(pH);
    C_EquipmentManager* em = ResolveEquipment(actor);
    int slotId = 0;
    if (!em || !pH->GetParam(2, slotId))
        return pH->EndFunction();
    auto it = em->m_clothing.find(static_cast<uint32_t>(slotId));
    if (it == em->m_clothing.end())
        return pH->EndFunction();
    return pH->EndFunctionAny(HandleValue(it->second.m_value));
}

int CScriptBind_EquipmentManager::GetEquipWeights(Offsets::IFunctionHandler* pH)
{
    C_Actor* actor = GetActorParam(pH);
    C_EquipmentManager* em = ResolveEquipment(actor);
    if (!em)
        return pH->EndFunction();
    Offsets::IScriptTable* t = m_pSS->CreateTable(0, 0);
    if (!t)
        return pH->EndFunction();
    t->SetValueAny("total", ScriptAnyValue(em->m_totalWeight));
    t->SetValueAny("worn", ScriptAnyValue(em->m_wornWeight));
    int n = pH->EndFunctionAny(ScriptAnyValue(t));
    t->Release();
    return n;
}

int CScriptBind_EquipmentManager::GetInventoryEx(Offsets::IFunctionHandler* pH)
{
    C_Actor* actor = GetActorParam(pH);
    C_Inventory* inv = ResolveInventory(actor);
    if (!inv)
        return pH->EndFunction();
    Offsets::IScriptTable* t = m_pSS->CreateTable(0, 0);
    if (!t)
        return pH->EndFunction();
    int idx = 1;
    for (C_Item* item : inv->m_items) {
        if (!item)
            continue;
        if (Offsets::IScriptTable* it = BuildItemTable(m_pSS, item)) {
            t->SetAtAny(idx++, ScriptAnyValue(it));
            it->Release();   // parent table's Lua ref keeps it alive
        }
    }
    int n = pH->EndFunctionAny(ScriptAnyValue(t));
    t->Release();
    return n;
}

int CScriptBind_EquipmentManager::GetInventoryId(Offsets::IFunctionHandler* pH)
{
    C_Actor* actor = GetActorParam(pH);
    C_Inventory* inv = ResolveInventory(actor);
    if (!inv)
        return pH->EndFunction();
    return pH->EndFunctionAny(HandleValue(inv->m_wuid.m_value));
}

int CScriptBind_EquipmentManager::GetInventoryHandle(Offsets::IFunctionHandler* pH)
{
    C_Actor* actor = GetActorParam(pH);
    C_Inventory* inv = ResolveInventory(actor);
    if (!inv)
        return pH->EndFunction();

    // Mint the registry variant with the game's own C_Inventory* pointer
    // policy (the one its property getters stamp, e.g. I_Soul::Inventory at
    // 0x18082554D): m_data[0] holds the pointer value, clone is a shallow
    // copy and destroy is a no-op, so registry ownership is safe.
    static REL::Relocation<rttr::variant::policy_func> policy{ REL::ID(44780) };  // 0x18082569C
    rttr::detail::variant_data data{};
    data.m_storage[0] = inv;
    rttr::variant value = rttr::variant::from_policy(data, policy.get());
    try {
        const RttrHandleRegistry::Handle handle =
            g_rttrRuntime.Registry().Store(std::move(value));
        return pH->EndFunctionAny(HandleValue(handle));
    } catch (...) {
        return pH->EndFunction();
    }
}

int CScriptBind_EquipmentManager::GetWeaponQuickSlots(Offsets::IFunctionHandler* pH)
{
    C_Actor* actor = GetActorParam(pH);
    QAMTarget target{};
    if (!actor || !ResolveQAMTarget(pH, actor, 2, true, target))
        return pH->EndFunction();

    Offsets::IScriptTable* result = m_pSS->CreateTable(0, 0);
    if (!result)
        return pH->EndFunction();
    result->SetValueAny("outfitId", ScriptAnyValue(static_cast<int>(target.outfit)));

    for (std::uint32_t pair = 0; pair < 4; ++pair) {
        auto mainSlot = static_cast<E_QAM_WeaponSlot::Type>(pair * 2);
        auto offSlot = static_cast<E_QAM_WeaponSlot::Type>(pair * 2 + 1);
        Offsets::IScriptTable* entry = m_pSS->CreateTable(0, 0);
        if (!entry)
            continue;
        entry->SetValueAny("usable", ScriptAnyValue(target.manager->IsWeaponSlotUsable(mainSlot)));
        if (C_Item* item = target.manager->GetWeaponItem(mainSlot))
            entry->SetValueAny("main", HandleValue(item->m_wuid.m_value));
        if (C_Item* item = target.manager->GetWeaponItem(offSlot))
            entry->SetValueAny("off", HandleValue(item->m_wuid.m_value));
        result->SetAtAny(static_cast<int>(pair + 1), ScriptAnyValue(entry));
        entry->Release();
    }

    int n = pH->EndFunctionAny(ScriptAnyValue(result));
    result->Release();
    return n;
}

int CScriptBind_EquipmentManager::GetConsumableQuickSlots(Offsets::IFunctionHandler* pH)
{
    C_Actor* actor = GetActorParam(pH);
    QAMTarget target{};
    if (!actor || !ResolveQAMTarget(pH, actor, 2, false, target))
        return pH->EndFunction();

    Offsets::IScriptTable* result = m_pSS->CreateTable(0, 0);
    if (!result)
        return pH->EndFunction();
    result->SetValueAny("outfitId", ScriptAnyValue(static_cast<int>(target.outfit)));

    for (std::uint32_t slotIndex = 0; slotIndex < 4; ++slotIndex) {
        auto slot = static_cast<E_QAM_FoodSlot::Type>(slotIndex);
        Offsets::IScriptTable* entry = m_pSS->CreateTable(0, 0);
        if (!entry)
            continue;
        entry->SetValueAny("usable", ScriptAnyValue(target.manager->IsConsumableSlotUsable(slot)));
        if (C_Item* item = target.manager->GetConsumableItem(slot))
            entry->SetValueAny("item", HandleValue(item->m_wuid.m_value));
        result->SetAtAny(static_cast<int>(slotIndex + 1), ScriptAnyValue(entry));
        entry->Release();
    }

    int n = pH->EndFunctionAny(ScriptAnyValue(result));
    result->Release();
    return n;
}

// ---- mutators -------------------------------------------------------------

int CScriptBind_EquipmentManager::SetItemEquipped(Offsets::IFunctionHandler* pH)
{
    C_Actor* actor = GetActorParam(pH);
    auto* invSoul = ResolveInventorySoul(actor);
    uint64_t itemId = 0;
    bool equip = true;
    if (!invSoul || !GetHandleParam(pH, 2, itemId) || !pH->GetParam(3, equip))
        return pH->EndFunction();
    C_Item* item = ResolveItem(itemId);
    if (!item)
        return pH->EndFunction();
    if (equip)
        invSoul->EquipItem(item, true);
    else
        invSoul->UnequipItem(item, true);
    return pH->EndFunctionAny(ScriptAnyValue(true));
}

int CScriptBind_EquipmentManager::SetWeaponQuickSlot(Offsets::IFunctionHandler* pH)
{
    C_Actor* actor = GetActorParam(pH);
    int quickSlot = 0;
    uint64_t itemId = 0;
    QAMTarget target{};
    if (!actor || !pH->GetParam(2, quickSlot) || quickSlot < 1 || quickSlot > 4 ||
        !GetHandleParam(pH, 3, itemId) || !ResolveQAMTarget(pH, actor, 4, true, target))
        return pH->EndFunction();

    C_Item* item = ResolveItem(itemId);
    if (!ItemBelongsToActor(actor, item))
        return pH->EndFunction();

    std::uint32_t pair = static_cast<std::uint32_t>(quickSlot - 1);
    auto mainSlot = static_cast<E_QAM_WeaponSlot::Type>(pair * 2);
    auto offSlot = static_cast<E_QAM_WeaponSlot::Type>(pair * 2 + 1);
    if (!target.manager->IsWeaponSlotUsable(mainSlot))
        return pH->EndFunction();

    target.manager->SetItem(item, pair);
    if (target.manager->GetWeaponItem(mainSlot) == item)
        return pH->EndFunctionAny(ScriptAnyValue(static_cast<int>(pair * 2 + 1)));
    if (target.manager->GetWeaponItem(offSlot) == item)
        return pH->EndFunctionAny(ScriptAnyValue(static_cast<int>(pair * 2 + 2)));
    return pH->EndFunction();
}

int CScriptBind_EquipmentManager::ClearWeaponQuickSlot(Offsets::IFunctionHandler* pH)
{
    C_Actor* actor = GetActorParam(pH);
    int quickSlot = 0;
    bool offHand = false;
    QAMTarget target{};
    if (!actor || !pH->GetParam(2, quickSlot) || quickSlot < 1 || quickSlot > 4 ||
        !pH->GetParam(3, offHand) || !ResolveQAMTarget(pH, actor, 4, true, target))
        return pH->EndFunction();

    std::uint32_t slotIndex = static_cast<std::uint32_t>((quickSlot - 1) * 2 + (offHand ? 1 : 0));
    auto slot = static_cast<E_QAM_WeaponSlot::Type>(slotIndex);
    C_Item* item = target.manager->GetWeaponItem(slot);
    if (!item)
        return pH->EndFunctionAny(ScriptAnyValue(true));
    if (!target.manager->ClearWeaponItem(item, slot))
        return pH->EndFunction();
    return target.manager->GetWeaponItem(slot)
        ? pH->EndFunction()
        : pH->EndFunctionAny(ScriptAnyValue(true));
}

int CScriptBind_EquipmentManager::SetConsumableQuickSlot(Offsets::IFunctionHandler* pH)
{
    C_Actor* actor = GetActorParam(pH);
    int slotId = 0;
    uint64_t itemId = 0;
    QAMTarget target{};
    if (!actor || !pH->GetParam(2, slotId) || slotId < 1 || slotId > 4 ||
        !GetHandleParam(pH, 3, itemId) || !ResolveQAMTarget(pH, actor, 4, false, target))
        return pH->EndFunction();

    C_Item* item = ResolveItem(itemId);
    if (!ItemBelongsToActor(actor, item))
        return pH->EndFunction();

    std::uint32_t slotIndex = static_cast<std::uint32_t>(slotId - 1);
    auto slot = static_cast<E_QAM_FoodSlot::Type>(slotIndex);
    if (!target.manager->IsConsumableSlotUsable(slot))
        return pH->EndFunction();

    target.manager->SetItem(item, slotIndex);
    return target.manager->GetConsumableItem(slot) == item
        ? pH->EndFunctionAny(ScriptAnyValue(true))
        : pH->EndFunction();
}

int CScriptBind_EquipmentManager::ClearConsumableQuickSlot(Offsets::IFunctionHandler* pH)
{
    C_Actor* actor = GetActorParam(pH);
    int slotId = 0;
    QAMTarget target{};
    if (!actor || !pH->GetParam(2, slotId) || slotId < 1 || slotId > 4 ||
        !ResolveQAMTarget(pH, actor, 3, false, target))
        return pH->EndFunction();

    std::uint32_t slotIndex = static_cast<std::uint32_t>(slotId - 1);
    auto slot = static_cast<E_QAM_FoodSlot::Type>(slotIndex);
    C_Item* item = target.manager->GetConsumableItem(slot);
    if (!item)
        return pH->EndFunctionAny(ScriptAnyValue(true));
    if (!target.manager->ClearItem(item, slotIndex))
        return pH->EndFunction();
    return target.manager->GetConsumableItem(slot)
        ? pH->EndFunction()
        : pH->EndFunctionAny(ScriptAnyValue(true));
}

}  // namespace luautils
