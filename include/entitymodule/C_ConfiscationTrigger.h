#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "S_ItemClassGUID.h"

namespace wh::entitymodule {

#pragma pack(push, 4)
class C_ConfiscationTrigger : public wh::conceptmodule::C_Effect {
public:
    C_ConfiscationTrigger();                                           // 0x18162857C
    ~C_ConfiscationTrigger() override;                                 // [0] 0x181759C3C
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                            // [5..7], vtable 0x183BD8A18
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                    // [27] 0x1829A8EF4
    void OnEffectActivate() override;                                  // [43] 0x1823DB6D8
    void OnEffectDeactivate() override;                                // [44] 0x1829A9BDC

    wh::conceptmodule::C_TypedPortRef<S_ItemClassGUID> m_itemClass;     // +0x88 RTTR "ItemClass"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onConfiscated;                  // +0xC8 RTTR "OnConfiscated"
    bool m_isListenerRegistered;                                       // +0x108
    std::uint8_t m_padding109[3];                                      // +0x109
    S_ItemClassGUID m_activeItemClass;                                 // +0x10C callback filter
    std::uint8_t m_padding11C[4];                                      // +0x11C
};
#pragma pack(pop)

static_assert(offsetof(C_ConfiscationTrigger, m_itemClass) == 0x88,
              "C_ConfiscationTrigger::m_itemClass offset mismatch");
static_assert(offsetof(C_ConfiscationTrigger, m_onConfiscated) == 0xC8,
              "C_ConfiscationTrigger::m_onConfiscated offset mismatch");
static_assert(offsetof(C_ConfiscationTrigger, m_isListenerRegistered) == 0x108,
              "C_ConfiscationTrigger::m_isListenerRegistered offset mismatch");
static_assert(offsetof(C_ConfiscationTrigger, m_activeItemClass) == 0x10C,
              "C_ConfiscationTrigger::m_activeItemClass offset mismatch");
static_assert(sizeof(C_ConfiscationTrigger) == 0x120,
              "C_ConfiscationTrigger size mismatch");

} // namespace wh::entitymodule
