#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "../entitymodule/E_StanceCategory.h"
#include "C_SmartObject.h"

namespace wh::rpgmodule {
class I_Soul;
}

namespace wh::xgenaimodule {

class C_StanceTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect> {
public:
    ~C_StanceTrigger() override;                                             // [0] 0x18159E8D4
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<
        wh::conceptmodule::C_Effect>)                                        // [5..7], vtable 0x183AEA950
    void OnEffectActivate() override;                                        // [43] 0x18129E66C
    void OnEffectDeactivate() override;                                      // [44] 0x183282D9C

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<wh::rpgmodule::I_Soul*>> m_souls;                        // +0xB0 RTTR "Souls"
    wh::conceptmodule::C_TypedPortRef<
        wh::entitymodule::E_StanceCategory::Type> m_stance;                  // +0xF0 RTTR "Stance"
    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<C_SmartObject*>> m_objects;                              // +0x130 RTTR "Objects"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onStanceMatched;                     // +0x170 RTTR "OnStanceMatched"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onStanceUnmatched;                   // +0x1B0 RTTR "OnStanceUnmatched"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAllStanceMatched;                  // +0x1F0 RTTR "OnAllStanceMatched"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAllStanceUnmatched;                // +0x230 RTTR "OnAllStanceUnmatched"
    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::I_Soul*> m_soul;                                      // +0x270 RTTR "Soul"
    wh::conceptmodule::C_TypedPortRef<C_SmartObject*> m_object;              // +0x2B0 RTTR "Object"
    std::uint8_t m_unknown2F0[0x20];                                         // +0x2F0
};

static_assert(offsetof(C_StanceTrigger, m_souls) == 0xB0,
              "C_StanceTrigger::m_souls offset mismatch");
static_assert(offsetof(C_StanceTrigger, m_object) == 0x2B0,
              "C_StanceTrigger::m_object offset mismatch");
static_assert(sizeof(C_StanceTrigger) == 0x310,
              "C_StanceTrigger size mismatch");

} // namespace wh::xgenaimodule
