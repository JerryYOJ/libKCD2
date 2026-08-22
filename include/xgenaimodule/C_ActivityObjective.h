#pragma once
#include <cstdint>
#include <functional>
#include "../framework/C_Signal.h"
#include "I_ObjectivePlannerRunnable.h"
#include "I_ActivityObjectiveContext.h"
#include "S_DogObjectiveRequest.h"
#include "S_ObjectiveScore.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_ActivityObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0x68. 17 slots.
// -----------------------------------------------
// RTTI .?AVC_ActivityObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183A42D68. No standalone ctor — inlined into C_DogObjective 0x1806265D8.
// dtor 0x180626528.

namespace wh::xgenaimodule::activitysystem {

class C_ActivityObjective : public I_ObjectivePlannerRunnable {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ActivityObjective;

    S_ObjectiveScore* GetScore(S_ObjectiveScore* out) override;           // [1] 0x180730F00
    void Start(void* session) override;                                   // [2] 0x1809F7300
    virtual void unk_03();                                                // [3] 0x1803B6E80
    virtual void StopIfRunning();                                         // [4] 0x1809F4E00
    virtual bool CanStart();                                              // [5] 0x182095E20
    virtual bool Accept(const S_DogObjectiveRequest* request);            // [6] 0x180838AE0
    virtual void Apply(const S_DogObjectiveRequest* request);             // [7] 0x1803B6E80
    virtual void BeginWork();                                             // [8] 0x1803B6E80
    virtual void unk_09();                                                // [9] 0x1803B6E80
    virtual void Tick();                                                  // [10] 0x1803B6E80
    virtual void unk_11();                                                // [11] 0x1803B6E80
    virtual S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) = 0;    // [12] 0x181D93E5D
    virtual bool unk_13();                                                // [13] 0x18041A6A0
    virtual bool unk_14();                                                // [14] 0x180838AE0
    virtual void Complete();                                              // [15] 0x1803931E8
    virtual I_ActivityObjectiveContext* GetActivityContext();             // [16] 0x1809DD2D0

    wh::shared::C_Signal<unsigned> m_onComplete;       // +0x08
    I_ActivityObjectiveContext*    m_pActivityContext; // +0x18  C_ActivitySystemContext+8
    void*                          m_pWaitObject;      // +0x20  [U pointee]
    std::function<void()>          m_onRebegin;        // +0x28  signature [U]
};
static_assert(sizeof(C_ActivityObjective) == 0x68,
              "C_ActivityObjective must be 0x68");
static_assert(offsetof(C_ActivityObjective, m_onComplete) == 0x08,
              "complete signal at +0x08");
static_assert(offsetof(C_ActivityObjective, m_onRebegin) == 0x28,
              "std::function at +0x28");

}  // namespace wh::xgenaimodule::activitysystem
