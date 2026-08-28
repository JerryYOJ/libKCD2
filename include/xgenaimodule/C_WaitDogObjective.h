#pragma once
#include <vector>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/TimeValue.h"
#include "C_DogObjective.h"
#include "S_WaitPhase.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_WaitDogObjective : C_DogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0xE0. 19 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_WaitDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183A66960, COL 0x1840DD2A0 offset 0, CHD 0x184564DF0 nbase=4 (single inheritance).
// ctor 0x18099C290(this, I_DogObjectiveContext*), dtor 0x18116CB38.
// Pack embed C_DogObjectivePack+0x4F8 -- THIS is C_DogObjectivePack::FindByType's
// miss-path fallback (0x1809F6BD4 `lea rax,[r10+4F8h]`), i.e. the idle default when
// no other objective is found by type. C_FailDogObjective is a SEPARATE leaf at
// pack+0xD58 (GetType 13) -- not related to the miss path.
//
// Idle fallback: Accept/CanStart always true (forces score/start eligibility even
// while the actor-busy flag is set, via unk_14). Runs a 4-phase Markov "idle
// action" state machine (S_WaitPhase) and, between actions, opportunistically
// walks toward nearby master-relative activity via a "wait-ahead" nav probe.

namespace wh::xgenaimodule::activitysystem {

class C_WaitDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_WaitDogObjective;

    void  StopIfRunning() override;                    // [4]  0x182098590  parent body 0x1809F4E08, then sentinel to +0x78/+0x80/+0x88/+0x90/+0x98
    bool  Accept(const S_DogObjectiveRequest*) override; // [6]  0x18041A6A0  return true (parent C_ActivityObjective returns false); request ignored
    void  BeginWork() override;                          // [8]  0x1807D83F8  arm 10s start window; if actor busy set m_skipWork and return; else snapshot pos, PickPhase, hook action cb, add to AI list
    void  Tick() override;                                // [10] 0x1809F7258  skip if m_fsm==3 or m_skipWork; else phase/hub-lane/extra-action timers + wait-ahead
    void  unk_11() override;                               // [11] StopWork 0x1807D8340  always clears hub+0xD0 lane; if !m_skipWork: disconnect cbs, reset fsm/timers, remove from AI list
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override; // [12] 0x18116D790  busy / hub+0x2B8 (band-3 20.0+eps) / facing-dot lerp
    bool  unk_14() override;                                // [14] CanScoreWhileBusy 0x18041A6A0  return true (parent C_ActivityObjective returns false)
    E_DogObjective::Type GetType() const override;         // [17] 0x180838AE0  return 0 (Wait)
    void  unk_18() override;                                 // [18] FillCatchupHint 0x18179675C  fires ONLY while the 10s start window is unset/expired (0x180731070), not while still running

    CTimeValue m_phaseDeadline;        // +0x78  sentinel -100000; PickPhase arms from S_WaitPhase::duration, 5s jitter
    CTimeValue m_freshDeadline;        // +0x80  sentinel; PickPhase arms 2.5s, 0 jitter; ComputeScore reads due-bool into score out+5
    CTimeValue m_hubLaneDeadline;      // +0x88  sentinel; ApplyPhase arms 1.0s; Tick due -> write hubLane2 into hub+0x48 idx2, reset
    CTimeValue m_extraActionDeadline;  // +0x90  sentinel; armed now+(remain-3.5)*0.5 +- same jitter when allowExtraAction; Tick due -> clear hub lane, stop anim
    CTimeValue m_startWindowDeadline;  // +0x98  sentinel; BeginWork arms now+10s (dword_18492F28C) BEFORE the busy check
    Vec3       m_waitDest;             // +0xA0  wait-ahead nav result; issued as move-mode 4
    Vec3       m_beginPos;             // +0xAC  BeginWork snapshot of NPC pos; write-only, no reader found in this class
    bool       m_moveCbHooked;         // +0xB8  guards Disconnect of 0x18330DB3C on ctx[1]+0x128
    bool       m_skipWork;             // +0xB9  set in BeginWork when actor busy (activityContext[0]()+0x118); Tick/StopWork gate on it
    uint8_t    m_fsm;                  // +0xBA  0 idle/playing, 1 action issued, 2 action-cb stage, 3 moving-to-dest (Tick bails if ==3)
    uint8_t    _padBB[5];
    S_WaitPhase*              m_pPhase;   // +0xC0  points into m_phases; dangling risk on realloc; 0 = no current phase
    std::vector<S_WaitPhase>  m_phases;   // +0xC8  ctor populates the 4-entry Markov table
};
static_assert(sizeof(C_WaitDogObjective) == 0xE0, "C_WaitDogObjective must be 0xE0");
static_assert(offsetof(C_WaitDogObjective, m_waitDest) == 0xA0, "m_waitDest at +0xA0");
static_assert(offsetof(C_WaitDogObjective, m_pPhase) == 0xC0, "m_pPhase at +0xC0");
static_assert(offsetof(C_WaitDogObjective, m_phases) == 0xC8, "m_phases at +0xC8");

// unk_18 [18] polarity (corrected from an earlier draft): 0x180731070 is a READY test (true if
// the CTimeValue is the sentinel OR already expired). The catch-up hint's out+0 byte is forced 0
// while m_startWindowDeadline is still a valid, unexpired future time -- NOT while it's running,
// the inverse of the naive reading of "during the start window."
// Wait-ahead (Tick, unconditional on m_pPhase -- not gated by it): skips a listed object equal to
// GetMaster() when hub+0x290==1 && hub+0x2B8==0; objects with speed-lensq<=0.0075 are also
// skipped; move-mode 4 issue failure calls ApplyPhase(this,0) rather than aborting outright.

}  // namespace wh::xgenaimodule::activitysystem
