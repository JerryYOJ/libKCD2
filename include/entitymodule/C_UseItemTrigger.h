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
using C_UseItemTriggerBase =
    wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>;

class C_UseItemTrigger : public C_UseItemTriggerBase {
public:
    C_UseItemTrigger();                                                // 0x1812188EC
    ~C_UseItemTrigger() override;                                      // [0] 0x181693224
    RTTR_ENABLE(C_UseItemTriggerBase)                                  // [5..7], vtable 0x183B37958
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                   // [27] 0x1829A97FC
    void OnEffectActivate() override;                                 // [43] 0x180AAF594
    void OnEffectDeactivate() override;                               // [44] 0x1829A9D88

    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::I_Soul*> m_soul;                               // +0xB0 RTTR "Soul"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onUsed;                        // +0xF0 RTTR "OnUsed"
    wh::conceptmodule::C_TypedPortRef<C_Item*> m_item;                // +0x130 RTTR "Item"
    bool m_isConnected;                                                // +0x170
    std::uint8_t m_padding171[7];                                     // +0x171
    wh::rpgmodule::I_Soul* m_activeSoul;                              // +0x178 borrowed callback source
};

static_assert(offsetof(C_UseItemTrigger, m_soul) == 0xB0,
              "C_UseItemTrigger::m_soul offset mismatch");
static_assert(offsetof(C_UseItemTrigger, m_onUsed) == 0xF0,
              "C_UseItemTrigger::m_onUsed offset mismatch");
static_assert(offsetof(C_UseItemTrigger, m_item) == 0x130,
              "C_UseItemTrigger::m_item offset mismatch");
static_assert(offsetof(C_UseItemTrigger, m_isConnected) == 0x170,
              "C_UseItemTrigger::m_isConnected offset mismatch");
static_assert(offsetof(C_UseItemTrigger, m_activeSoul) == 0x178,
              "C_UseItemTrigger::m_activeSoul offset mismatch");
static_assert(sizeof(C_UseItemTrigger) == 0x180,
              "C_UseItemTrigger size mismatch");

} // namespace wh::entitymodule
