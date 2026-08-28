#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"

namespace wh::entitymodule {
class C_LedgeObject;
}

namespace wh::xgenaimodule {

class C_NonInteractiveLedgeTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect> {
public:
    C_NonInteractiveLedgeTrigger();                                          // 0x1813144A0
    ~C_NonInteractiveLedgeTrigger() override;
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<
        wh::conceptmodule::C_Effect>)                                        // [5..7], vtable 0x183BA3F00
    void OnEffectActivate() override;                                        // [43] 0x183282A98
    void OnEffectDeactivate() override;                                      // [44] 0x183282CD8

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<wh::entitymodule::C_LedgeObject*>> m_ledges;             // +0xB0 RTTR "Ledges"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onUsed;                              // +0xF0 RTTR "OnUsed"
    wh::conceptmodule::C_TypedPortRef<
        wh::entitymodule::C_LedgeObject*> m_usedLedge;                       // +0x130 RTTR "UsedLedge"
    std::uint8_t m_unknown170[0x20];                                         // +0x170
};

static_assert(offsetof(C_NonInteractiveLedgeTrigger, m_ledges) == 0xB0,
              "C_NonInteractiveLedgeTrigger::m_ledges offset mismatch");
static_assert(offsetof(C_NonInteractiveLedgeTrigger, m_onUsed) == 0xF0,
              "C_NonInteractiveLedgeTrigger::m_onUsed offset mismatch");
static_assert(offsetof(C_NonInteractiveLedgeTrigger, m_usedLedge) == 0x130,
              "C_NonInteractiveLedgeTrigger::m_usedLedge offset mismatch");
static_assert(sizeof(C_NonInteractiveLedgeTrigger) == 0x190,
              "C_NonInteractiveLedgeTrigger size mismatch");

} // namespace wh::xgenaimodule
