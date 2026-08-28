#pragma once
#include <cstdint>
#include <functional>
#include <vector>
#include "../framework/C_Signal.h"
#include "I_ObjectivePlannerRunnable.h"
#include "S_DogObjectiveRequest.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_ObjectivePlanner
// (KCD2 WHGame.dll 1.5.6). sizeof 0x58. No vptr / no .?AV.
// -----------------------------------------------
// NOT a member of C_DogObjectivePack (a prior pass wrongly nested it at a synthetic pack+0x1480,
// inflating the pack's sizeof to 0x14D8 -- see C_DogObjectivePack.h). This is a SIBLING field of
// C_DogCompanionContext at +0x1D90, in-place constructed by the context ctor 0x180BC9D10 AFTER
// the pack ctor 0x1809F5960 returns, and destroyed by the context dtor 0x18116C490 (planner dtor
// 0x18116C510 first, then the pack's own dtor 0x18116C590) -- the pack ctor/dtor never touch
// this region. I_DogObjectiveContext [6] and [7] are both 0x1809F6CC0 (GetObjectivePlanner),
// returning `context+0x1D90` from the `context+8` subobject this-pointer.
//
// Drives the dog's objective selection: Enqueue() pushes an S_Request (score + copied
// S_DogObjectiveRequest POD + optional completion callback); Tick() either preempts/advances
// m_pCurrent or, when idle, picks the best-scoring candidate among the queued S_Requests AND
// the pack's own idle leaves (via I_ObjectivePlannerContext[2] ForEachEligibleObjective) and
// starts it. A queued S_Request additionally Applies its stored request payload before starting;
// an idle pack leaf that wins is started directly, with m_pCurrentRequest left null.

namespace wh::xgenaimodule::activitysystem {

class C_ActivityObjective;
class I_ObjectivePlannerContext;

class C_ObjectivePlanner {
public:
    // Queue entry (KCD2 WHGame.dll 1.5.6). sizeof 0x98. 3 slots, 0 new.
    // RTTI .?AUS_Request@C_ObjectivePlanner@activitysystem@xgenaimodule@wh@@
    // vtable 0x183A8A940, COL 0x1840DE1C8 offset 0, CHD 0x18455FB40 nbase=2 (single inheritance).
    // ctor 0x180C58B90(this, uint32_t id, S_Enqueue const*), dtor 0x180626594.
    // Sibling of C_ActivityObjective under I_ObjectivePlannerRunnable, not its subclass --
    // wraps a C_ActivityObjective* plus a copied S_DogObjectiveRequest POD.
    struct S_Request : I_ObjectivePlannerRunnable {
        S_ObjectiveScore* GetScore(S_ObjectiveScore* out) override;  // [1] 0x1817AF504  m_pObjective->CanStart(&m_request) ? stored m_score : miss(-1.0f, band 0)
        void Start(void* session) override;                          // [2] 0x18176E000  erase self from planner queue, m_pObjective->Apply(&m_request), StartObjective(planner, m_pObjective)

        uint32_t                  m_id;           // +0x08  Enqueue's return value; CancelById key
        uint8_t                   _pad0C[4];      // +0x0C
        S_ObjectiveScore          m_score;        // +0x10  snapshot supplied at Enqueue time
        bool                      m_flush;        // +0x18  OR'd into planner m_flushQueued at Enqueue
        bool                      m_stickyScore;  // +0x19  GetCurrentScore uses m_score instead of live GetScore while this request is current
        uint8_t                   _pad1A[6];      // +0x1A
        S_DogObjectiveRequest     m_request;      // +0x20  copied from the enqueue blob; passed to CanStart/Apply
        C_ActivityObjective*      m_pObjective;    // +0x50  target pack leaf (always a C_DogObjective* in practice)
        std::function<void(int&)> m_onComplete;    // +0x58  optional; invoked with the stop/complete code on teardown
    };
    static_assert(sizeof(S_Request) == 0x98, "S_Request must be 0x98");
    static_assert(offsetof(S_Request, m_request) == 0x20, "m_request at +0x20");
    static_assert(offsetof(S_Request, m_pObjective) == 0x50, "m_pObjective at +0x50");
    static_assert(offsetof(S_Request, m_onComplete) == 0x58, "m_onComplete at +0x58");

    wh::shared::C_Signal<C_ActivityObjective*, unsigned> m_onObjectiveEvent;  // +0x00  sentinel 0x18566A3F8; Emit(objective, 1) on start, Emit(objective, 0) on complete/stop
    C_ActivityObjective*       m_pCurrent;         // +0x10  currently running objective, or null when idle
    S_Request*                 m_pCurrentRequest;  // +0x18  set only when m_pCurrent came from a queued S_Request (null for a won idle pack leaf)
    bool                       m_starting;         // +0x20  reentrancy gate: true for the duration of StartObjective
    bool                       m_flushQueued;      // +0x21  true if any queued S_Request::m_flush is set; drains that cohort after the next pick/start step
    uint8_t                    _pad22[6];          // +0x22
    std::vector<S_Request*>    m_queue;            // +0x28
    I_ObjectivePlannerContext* m_pContext;          // +0x40  context+0x10 subobject; only slot [2] ForEachEligibleObjective is used
    uint32_t                   m_nextRequestId;     // +0x48  monotonically incremented by Enqueue
    uint32_t                   m_skipId;            // +0x4C  shared id-gen helper field; no planner-specific writer found -- dormant on this embed
    bool                       m_skipIdEnabled;     // +0x50  dormant, same reason; context ctor zero-inits the whole +0x48..+0x50 tail
    uint8_t                    _pad51[7];           // +0x51
};
static_assert(sizeof(C_ObjectivePlanner) == 0x58,
              "C_ObjectivePlanner must be 0x58");
static_assert(offsetof(C_ObjectivePlanner, m_pCurrent) == 0x10,
              "current objective at +0x10");
static_assert(offsetof(C_ObjectivePlanner, m_queue) == 0x28,
              "request queue at +0x28");
static_assert(offsetof(C_ObjectivePlanner, m_pContext) == 0x40,
              "planner context at +0x40");
static_assert(offsetof(C_ObjectivePlanner, m_nextRequestId) == 0x48,
              "id generator at +0x48");

// m_onObjectiveEvent's true Args are certified in framework/C_Signal.h
// (S_SignalFamily<C_ActivityObjective*, unsigned>); do not add ad-hoc Connect/Emit call sites
// without checking that specialization first. GetScore/Start proposed names on S_Request keep
// the I_ObjectivePlannerRunnable-declared slot order; source spellings are UNVERIFIED.
// m_skipId/m_skipIdEnabled and the shared id-gen helper (0x1803A480C) are laid out here for
// completeness but have no proven writer anywhere in this planner embed -- treat as inert.

}  // namespace wh::xgenaimodule::activitysystem
