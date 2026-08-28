#pragma once
#include <cstddef>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "../entitymodule/S_ItemClassGUID.h"

namespace wh::playermodule {

class C_Reading;

class C_UseBookTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect> {
public:
    C_UseBookTrigger();
    ~C_UseBookTrigger() override;                               // [0] 0x18167E750
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27] 0x182DE0A4C
    void OnEffectActivate() override;                           // [43] 0x1809F292C
    void OnEffectDeactivate() override;                         // [44] 0x1809F26F0

    wh::conceptmodule::C_TypedPortRef<
        wh::entitymodule::S_ItemClassGUID> m_book;              // +0xB0
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onOpened;               // +0xF0
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onClosed;               // +0x130
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onLastPageTurned;       // +0x170
    C_Reading* m_pReading;                                      // +0x1B0
};

static_assert(sizeof(C_UseBookTrigger) == 0x1B8,
              "C_UseBookTrigger size mismatch");
static_assert(offsetof(C_UseBookTrigger, m_book) == 0xB0,
              "C_UseBookTrigger book offset mismatch");
static_assert(offsetof(C_UseBookTrigger, m_pReading) == 0x1B0,
              "C_UseBookTrigger session offset mismatch");

} // namespace wh::playermodule
