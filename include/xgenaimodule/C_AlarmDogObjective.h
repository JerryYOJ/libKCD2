#pragma once
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/TimeValue.h"
#include "C_DogObjective.h"
#include "C_NPCWatch.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_AlarmDogObjective : C_DogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0xF0. 19 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_AlarmDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183A823B8, COL 0x1840DD840 offset 0, CHD 0x184562BC8 nbase=4 (single inheritance).
// ctor 0x180BC9E4C(this, I_DogObjectiveContext*), dtor 0x18116CA68.
// Pack embed C_DogObjectivePack+0xB58. E_DogObjective::Alarm = 12 (0x0C).
//
// Point-and-bark at a requested NPC (mode 1, "normal"), or -- when unbound and a host-side gate
// is set -- occasionally fire a fake/disobedience alarm (mode 2) on an 180s cooldown. Accept
// requires S_DogObjectiveRequest::m_hasTarget resolvable via C_NPCManager; Apply installs that
// I_NPC* into m_watch. unk_03 [3] (rare override on this leaf) hooks a per-instance host event
// (0x67) whose 0/1 edge feeds m_fakeAlarmAllowed.

namespace wh::xgenaimodule::activitysystem {

class C_AlarmDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_AlarmDogObjective;

    void  unk_03() override;                                              // [3]  0x180A4A08C  HookHostEvent: register {this, event 0x67} on GetNPC()->vf+0xE0()->vf+0x260()
    void  StopIfRunning() override;                                        // [4]  0x181951AE4  unregister the 0x67 pair, then parent body, then sentinel both CTimeValues
    bool  Accept(const S_DogObjectiveRequest*) override;                    // [6]  0x18330040C  m_hasTarget (+0x2A) && C_NPCManager Find(request->m_target) != 0
    void  Apply(const S_DogObjectiveRequest*) override;                      // [7]  0x1833028B0  Find WUID -> m_watch.SetValue(npc); m_requestedMode = 1
    void  BeginWork() override;                                              // [8]  0x183301F64  CommitMode(m_requestedMode); arm yield timer; hub channel writes; Connect watch signals
    void  Tick() override;                                                    // [10] 0x183302DC8  mode-timer expiry -> Complete(1); lost target in mode 1 -> Complete(0); else CommitMode + facing update
    void  unk_11() override;                                                  // [11] 0x1833023F4  EndWork: disconnect signals, clear watch, reset timers/mode, stamp m_fakeAlarmLastRoll
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override;          // [12] 0x180395658  in-range distance lerp (mode 1) or 180s-gated fake-alarm roll (mode 2); see class comment
    E_DogObjective::Type GetType() const override;                         // [17] 0x181A99DC0  return 0x0C (Alarm)

    C_NPCWatch  m_watch;                // +0x78  sizeof 0x50
    Vec2        m_facing;               // +0xC8  dog-forward vs to-target XY direction, written by Tick's facing update
    bool        m_fakeAlarmAllowed;     // +0xD0  (host vf+0x1F0()->vf+0x10() == 0); name INFERRED
    uint8_t     _padD1[3];              // +0xD1
    float       m_fakeAlarmLastRoll;    // +0xD4  ITimer seconds at last EndWork; gates the 180s fake-alarm pause
    CTimeValue  m_yieldDeadline;        // +0xD8  AlarmYieldingDelay; ComputeScore's out+5 "yield" byte follows this
    CTimeValue  m_modeDeadline;         // +0xE0  mode-1/mode-2 duration; armed as now + Duration + U[0,Variation)
    uint8_t     m_mode;                 // +0xE8  0 idle, 1 normal alarm, 2 fake/disobedience (committed)
    uint8_t     m_requestedMode;        // +0xE9  mode requested by Apply/ComputeScore, applied via CommitMode
    uint8_t     _padEA[2];              // +0xEA
    uint32_t    m_alarmEntryId;         // +0xEC  invalid 0xFFFFFFFF; id in the dog NPC's +0x120 alarm-participant list (mode 1 only)
};
static_assert(sizeof(C_AlarmDogObjective) == 0xF0, "C_AlarmDogObjective must be 0xF0");
static_assert(offsetof(C_AlarmDogObjective, m_facing) == 0xC8, "m_facing at +0xC8");
static_assert(offsetof(C_AlarmDogObjective, m_yieldDeadline) == 0xD8, "m_yieldDeadline at +0xD8");
static_assert(offsetof(C_AlarmDogObjective, m_alarmEntryId) == 0xEC, "m_alarmEntryId at +0xEC");

// Mode deadlines are NOT "+- Variation": the arming helper computes now + Duration + U[0,Variation),
// a one-sided jitter, for both mode 1 (AlarmObjectiveDuration/Variation, default 30/10s) and mode 2
// (AlarmObjectiveDisobedienceDuration, default 15s, same Variation). ComputeScore additionally keeps
// a running mode-2 alarm alive at score 35 without re-rolling while m_bound; the LCG-gated re-roll
// only fires on the fully unbound path. EndWork stamps m_fakeAlarmLastRoll unconditionally (any
// teardown starts the 180s pause), not only after an actual fake-alarm roll.

}  // namespace wh::xgenaimodule::activitysystem
