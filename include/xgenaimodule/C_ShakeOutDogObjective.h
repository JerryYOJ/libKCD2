#pragma once
#include "../CryEngine/CryCommon/TimeValue.h"
#include "C_DogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_ShakeOutDogObjective : C_DogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0xA0. 19 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_ShakeOutDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183C6E860, COL 0x1840DD250 offset 0, CHD 0x1845647A8 nbase=4 (single inheritance).
// ctor 0x1819A279C(this, I_DogObjectiveContext*), dtor 0x18330AAF8.
// Pack embed C_DogObjectivePack+0x1278. E_DogObjective::ShakeOut = 20.
//
// Score-driven "dog shakes water/rain off its coat" objective. Accept is always true; Apply is a
// nullsub (no request payload); Tick is a nullsub -- ComputeScore returns 20.0 when the dog has
// walked through water deeper than ShakeoutMinimumWaterDepth since the last BeginWork, or when
// rain has been above ShakeoutRainThreshold for ShakeoutTimeAfterRainStart and ShakeoutInterval
// has elapsed since the last shake. BeginWork plays a one-shot full-body "shakeout" anim and
// starts the interval timer; completion is driven by that anim's done callback, not by Tick.
// StopIfRunning additionally unregisters the per-instance rain listener (slot [3]) -- nothing
// in this class re-registers it after a stop, so rain scoring is dead once aborted once.

namespace wh::xgenaimodule::activitysystem {

class C_ShakeOutDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ShakeOutDogObjective;

    void  unk_03() override;                                              // [3]  0x180A49FA8  RegisterRainListener: IWeatherSystem[18] insert keyed on this
    void  StopIfRunning() override;                                        // [4]  0x1817E6E74  IWeatherSystem[19] erase, parent body, reset all three CTimeValues to sentinel
    bool  Accept(const S_DogObjectiveRequest*) override;                    // [6]  0x18041A6A0  return true (ignores the request)
    void  BeginWork() override;                                              // [8]  0x180395120  mood write, clear water latch, request "shakeout" anim, Connect action-done, arm interval timer
    void  unk_11() override;                                                  // [11] 0x1819D2494  EndWork: disconnect action-done cb if hooked
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override;          // [12] 0x181341950  20.0 if m_bound or (!m_inWater && (m_wasInWater || rain+interval gate)), else -1.0
    E_DogObjective::Type GetType() const override;                         // [17] 0x181A6ED50  return 0x14 (ShakeOut)

    CTimeValue m_intervalDeadline;    // +0x78  ShakeoutInterval, armed at BeginWork
    CTimeValue m_rainDelayDeadline;   // +0x80  ShakeoutTimeAfterRainStart, armed by the rain listener
    bool       m_isRaining;           // +0x88  pushed by the rain listener callback
    bool       m_inWater;             // +0x89  water-depth poll result (hysteresis vs 0)
    bool       m_wasInWater;          // +0x8A  latched true on any in-water reading; only BeginWork clears it
    uint8_t    _pad8B[5];             // +0x8B
    CTimeValue m_waterPollDeadline;   // +0x90  ~1s water-depth poll cadence
    bool       m_actionCbHooked;      // +0x98
    uint8_t    _pad99[7];             // +0x99
};
static_assert(sizeof(C_ShakeOutDogObjective) == 0xA0, "C_ShakeOutDogObjective must be 0xA0");
static_assert(offsetof(C_ShakeOutDogObjective, m_intervalDeadline) == 0x78, "m_intervalDeadline at +0x78");
static_assert(offsetof(C_ShakeOutDogObjective, m_actionCbHooked) == 0x98, "m_actionCbHooked at +0x98");

// unk_03/unk_11 keep the C_ActivityObjective-declared spellings (source names UNVERIFIED);
// RegisterRainListener/EndWork describe behavior only. unk_03 is C_ActivityObjective's own
// slot [3] (elsewhere a nullsub) -- Alarm overrides the same slot with an unrelated impl, this
// is not a ShakeOut-only virtual. No caller of slot [3] was found in this class or the pack/
// companion ctors, so the rain-listener registration path itself is currently unreachable;
// the water-latch scoring path does not depend on it. Deadlines are armed as now + duration +
// U[0, jitter) (one-sided), not duration +/- jitter.

}  // namespace wh::xgenaimodule::activitysystem
