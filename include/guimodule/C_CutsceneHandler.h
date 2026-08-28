#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "conceptmodule/C_RuntimeState.h"
#include "conceptmodule/C_TypedPortRef.h"
#include "conceptmodule/S_Trigger.h"
#include "guimodule/I_CutsceneChangeListener.h"

namespace wh::entitymodule { class C_CutsceneHolder; }

namespace wh::guimodule {

class C_CutsceneHandler : public wh::conceptmodule::C_RuntimeState, // +0x00
                          public I_CutsceneChangeListener {          // +0x40
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CutsceneHandler;

    C_CutsceneHandler();                                           // 0x18115229C
    ~C_CutsceneHandler() override;                                 // [0] 0x181152058
    RTTR_ENABLE(wh::conceptmodule::C_RuntimeState)                  // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                // [27] 0x182B130AC
    void OnExecute(
        wh::conceptmodule::S_NodeExecuteContext const& context) override; // [33] 0x182B1280C
    void OnDeserializationComplete() override;                     // [41] 0x1811523D8
    void OnCutsceneChanged(
        I_Cutscene* cutscene, int changeType) override;            // secondary [0] 0x182B12028

    wh::conceptmodule::C_TypedPortRef<wh::conceptmodule::S_Trigger>
        m_enqueueCutscenePort;                                     // +0x48 RTTR "EnqueueCutscene", In
    wh::conceptmodule::C_TypedPortRef<wh::conceptmodule::S_Trigger>
        m_playCutscenePort;                                        // +0x88 RTTR "PlayCutscene", In
    wh::conceptmodule::C_TypedPortRef<wh::conceptmodule::S_Trigger>
        m_finishCutscenePort;                                      // +0xC8 RTTR "FinishCutscene", In
    wh::conceptmodule::C_TypedPortRef<wh::entitymodule::C_CutsceneHolder*>
        m_cutscenePort;                                            // +0x108 RTTR "Cutscene", In
    wh::conceptmodule::C_TypedPortRef<bool> m_autoPlayPort;        // +0x148 RTTR "AutoPlay", In
    wh::conceptmodule::C_TypedPortRef<bool> m_autoFinishPort;      // +0x188 RTTR "AutoFinish", In
    wh::conceptmodule::C_TypedPortRef<wh::conceptmodule::S_Trigger>
        m_onQueuedPort;                                            // +0x1C8 RTTR "OnQueued", Out
    wh::conceptmodule::C_TypedPortRef<wh::conceptmodule::S_Trigger>
        m_beforePlayPort;                                          // +0x208 RTTR "BeforePlay", Out
    wh::conceptmodule::C_TypedPortRef<wh::conceptmodule::S_Trigger>
        m_afterPlayPort;                                           // +0x248 RTTR "AfterPlay", Out
    wh::conceptmodule::C_TypedPortRef<wh::conceptmodule::S_Trigger>
        m_onFinishedPort;                                          // +0x288 RTTR "OnFinished", Out
    std::int32_t m_state;                                          // +0x2C8, 0/2/4 input gate
    bool m_listenerRegistered;                                    // +0x2CC
    std::uint8_t m_unknown2CD[3];
    std::shared_ptr<I_Cutscene> m_trackedCutscene;                 // +0x2D0
};

static_assert(offsetof(C_CutsceneHandler, m_enqueueCutscenePort) == 0x48,
              "C_CutsceneHandler::m_enqueueCutscenePort offset mismatch");
static_assert(offsetof(C_CutsceneHandler, m_onFinishedPort) == 0x288,
              "C_CutsceneHandler::m_onFinishedPort offset mismatch");
static_assert(offsetof(C_CutsceneHandler, m_state) == 0x2C8,
              "C_CutsceneHandler::m_state offset mismatch");
static_assert(offsetof(C_CutsceneHandler, m_trackedCutscene) == 0x2D0,
              "C_CutsceneHandler::m_trackedCutscene offset mismatch");
static_assert(sizeof(C_CutsceneHandler) == 0x2E0,
              "C_CutsceneHandler size mismatch");

}  // namespace wh::guimodule
