#pragma once
#include <cstddef>
#include <cstdint>
#include "C_EventNode.h"
#include "C_TypedPortRef.h"
#include "S_Trigger.h"
#include "framework/E_GameReleaseVersion.h"

namespace wh::conceptmodule {

class C_PatchTrigger : public C_EventNode<C_Node> {
public:
    C_PatchTrigger();                                      // 0x1812EE9C8
    ~C_PatchTrigger() override;                            // [0] 0x181739FD8
    RTTR_ENABLE(C_EventNode<C_Node>)                       // [5..7]
    void EnumerateNodeVariants(
        definition::NodeDefinitionSink sink,
        bool allVariants) override;                        // [27] 0x18268E7DC
    void OnLifecycleEvent(std::int32_t event) override;    // [34] 0x18176BF90
    std::int32_t MapEventToPhase(std::int32_t event) override; // [35] 0x1816D48D8

    C_TypedPortRef<S_Trigger> m_onPatch;                   // +0x68 RTTR "OnPatch", Out
    C_TypedPortRef<wh::framework::E_GameReleaseVersion::Type>
        m_transitionFromVersion;                           // +0xA8 RTTR "TransitionFromVersion", In
    C_TypedPortRef<wh::framework::E_GameReleaseVersion::Type>
        m_transitionToVersion;                             // +0xE8 RTTR "TransitionToVersion", In
};

static_assert(offsetof(C_PatchTrigger, m_onPatch) == 0x68,
              "C_PatchTrigger::m_onPatch offset mismatch");
static_assert(offsetof(C_PatchTrigger, m_transitionFromVersion) == 0xA8,
              "C_PatchTrigger::m_transitionFromVersion offset mismatch");
static_assert(offsetof(C_PatchTrigger, m_transitionToVersion) == 0xE8,
              "C_PatchTrigger::m_transitionToVersion offset mismatch");
static_assert(sizeof(C_PatchTrigger) == 0x128,
              "C_PatchTrigger size mismatch");

}  // namespace wh::conceptmodule
