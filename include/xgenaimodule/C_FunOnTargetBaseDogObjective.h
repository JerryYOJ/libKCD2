#pragma once
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/TimeValue.h"
#include "C_DogObjective.h"
#include "S_DogPoint.h"
#include "S_ObjectiveScore.h"
#include "S_DogObjectiveRequest.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_FunOnTargetBaseDogObjective : C_DogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0xE8. 29 slots (10 new: [19]..[28]).
// -----------------------------------------------
// RTTI .?AVC_FunOnTargetBaseDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183A42E98, COL 0x1840DD0C0 offset 0, CHD 0x184562A00 nbase=4 (single inheritance).
// ctor 0x18062646C(this, I_DogObjectiveContext*), dtor 0x18330A974 (scalar-deleting,
// implicit override -- all own members are POD/S_DogPoint, no custom cleanup to declare).
// Abstract: GetType [17] stays _purecall (getTypeValue=-1, not a leaf itself);
// SelectDogPoint [26] and OnArrived [27] are new pure virtuals.
//
// NOT multiple inheritance. The vptr this ctor writes at +0x88 is S_DogPoint's own
// COMPLETE-OBJECT table (COL.offset=0), not a subobject/adjustor table -- this class's
// own CHD lists only the plain C_DogObjective->C_ActivityObjective->I_ObjectivePlannerRunnable
// chain, all mdisp=0. S_DogPoint is a composed member (m_requestPoint), proven by:
// sizeof(S_DogPoint)=0x38 exactly tiling +0x88..+0xC0; no this-adjusting thunks on this
// class; dtor does not call a second-base dtor. The one genuine MI leaf in this pack is
// C_FunOnSoDogObjective, whose SECOND base I_BehaviorReservationHost sits at mdisp=0xE8 --
// i.e. strictly *after* this class's own extent, which is further proof +0x88 is not MI.
// Full evidence: KCD2/analysis/dogpack_re/C_FunOnTargetBaseDogObjective.md (+ AUDIT2/AUDIT3).
//
// Leaves derived from this base (pack ctor 0x1809F5960): C_MarkDogObjective (+0x18),
// C_FunOnPointDogObjective (+0x190), C_DigDogObjective (+0x280), C_FunMoveDogObjective
// (+0xE60), C_FunOnSoDogObjective (+0xF88), C_ChaseDogObjective (+0x1090).

namespace wh::xgenaimodule::activitysystem {

class C_FunOnTargetBaseDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FunOnTargetBaseDogObjective;

    void StopIfRunning() override;                 // [4]  0x1809F4A7C  parent body 0x1809F4E08, then m_pTargetPoint=0, both CTimeValues<-sentinel
    bool Accept(const S_DogObjectiveRequest*) override; // [6] 0x18176E1B8  if ![24]: return 1; else return request->m_hasPosition
    void Apply(const S_DogObjectiveRequest*) override;  // [7] 0x18176E0B0  if [24]: copy request pos/dir into m_requestPoint, m_pTargetPoint=&m_requestPoint, m_useRequestPoint=1
    void BeginWork() override;                     // [8]  0x1809F4528  resolve m_worldDest = point.Position + Rotate(Direction,[28]); issue move; [20] occupy; m_phase=1; hook move cb
    void unk_11() override;                         // [11] 0x18175D76C  OnStop: unhook both callbacks, m_pTargetPoint=0, m_phase=0, clear hub flags
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override; // [12] 0x180730FA4  see note below -- m_bound gates re-pick, not just m_reselectTimer
    // [17] GetType remains pure (_purecall 0x181D93E5D) -- not a leaf itself

    virtual S_ObjectiveScore* ComputePointScore(S_ObjectiveScore* out); // [19] 0x180395BD4  dist2(master,point.Position) vs [22]^2; band-20.0 remap via 0x180395C8C
    virtual bool     TryOccupyTarget();             // [20] 0x18041A6A0  default return 1. FunOnSo reserves SO, FunOnPoint notifies C_DogPointManager
    virtual uint32_t GetActionCode() const;         // [21] 0x181A72CF0  default return 3 (enum UNVERIFIED). FunMove=1, Chase=8. Written to activity-hub via 0x1809F594C
    virtual float    GetScoreRadius() const;        // [22] 0x181A730F0  default return 0.0f. [19]'s max-distance bound
    virtual float    GetFailCooldown() const;       // [23] 0x181A730F0  default return 0.0f. 0x18176E1DC arms m_scoreGate from this on select-miss
    virtual bool     UsesRequestTarget() const;     // [24] 0x18041A6A0  default return 1. Gates Accept/Apply/BeginWork/ComputeScore. FunMove+Dig override to return 0 (pick via [26] instead)
    virtual float    GetStopDistance() const;       // [25] 0x181A730F0  default return 0.0f. BeginWork writes to move-req +0x44. FunOnPoint overrides from its point type
    virtual S_DogPoint* SelectDogPoint() = 0;       // [26] pure. ComputeScore / 0x1809F44C8 store result at +0x80
    virtual void     OnArrived() = 0;               // [27] pure. Move-complete cb vcalls this after m_phase=2 (on-site action / reservation)
    virtual Vec3     GetApproachOffset() const;     // [28] 0x1809F44F0  default sret {0,0,0}. BeginWork rotates by point Direction, adds to Position -> m_worldDest

    uint8_t     m_phase;            // +0x78  0 idle / 1 moving / 2 arrived
    uint8_t     _pad79[7];
    S_DogPoint* m_pTargetPoint;     // +0x80  points at m_requestPoint OR a world S_DogPoint from SelectDogPoint
    S_DogPoint  m_requestPoint;     // +0x88  sizeof 0x38, request-driven path copies pos/dir here
    bool        m_useRequestPoint;  // +0xC0  Apply sets 1; select-path (0x1809F44C8, ComputeScore) sets 0
    uint8_t     _padC1[7];
    CTimeValue  m_scoreGate;        // +0xC8  sentinel -100000; ComputeScore ready-gate; fail path arms via [23]
    CTimeValue  m_reselectTimer;    // +0xD0  sentinel -100000; re-pick cadence, rearmed +-0.1s (dword_18492F354 "FunOnTargetPointUpdateTimeout")
    bool        m_arriveCbHooked;   // +0xD8  guards unhook of 0x18176E09C on actor+0x18
    bool        m_moveCbHooked;     // +0xD9  guards unhook of 0x1809F4070 on actor+0x128
    uint8_t     _padDA[2];
    Vec3        m_worldDest;        // +0xDC  BeginWork: Position + Rotate(Direction, GetApproachOffset())
};
static_assert(sizeof(C_FunOnTargetBaseDogObjective) == 0xE8,
              "C_FunOnTargetBaseDogObjective must be 0xE8 (leaves start there)");
static_assert(offsetof(C_FunOnTargetBaseDogObjective, m_requestPoint) == 0x88,
              "S_DogPoint embed at +0x88 -- composition, not a second C++ base");
static_assert(offsetof(C_FunOnTargetBaseDogObjective, m_worldDest) == 0xDC,
              "trailing Vec3 at +0xDC");

// ComputeScore [12] m_bound (+0x69) gating, per adversarial review (not just m_reselectTimer):
//   [24] && m_bound && m_pTargetPoint  -> skip select, score immediately.
//   [24] && !m_bound                   -> may overwrite an existing pointer once m_reselectTimer is ready.
//   ![24]                              -> never call [26]; goes straight to [19] with NO null check on +0x80
//                                         (FunMove/Dig survive this because they override [19]).
//
// Arrive-followup cb (0x18176E148, hardcoded FindByType(pack, 0xF)=FunMove): BOTH the hit and
// miss paths Complete(1) this objective -- miss calls 0x1809F62F4(this,1) directly; hit still
// submits FunMove via 0x180C58ACC *and* Completes(1) this objective (does not merely chain).

}  // namespace wh::xgenaimodule::activitysystem
