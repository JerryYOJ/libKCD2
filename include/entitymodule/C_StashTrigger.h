#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "I_RemovedEntityListener.h"

namespace wh::entitymodule {

class C_Stash;

class C_StashTrigger
    : public wh::conceptmodule::C_Effect,
      public I_RemovedEntityListener {
public:
    C_StashTrigger();                                                   // 0x181469B6C
    ~C_StashTrigger() override;                                        // [0] 0x1815FFB28
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                            // [5..7], vtable 0x183B8EB20
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                    // [27] 0x1829A972C
    void OnEffectActivate() override;                                  // [43] 0x180DBF0DC
    void OnEffectDeactivate() override;                                // [44] 0x180DA66AC

    bool OnRemove(IEntity* entity) override;                            // +0x88 [3] 0x1812B544C
    const char* GetName() const override;                               // +0x88 [7] 0x181A86DA0

    wh::conceptmodule::C_TypedPortRef<C_Stash*> m_stash;               // +0x90 RTTR "Stash"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onOpened;                       // +0xD0 RTTR "OnOpened"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onClosed;                       // +0x110 RTTR "OnClosed"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onUnlocked;                     // +0x150 RTTR "OnUnlocked"
    bool m_isConnected;                                                 // +0x190
    std::uint8_t m_padding191[7];                                      // +0x191
    C_Stash* m_activeStash;                                            // +0x198 borrowed callback source
};

static_assert(offsetof(C_StashTrigger, m_stash) == 0x90,
              "C_StashTrigger::m_stash offset mismatch");
static_assert(offsetof(C_StashTrigger, m_onOpened) == 0xD0,
              "C_StashTrigger::m_onOpened offset mismatch");
static_assert(offsetof(C_StashTrigger, m_onClosed) == 0x110,
              "C_StashTrigger::m_onClosed offset mismatch");
static_assert(offsetof(C_StashTrigger, m_onUnlocked) == 0x150,
              "C_StashTrigger::m_onUnlocked offset mismatch");
static_assert(offsetof(C_StashTrigger, m_isConnected) == 0x190,
              "C_StashTrigger::m_isConnected offset mismatch");
static_assert(offsetof(C_StashTrigger, m_activeStash) == 0x198,
              "C_StashTrigger::m_activeStash offset mismatch");
static_assert(sizeof(C_StashTrigger) == 0x1A0,
              "C_StashTrigger size mismatch");

} // namespace wh::entitymodule
