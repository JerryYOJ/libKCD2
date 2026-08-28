#pragma once
#include <cstddef>
#include <cstdint>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"

namespace wh::entitymodule {
class C_LockpickableEntity;
}

namespace wh::playermodule {

class C_LockpickingResultTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect> {
public:
    C_LockpickingResultTrigger();
    ~C_LockpickingResultTrigger() override;                     // [0] 0x182DDE0E0
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27] 0x182DE05C4
    void OnEffectActivate() override;                           // [43] 0x182DE121C
    void OnEffectDeactivate() override;                         // [44] 0x182DE1898

    wh::conceptmodule::C_TypedPortRef<
        wh::entitymodule::C_LockpickableEntity*> m_lockpickableEntity; // +0xB0
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onLockpicked;           // +0xF0
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onFailed;               // +0x130
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onInterrupted;          // +0x170
    wh::entitymodule::C_LockpickableEntity* m_pResolvedEntity; // +0x1B0
    bool m_resultHandled;                                       // +0x1B8
    std::uint8_t m_padding1B9[7];                              // +0x1B9
};

static_assert(sizeof(C_LockpickingResultTrigger) == 0x1C0,
              "C_LockpickingResultTrigger size mismatch");
static_assert(offsetof(C_LockpickingResultTrigger, m_lockpickableEntity) == 0xB0,
              "C_LockpickingResultTrigger entity port offset mismatch");
static_assert(offsetof(C_LockpickingResultTrigger, m_pResolvedEntity) == 0x1B0,
              "C_LockpickingResultTrigger resolved entity offset mismatch");
static_assert(offsetof(C_LockpickingResultTrigger, m_resultHandled) == 0x1B8,
              "C_LockpickingResultTrigger state offset mismatch");

} // namespace wh::playermodule
