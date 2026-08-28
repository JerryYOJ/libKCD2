#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "I_RemovedEntityListener.h"

namespace wh::entitymodule {

class C_LockBase;
using C_LockTriggerBase =
    wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>;

class C_LockTrigger
    : public C_LockTriggerBase,
      public I_RemovedEntityListener {
public:
    C_LockTrigger();                                                    // 0x181696F7C
    ~C_LockTrigger() override;                                         // [0] 0x1817FD03C
    RTTR_ENABLE(C_LockTriggerBase)                                     // [5..7], vtable 0x183BEC808
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                    // [27] 0x1829A944C
    void OnEffectActivate() override;                                  // [43] 0x1829A99CC
    void OnEffectDeactivate() override;                                // [44] 0x1829A9D60

    bool OnRemove(IEntity* entity) override;                            // +0xB0 [3] 0x1829A9F6C
    const char* GetName() const override;                               // +0xB0 [7] 0x181A86D90

    wh::conceptmodule::C_TypedPortRef<C_LockBase*> m_lockBase;         // +0xB8 RTTR "LockBase"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onLocked;                       // +0xF8 RTTR "OnLocked"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onUnlocked;                     // +0x138 RTTR "OnUnlocked"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onLockpicked;                   // +0x178 RTTR "OnLockpicked"
    bool m_isConnected;                                                 // +0x1B8
    std::uint8_t m_padding1B9[7];                                      // +0x1B9
    C_LockBase* m_activeLock;                                          // +0x1C0 borrowed callback source
};

static_assert(offsetof(C_LockTrigger, m_lockBase) == 0xB8,
              "C_LockTrigger::m_lockBase offset mismatch");
static_assert(offsetof(C_LockTrigger, m_onLocked) == 0xF8,
              "C_LockTrigger::m_onLocked offset mismatch");
static_assert(offsetof(C_LockTrigger, m_onUnlocked) == 0x138,
              "C_LockTrigger::m_onUnlocked offset mismatch");
static_assert(offsetof(C_LockTrigger, m_onLockpicked) == 0x178,
              "C_LockTrigger::m_onLockpicked offset mismatch");
static_assert(offsetof(C_LockTrigger, m_isConnected) == 0x1B8,
              "C_LockTrigger::m_isConnected offset mismatch");
static_assert(offsetof(C_LockTrigger, m_activeLock) == 0x1C0,
              "C_LockTrigger::m_activeLock offset mismatch");
static_assert(sizeof(C_LockTrigger) == 0x1C8,
              "C_LockTrigger size mismatch");

} // namespace wh::entitymodule
