#pragma once
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/TimeValue.h"
#include "C_DogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_FollowDogObjective : C_DogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0xB0. 25 slots, 6 new (default "stick with master" objective).
// -----------------------------------------------
// RTTI .?AVC_FollowDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183B1F2B0, COL 0x1840DCFA8 offset 0, CHD 0x184564E80 nbase=4 (single inheritance).
// ctor 0x18116C74C(this, I_DogObjectiveContext*), dtor 0x18330A7F4.
// Pack embed C_DogObjectivePack+0x448. Also the CONCRETE BASE of C_FollowHeelDogObjective
// (pack+0x5D8 inlines this ctor then overwrites the vtable). C_FollowRiderDogObjective
// (pack+0x698) does NOT derive from this class -- it calls C_DogObjective's ctor directly.
//
// Autonomous: Accept always true, Apply is a no-op (not request-driven). CanStart reduces to
// HasFollowableMaster (GetMaster() && hub E_DogMasterLocationState != 0), or unconditionally true
// while mounted (AllowWhenMounted opts out of C_ActivityObjective::CanStart's busy veto).
// BeginWork picks a dest ahead of the master (facing-lead x GetDynamicLeadFactor/GetStaticLeadFactor
// gated by the SIGN of m_leadScale, not by motion state) and issues a move; Tick restarts the move
// once the dest goes stale.

namespace wh::xgenaimodule::activitysystem {

class C_FollowDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FollowDogObjective;

    void  StopIfRunning() override;                                 // [4]  0x182098550  parent body, then sentinel the three own CTimeValues
    bool  Accept(const S_DogObjectiveRequest*) override;             // [6]  0x18041A6A0  return true; request unused
    void  BeginWork() override;                                        // [8]  0x1806276F8  mounted: TryCommandTowardDest + complete; on foot: pick dest, issue move, hook gait callback
    void  unk_09() override;                                            // [9]  0x181AA5730  InvalidateDest: m_hasDest = false
    void  Tick() override;                                               // [10] 0x1809F60DC  dist tracking, gait refresh, restart via RestartFollow when the follow bubble is exceeded
    void  unk_11() override;                                             // [11] 0x1809F63B4  EndWork: unhook callbacks, clear wiggle/sniff context, arm 2.5s restart cooldown, clear m_hasDest
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override;    // [12] 0x1807368B4  mounted/facing/distance blend; see class comment
    bool  unk_13() override;                                            // [13] 0x181389A6C  HasFollowableMaster: GetMaster() && hub E_DogMasterLocationState != 0
    bool  unk_14() override;                                             // [14] 0x18041A6A0  AllowWhenMounted: return true (opts out of the CanStart busy veto)
    E_DogObjective::Type GetType() const override;                    // [17] 0x181A78EA0  return 4 (Follow)

    virtual float GetFollowDistance() const;                          // [19] 0x180627890  return 4.0f (dword_18492F2D8). Heel overrides per-mount radius
    virtual float GetDynamicLeadFactor() const;                        // [20] 0x181AA6AB0  return 0.7f; used when m_leadScale > 0 (dest-pick multiplies it in)
    virtual float GetStaticLeadFactor() const;                          // [21] 0x181AA6AB0  return 0.7f (same impl as [20] on this class); used when m_leadScale <= 0 (flat replacement)
    virtual bool  ShouldRestartIfMasterMoving() const;                    // [22] 0x18041A6A0  return true; Tick restart gate: master moving AND already within 5m of dest
    virtual void  RestartFollow();                                         // [23] 0x1809F47CC  m_moveIssued = false; CompleteInternal(this, 1)
    virtual void  ApplyFollowContext();                                     // [24] 0x1809F4C64  hub wiggle channel 3 = 2, sniffing channel 0 = 2

    bool        m_moveIssued;          // +0x78
    bool        m_destFar;             // +0x79  set when the far-path occupy (>400m) was taken
    uint8_t     _pad7A[2];             // +0x7A
    Vec3        m_dest;                // +0x7C  NOT ctor-initialized; first write is dest-pick in BeginWork
    bool        m_hasDest;             // +0x88
    bool        m_arrivedCbHooked;     // +0x89
    bool        m_mountedMode;         // +0x8A  INFERRED name; copies activity-context "+0x118" bool getter, exact declaring type unwalked
    uint8_t     _pad8B[5];             // +0x8B
    CTimeValue  m_restartCooldown;     // +0x90  INFERRED name; sentinel -100000; armed 2.5s by unk_11/RestartFollow paths
    CTimeValue  m_gaitTimer;           // +0x98  sentinel -100000; armed 0.4s, refreshes locomotion gait on expiry
    CTimeValue  m_mountedRetryTimer;   // +0xA0  sentinel -100000; armed 1.0s on mounted BeginWork failure
    float       m_leadScale;           // +0xA8  default 1.0f; dot(velDir,faceDir)*speed + 1.0 when master moving fast enough
    float       m_destDistSq;          // +0xAC  |NPC_pos - m_dest|^2, refreshed every Tick
};
static_assert(sizeof(C_FollowDogObjective) == 0xB0, "C_FollowDogObjective must be 0xB0");
static_assert(offsetof(C_FollowDogObjective, m_dest) == 0x7C, "m_dest at +0x7C");
static_assert(offsetof(C_FollowDogObjective, m_restartCooldown) == 0x90, "m_restartCooldown at +0x90");
static_assert(offsetof(C_FollowDogObjective, m_leadScale) == 0xA8, "m_leadScale at +0xA8");

// [22] ShouldRestartIfMasterMoving: the Tick gate is "destDistSq < 5^2" (already close), NOT
// "farther than 5m" -- do not invert this when reading Tick. [20]/[21] must NOT be named
// Moving/Idle: m_leadScale defaults to 1.0 (positive) even at rest, so idle still takes [20] --
// the split is on the SIGN of m_leadScale, not motion state (Heel's overrides use these same two
// slots with CVar names s_FollowHeelDynamicOffset/s_FollowHeelStaticOffset, which is where these
// names come from). [8] BeginWork's mounted branch always returns via CompleteInternal -- it
// never leaves the objective self-running while mounted.

}  // namespace wh::xgenaimodule::activitysystem
