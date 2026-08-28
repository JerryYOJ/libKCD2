#pragma once
#include "C_FunOnTargetBaseDogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_ChaseDogObjective : C_FunOnTargetBaseDogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0x130. 29 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_ChaseDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183C74CC8, COL 0x1840DD890 offset 0, CHD 0x184562B98 nbase=5 (single inheritance).
// ctor 0x1819C06E8(this, I_DogObjectiveContext*), dtor 0x1832FFEA0.
// Pack embed C_DogObjectivePack+0x1090.
//
// Run at a target boid (C_NPC via C_NPCManager), bark at the point, chain FunMove (15).
// Target is identified by EntityId, NOT the parent's S_DogPoint position-request path --
// Accept/Apply are fully overridden to consume S_DogObjectiveRequest::m_target (a WUID),
// not m_hasPosition. UsesRequestTarget stays inherited true (1), but because Accept/Apply
// are overridden it never drives the parent's position-copy behavior. The ONE leaf in this
// family whose own Tick is live (not a nullsub) -- it polls a bark-dwell CTimeValue.

namespace wh::xgenaimodule::activitysystem {

class C_ChaseDogObjective : public C_FunOnTargetBaseDogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ChaseDogObjective;

    bool  Accept(const S_DogObjectiveRequest*) override; // [6]  0x183300438  request->m_hasTarget (+0x2A) && C_NPCManager WUID-lookup(request->m_target) != null
    void  Apply(const S_DogObjectiveRequest*) override;  // [7]  0x1833028E4  WUID-lookup -> C_NPC -> m_puppet -> IEntity::GetId() -> m_targetEntityId
    void  BeginWork() override;                           // [8]  0x183302008  parent BeginWork, then hub+0x90 idx2=3 and hub+0x48 idx7=3
    void  Tick() override;                                 // [10] 0x183302E48  id==0 -> Complete(0); else bark-timer expiry -> reset, chain FunMove/complete
    void  unk_11() override;                               // [11] 0x1833024D8  OnStop: parent teardown + hub channels 2/7 cleared, id=0, bark timer reset
    E_DogObjective::Type GetType() const override;         // [17] 0x181AA6890  return 0x12 (Chase)
    S_ObjectiveScore* ComputePointScore(S_ObjectiveScore* out) override;  // [19] 0x1833009F4  dog-master distance gate (ChaseMasterDogDistance), then target-distance lerp
    uint32_t GetActionCode() const override;                 // [21] 0x181A74260  return 8  (enum UNVERIFIED)
    float GetFailCooldown() const override;                   // [23] 0x181AA6860  ChaseActionTimeout cvar (dword_18492F1EC)
    S_DogPoint* SelectDogPoint() override;                    // [26] 0x180728E18  auto-pick target EntityId if unset, then C_NPCManager EntityId-lookup -> m_chasePoint.Position
    void  OnArrived() override;                               // [27] 0x183303E0C  hub+0x90 idx2=4 (bark), arm m_barkTimer from ChaseBarkingTimeout (no jitter)

    uint32_t    m_targetEntityId;  // +0xE8  Cry EntityId (typedef unsigned int), 0 = none. Set by Apply or SelectDogPoint auto-pick; cleared on lookup-miss/OnStop
    uint8_t     _padEC[4];
    S_DogPoint  m_chasePoint;      // +0xF0  sizeof 0x38. Direction/Type/Guid stay ctor defaults -- only Position is ever written
    CTimeValue  m_barkTimer;       // +0x128 sentinel -100000; armed by OnArrived, polled by Tick
};
static_assert(sizeof(C_ChaseDogObjective) == 0x130, "C_ChaseDogObjective must be 0x130");
static_assert(offsetof(C_ChaseDogObjective, m_targetEntityId) == 0xE8, "m_targetEntityId at +0xE8");
static_assert(offsetof(C_ChaseDogObjective, m_chasePoint) == 0xF0, "m_chasePoint at +0xF0");
static_assert(offsetof(C_ChaseDogObjective, m_barkTimer) == 0x128, "m_barkTimer at +0x128");

// UsesRequestTarget [24] stays inherited default (true) but is INERT for Chase: Accept/Apply are
// fully overridden and never touch m_pTargetPoint/m_requestPoint the way the base class's own
// Accept/Apply would. Inherited BeginWork [8]'s null-m_pTargetPoint early-out only exists on the
// UsesRequestTarget==false (FunMove/Dig) path -- with [24] true Chase instead dereferences
// m_pTargetPoint+0x14 directly; a null pointer here is a genuine crash path, not a soft-fail.
// GetActionCode [21]'s stub 0x181A74260 is ICF-shared across many unrelated vtables; only this
// class's vtable slot binds it to Chase.

}  // namespace wh::xgenaimodule::activitysystem
