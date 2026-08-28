#pragma once
#include <cstddef>
#include <memory>
#include "C_RuntimeState.h"
#include "C_TypedPortRef.h"
#include "S_Trigger.h"
#include "framework/C_Signal.h"

namespace wh::conceptmodule {

class C_SceneFinishedWaiter : public C_RuntimeState {
public:
    C_SceneFinishedWaiter();                                // 0x1813D0C88
    ~C_SceneFinishedWaiter() override;                      // [0] 0x18155FAF4
    RTTR_ENABLE(C_RuntimeState)                             // [5..7]
    void EnumerateNodeVariants(
        definition::NodeDefinitionSink sink,
        bool allVariants) override;                         // [27] 0x18268E8AC
    void OnExecute(
        S_NodeExecuteContext const& context) override;       // [33] 0x18268E068
    void OnDeserializationComplete() override;              // [41] 0x181152434

    C_TypedPortRef<S_Trigger> m_enqueue;                     // +0x40 RTTR "Enqueue", In
    C_TypedPortRef<S_Trigger> m_onEnqueue;                   // +0x80 RTTR "OnEnqueue", Out
    C_TypedPortRef<S_Trigger> m_onFinished;                  // +0xC0 RTTR "OnFinished", Out
    std::shared_ptr<wh::shared::C_Signal<char>>
        m_completionSignal;                                 // +0x100, callback status 0 emits OnFinished
};

static_assert(offsetof(C_SceneFinishedWaiter, m_enqueue) == 0x40,
              "C_SceneFinishedWaiter::m_enqueue offset mismatch");
static_assert(offsetof(C_SceneFinishedWaiter, m_onEnqueue) == 0x80,
              "C_SceneFinishedWaiter::m_onEnqueue offset mismatch");
static_assert(offsetof(C_SceneFinishedWaiter, m_onFinished) == 0xC0,
              "C_SceneFinishedWaiter::m_onFinished offset mismatch");
static_assert(offsetof(C_SceneFinishedWaiter, m_completionSignal) == 0x100,
              "C_SceneFinishedWaiter::m_completionSignal offset mismatch");
static_assert(sizeof(C_SceneFinishedWaiter) == 0x110,
              "C_SceneFinishedWaiter size mismatch");

}  // namespace wh::conceptmodule
