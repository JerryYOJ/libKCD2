#pragma once
#include <cstdint>
#include "conceptmodule/C_RuntimeState.h"
#include "conceptmodule/C_TypedPortRef.h"
#include "conceptmodule/S_Trigger.h"
#include "guimodule/I_CutsceneChangeListener.h"

// -----------------------------------------------
// wh::guimodule::C_CutsceneHandler -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x2E0 (ALLOC-PROVEN).
// -----------------------------------------------
// RTTI TD 0x184C9E118; COLs +0x00/0x413A928, +0x40/0x413A950; primary vtable 0x183B1C288
// (the 42-slot conceptmodule C_RuntimeState node table -- not modeled as C++ virtuals
// per module convention), I_CutsceneChangeListener @+0x40 vtable 0x183B1C1B0.
// ctor sub_18115229C (chains the C_Node ctor sub_1806B2744); as_wh_smart_ptr creator
// sub_181152200 (alloc 0x2E0 @0x18115222b); as_std_shared_ptr creator sub_182B0BBE4.
//
// Concept-graph node bridging cutscene lifecycle -> trigger outputs: OnCutsceneChanged
// (0x182B12028) fires the S_Trigger output ports per changeType (dispatch at
// handler+392/+520/+584 via port vf[+0x78]). Port display-names RESOLVED 2026-08-05
// (RTTR registration 0x181169818, all 10 property sites walked): EnqueueCutscene/
// PlayCutscene/FinishCutscene inputs gated by a state machine at +0x2C8 (0=ready,
// requires 2 to Play, requires 4 to Finish); AutoPlay/AutoFinish bools; outputs
// OnQueued/BeforePlay/AfterPlay/OnFinished in that order.

namespace wh::entitymodule { class C_CutsceneHolder; }

namespace wh::guimodule {

class C_CutsceneHandler : public wh::conceptmodule::C_RuntimeState,   // +0x00 (0x40)
                          public I_CutsceneChangeListener {           // +0x40
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CutsceneHandler;
    void OnCutsceneChanged(I_Cutscene* pCutscene, int changeType) override;   // 0x182B12028

    wh::conceptmodule::C_TypedPortRef<wh::conceptmodule::S_Trigger> m_enqueueCutscenePort;  // +0x48  In -- EnqueueCutscene
    wh::conceptmodule::C_TypedPortRef<wh::conceptmodule::S_Trigger> m_playCutscenePort;     // +0x88  In -- PlayCutscene (requires state +0x2C8==2)
    wh::conceptmodule::C_TypedPortRef<wh::conceptmodule::S_Trigger> m_finishCutscenePort;   // +0xC8  In -- FinishCutscene (requires state +0x2C8==4)
    wh::conceptmodule::C_TypedPortRef<wh::entitymodule::C_CutsceneHolder*> m_cutscenePort;  // +0x108 In -- CutsceneHolder
    wh::conceptmodule::C_TypedPortRef<bool> m_autoPlayPort;                                  // +0x148 In -- AutoPlay
    wh::conceptmodule::C_TypedPortRef<bool> m_autoFinishPort;                                // +0x188 In -- AutoFinish
    wh::conceptmodule::C_TypedPortRef<wh::conceptmodule::S_Trigger> m_onQueuedPort;         // +0x1C8 Out -- OnQueued (changeType 0)
    wh::conceptmodule::C_TypedPortRef<wh::conceptmodule::S_Trigger> m_beforePlayPort;       // +0x208 Out -- BeforePlay (changeType 1)
    wh::conceptmodule::C_TypedPortRef<wh::conceptmodule::S_Trigger> m_afterPlayPort;        // +0x248 Out -- AfterPlay (changeType 2)
    wh::conceptmodule::C_TypedPortRef<wh::conceptmodule::S_Trigger> m_onFinishedPort;       // +0x288 Out -- OnFinished (changeType 3, teardown)
    int32_t  m_int2C8;              // +0x2C8  ctor 0; cutscene state machine (0=ready, 2=queued/played gate, 4=finish gate)
    uint8_t  m_byte2CC;             // +0x2CC  ctor 0; cutscene-listener-registered guard flag (set by EnqueueCutscene's subscribe, tested by teardown)
    uint8_t  _pad2CD[3];            // +0x2CD
    I_Cutscene* m_pTrackedCutscene; // +0x2D0  currently-tracked cutscene; OnCutsceneChanged 0x182B1203F returns early unless (this == changed cutscene); +0x2D8 = its _smart_ptr control
    volatile int32_t* m_pRefCount;  // +0x2D8  smart-ptr control [ctor 0]
};
static_assert(sizeof(C_CutsceneHandler) == 0x2E0, "C_CutsceneHandler must be 0x2E0 (creator sub_181152200)");
static_assert(offsetof(C_CutsceneHandler, m_enqueueCutscenePort) == 0x48, "first port at 0x48");
static_assert(offsetof(C_CutsceneHandler, m_onFinishedPort) == 0x288, "last output port at 0x288");

}  // namespace wh::guimodule
