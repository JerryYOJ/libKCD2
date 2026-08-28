#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"

namespace wh::rpgmodule {
class I_Soul;
}

namespace wh::entitymodule {

class C_Item;
using C_WeaponDrawTriggerBase =
    wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>;

class C_WeaponDrawTrigger : public C_WeaponDrawTriggerBase {
public:
    C_WeaponDrawTrigger();                                             // 0x181218A54
    ~C_WeaponDrawTrigger() override;                                   // [0] 0x1815296D0
    RTTR_ENABLE(C_WeaponDrawTriggerBase)                               // [5..7], vtable 0x183B377D8
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                   // [27] 0x1829A98CC
    void OnEffectActivate() override;                                 // [43] 0x180AAF5E0
    void OnEffectDeactivate() override;                               // [44] 0x1819B0DF4
    void OnEffectShutdown() override;                                 // [45] 0x181EB3570

    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::I_Soul*> m_soul;                               // +0xB0 RTTR "Soul"
    wh::conceptmodule::C_TypedPortRef<bool> m_includeNonCombatWeapons; // +0xF0
    wh::conceptmodule::C_TypedPortRef<bool> m_triggerForMainHand;     // +0x130
    wh::conceptmodule::C_TypedPortRef<bool> m_triggerForOffHand;      // +0x170
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onDraw;                        // +0x1B0 RTTR "OnDraw"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onHolster;                     // +0x1F0 RTTR "OnHolster"
    wh::conceptmodule::C_TypedPortRef<C_Item*> m_item;                // +0x230 RTTR "Item"
    bool m_isConnected;                                                // +0x270
    std::uint8_t m_padding271[7];                                     // +0x271
    wh::rpgmodule::I_Soul* m_activeSoul;                              // +0x278 borrowed callback source
};

static_assert(offsetof(C_WeaponDrawTrigger, m_soul) == 0xB0,
              "C_WeaponDrawTrigger::m_soul offset mismatch");
static_assert(offsetof(C_WeaponDrawTrigger, m_includeNonCombatWeapons) == 0xF0,
              "C_WeaponDrawTrigger include-noncombat offset mismatch");
static_assert(offsetof(C_WeaponDrawTrigger, m_triggerForMainHand) == 0x130,
              "C_WeaponDrawTrigger main-hand offset mismatch");
static_assert(offsetof(C_WeaponDrawTrigger, m_triggerForOffHand) == 0x170,
              "C_WeaponDrawTrigger off-hand offset mismatch");
static_assert(offsetof(C_WeaponDrawTrigger, m_onDraw) == 0x1B0,
              "C_WeaponDrawTrigger::m_onDraw offset mismatch");
static_assert(offsetof(C_WeaponDrawTrigger, m_onHolster) == 0x1F0,
              "C_WeaponDrawTrigger::m_onHolster offset mismatch");
static_assert(offsetof(C_WeaponDrawTrigger, m_item) == 0x230,
              "C_WeaponDrawTrigger::m_item offset mismatch");
static_assert(offsetof(C_WeaponDrawTrigger, m_isConnected) == 0x270,
              "C_WeaponDrawTrigger::m_isConnected offset mismatch");
static_assert(offsetof(C_WeaponDrawTrigger, m_activeSoul) == 0x278,
              "C_WeaponDrawTrigger::m_activeSoul offset mismatch");
static_assert(sizeof(C_WeaponDrawTrigger) == 0x280,
              "C_WeaponDrawTrigger size mismatch");

} // namespace wh::entitymodule
