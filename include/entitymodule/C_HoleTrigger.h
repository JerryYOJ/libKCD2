#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"

namespace wh::entitymodule {

class C_Hole;

class C_HoleTrigger : public wh::conceptmodule::C_Effect {
public:
    C_HoleTrigger();                                                    // 0x18152C8FC
    ~C_HoleTrigger() override;                                         // [0] 0x1816A74BC
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                            // [5..7], vtable 0x183E9BAF0
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                    // [27] 0x1829A9104
    void OnEffectActivate() override;                                  // [43] 0x180DBF10C
    void OnEffectDeactivate() override;                                // [44] 0x1829A9C6C

    wh::conceptmodule::C_TypedPortRef<C_Hole*> m_hole;                 // +0x88 RTTR "Hole"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onStarted;                      // +0xC8 RTTR "OnStarted"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onStopped;                      // +0x108 RTTR "OnStopped"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onFinished;                     // +0x148 RTTR "OnFinished"
    bool m_isSubscribed;                                               // +0x188
    std::uint8_t m_padding189[7];                                      // +0x189
    C_Hole* m_activeHole;                                              // +0x190 borrowed callback source
};

static_assert(offsetof(C_HoleTrigger, m_hole) == 0x88,
              "C_HoleTrigger::m_hole offset mismatch");
static_assert(offsetof(C_HoleTrigger, m_onStarted) == 0xC8,
              "C_HoleTrigger::m_onStarted offset mismatch");
static_assert(offsetof(C_HoleTrigger, m_onStopped) == 0x108,
              "C_HoleTrigger::m_onStopped offset mismatch");
static_assert(offsetof(C_HoleTrigger, m_onFinished) == 0x148,
              "C_HoleTrigger::m_onFinished offset mismatch");
static_assert(offsetof(C_HoleTrigger, m_isSubscribed) == 0x188,
              "C_HoleTrigger::m_isSubscribed offset mismatch");
static_assert(offsetof(C_HoleTrigger, m_activeHole) == 0x190,
              "C_HoleTrigger::m_activeHole offset mismatch");
static_assert(sizeof(C_HoleTrigger) == 0x198,
              "C_HoleTrigger size mismatch");

} // namespace wh::entitymodule
