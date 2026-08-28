#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../rpgmodule/S_BuffDefinitionId.h"
#include "S_ItemClassGUID.h"

namespace wh::entitymodule {

class C_ItemHolder;

class C_AddQuestItem : public wh::conceptmodule::C_Effect {
public:
    C_AddQuestItem();                                                  // 0x180AD0B40
    ~C_AddQuestItem() override;                                       // [0] 0x180968C98
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                           // [5..7], vtable 0x183E90BA8
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                   // [27] 0x18295EA4C
    void OnLifecycleEvent(std::int32_t event) override;                // [34] 0x1814B7160
    std::int32_t MapEventToPhase(std::int32_t event) override;         // [35] 0x1814FE670
    void OnEffectActivate() override;                                 // [43] 0x180518B98
    void OnEffectDeactivate() override;                               // [44] 0x180515D10

    wh::conceptmodule::C_TypedPortRef<S_ItemClassGUID> m_itemClassGuid; // +0x88 RTTR "ItemClassGUID"
    wh::conceptmodule::C_TypedPortRef<C_ItemHolder*> m_backupLocation; // +0xC8 RTTR "BackupLocation"
    wh::conceptmodule::C_TypedPortRef<C_ItemHolder*> m_startingLocation; // +0x108 RTTR "StartingLocation"
    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::S_BuffDefinitionId> m_onEquipBuff;               // +0x148 RTTR "OnEquipBuff"
    wh::conceptmodule::C_TypedPortRef<std::uint32_t> m_quality;        // +0x188 RTTR "Quality"
    wh::conceptmodule::C_TypedPortRef<float> m_health;                 // +0x1C8 RTTR "Health"
    wh::conceptmodule::C_TypedPortRef<float> m_condition;              // +0x208 RTTR "Condition"
    wh::conceptmodule::C_TypedPortRef<float> m_blood;                  // +0x248 RTTR "Blood"
    wh::conceptmodule::C_TypedPortRef<bool> m_doEquip;                 // +0x288 RTTR "DoEquip"
    wh::conceptmodule::C_TypedPortRef<bool>
        m_suppressUINotificationOnAcquire;                             // +0x2C8
    wh::conceptmodule::C_TypedPortRef<bool>
        m_suppressUINotificationOnLost;                               // +0x308
    CryGUID m_createdItemGuid;                                        // +0x348 item instance removed on deactivation
};

static_assert(offsetof(C_AddQuestItem, m_itemClassGuid) == 0x88,
              "C_AddQuestItem::m_itemClassGuid offset mismatch");
static_assert(offsetof(C_AddQuestItem, m_backupLocation) == 0xC8,
              "C_AddQuestItem::m_backupLocation offset mismatch");
static_assert(offsetof(C_AddQuestItem, m_startingLocation) == 0x108,
              "C_AddQuestItem::m_startingLocation offset mismatch");
static_assert(offsetof(C_AddQuestItem, m_onEquipBuff) == 0x148,
              "C_AddQuestItem::m_onEquipBuff offset mismatch");
static_assert(offsetof(C_AddQuestItem, m_quality) == 0x188,
              "C_AddQuestItem::m_quality offset mismatch");
static_assert(offsetof(C_AddQuestItem, m_health) == 0x1C8,
              "C_AddQuestItem::m_health offset mismatch");
static_assert(offsetof(C_AddQuestItem, m_condition) == 0x208,
              "C_AddQuestItem::m_condition offset mismatch");
static_assert(offsetof(C_AddQuestItem, m_blood) == 0x248,
              "C_AddQuestItem::m_blood offset mismatch");
static_assert(offsetof(C_AddQuestItem, m_doEquip) == 0x288,
              "C_AddQuestItem::m_doEquip offset mismatch");
static_assert(offsetof(C_AddQuestItem, m_suppressUINotificationOnAcquire) == 0x2C8,
              "C_AddQuestItem acquire-notification offset mismatch");
static_assert(offsetof(C_AddQuestItem, m_suppressUINotificationOnLost) == 0x308,
              "C_AddQuestItem lost-notification offset mismatch");
static_assert(offsetof(C_AddQuestItem, m_createdItemGuid) == 0x348,
              "C_AddQuestItem::m_createdItemGuid offset mismatch");
static_assert(sizeof(C_AddQuestItem) == 0x358,
              "C_AddQuestItem size mismatch");

} // namespace wh::entitymodule
