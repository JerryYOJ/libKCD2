#pragma once
#include "C_FollowDogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_FollowHeelDogObjective : C_FollowDogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0xC0. 25 slots, 0 new (13 overrides vs Follow).
// -----------------------------------------------
// RTTI .?AVC_FollowHeelDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183D25B68, COL 0x1840DCFD0 offset 0, CHD 0x184564EE0 nbase=5 (single inheritance).
// No standalone ctor -- inlined in pack ctor 0x1809F5960 at pack+0x5D8 (reuses Follow's ctor
// 0x18116C74C, then overwrites the vtable). Dtor 0x18330A834 (ICF twin of Follow's dtor; still
// restores the FOLLOW vtable before chaining into C_ActivityObjective's dtor -- expected MSVC
// deleting-dtor behavior, not a bug). Pack embed C_DogObjectivePack+0x5D8.
//
// On-foot "stay at the master's heel" objective. Tick runs C_FollowDogObjective::Tick first
// (repath / gait / far-snap), then tracks a tighter GetFollowDistance radius (2.0m unmounted /
// 3.5m mounted) around the master; once continuously in-radius past s_FollowHeelTimeout it hands
// off to C_FollowRiderDogObjective via FindByType(pack, FollowRider) + planner Enqueue and
// completes itself with code 1. ShouldRestartIfMasterMoving is disabled here (Heel does not
// restart just because the master is moving -- only the radius/timeout state machine drives it).

namespace wh::xgenaimodule::activitysystem {

class C_FollowHeelDogObjective : public C_FollowDogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FollowHeelDogObjective;

    bool  CanStart() override;                                        // [5]  0x182098520  !m_bound && C_FollowDogObjective::CanStart
    void  BeginWork() override;                                         // [8]  0x18330C72C  m_inRadius = false, then parent BeginWork
    void  Tick() override;                                               // [10] 0x18330E04C  parent Tick, then radius tracking / FollowRider handoff -- see class comment
    void  unk_11() override;                                             // [11] 0x18330D020  parent unk_11 (Follow teardown), then m_inRadius = false
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override;    // [12] 0x18330AC7C  bound+inRadius: lerp by elapsed time vs s_FollowHeelTimeout; else FAR=40/CLOSE=0
    E_DogObjective::Type GetType() const override;                    // [17] 0x181A78ED0  return 5 (FollowHeel)
    float GetFollowDistance() const override;                          // [19] 0x18330B988  s_FollowHeelRadiusWhenMounted (3.5) if mounted else s_FollowHeelRadius (2.0)
    float GetDynamicLeadFactor() const override;                        // [20] 0x181AA6AC0  s_FollowHeelDynamicOffset, default 0.3
    float GetStaticLeadFactor() const override;                         // [21] 0x181AA6AD0  s_FollowHeelStaticOffset, default -0.5
    bool  ShouldRestartIfMasterMoving() const override;                  // [22] 0x180838AE0  return false
    void  RestartFollow() override;                                       // [23] 0x18330B428  stop in-flight move via activity-context slot 0 (+0x150); does NOT complete (unlike parent)
    void  ApplyFollowContext() override;                                   // [24] 0x18330EA90  hub wiggle channel 3 = 2, sniffing channel 0 = 0 (parent writes sniffing = 2)

    CTimeValue  m_inRadiusTime;  // +0xB0  stamped from S_GameContext+0x1A8+0x50 clock on radius entry
    bool        m_inRadius;      // +0xB8
    uint8_t     _padB9[7];       // +0xB9
};
static_assert(sizeof(C_FollowHeelDogObjective) == 0xC0, "C_FollowHeelDogObjective must be 0xC0");
static_assert(offsetof(C_FollowHeelDogObjective, m_inRadiusTime) == 0xB0, "m_inRadiusTime at +0xB0");
static_assert(offsetof(C_FollowHeelDogObjective, m_inRadius) == 0xB8, "m_inRadius at +0xB8");

// GetFollowDistance [19]'s mounted test walks GetMaster()->vf+0xA8()->C_Actor::m_pActorModel(+0x990)
// ->vf[6](); compared to byte value 2. GetMaster()'s own null-check is proven -- the two chained
// derefs past it are not. m_inRadiusTime's clock pointee (S_GameContext+0x1A8) is not yet in
// S_GameContext.h (falls inside its current _pad188); whether +0x50 there is milliseconds or a
// CTimeValue changes the effective timeout by 100x -- UNVERIFIED, flagged in the dossier.

}  // namespace wh::xgenaimodule::activitysystem
