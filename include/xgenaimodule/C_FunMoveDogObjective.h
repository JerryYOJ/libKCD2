#pragma once
#include "C_FunOnTargetBaseDogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_FunMoveDogObjective : C_FunOnTargetBaseDogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0x128. 29 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_FunMoveDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183D16FA0, COL 0x1840DD020 offset 0, CHD 0x1845647D8 nbase=5 (single inheritance).
// ctor 0x1819D2EF8(this, I_DogObjectiveContext*), dtor 0x18330A8B4.
// Pack embed C_DogObjectivePack+0xE60.
//
// Idle wander. Does NOT consume a request position (UsesRequestTarget overridden
// false); scoring/start gated on unk_13 (master location != Undefined). OnArrived
// Completes success directly (the move itself IS the work) -- no on-site anim,
// no chain into another objective. Terminal leaf of the FunOnTarget family.

namespace wh::xgenaimodule::activitysystem {

class C_FunMoveDogObjective : public C_FunOnTargetBaseDogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FunMoveDogObjective;

    bool  unk_13() override;                          // [13] 0x180627BB0  hub+0x290 C_ModelEnumProperty<E_DogMasterLocationState> != Undefined. Shared logic w/ Dig; ToString 0x1833049F0: 0 Undefined / 1 Real / 2 LastValidPosition
    E_DogObjective::Type GetType() const override;    // [17] 0x181AA6AE0  return 0xF (FunMove)
    S_ObjectiveScore* ComputePointScore(S_ObjectiveScore* out) override;  // [19] 0x180624E10  see .cpp-level notes below
    uint32_t GetActionCode() const override;            // [21] 0x181A72470  return 1  (parent default 3, Chase 8; enum UNVERIFIED)
    float GetFailCooldown() const override;             // [23] 0x181AA6A90  FunMoveMinInterval cvar (dword_18492F328, default 20.0f). Arm formula is now+r+U[0,r/2) = now+r*[1.0,1.5), NOT now+r*[0.5,1.5)
    bool  UsesRequestTarget() const override;            // [24] 0x180838AE0  return 0
    S_DogPoint* SelectDogPoint() override;               // [26] 0x18062664C  nav-query pick near master (FunMoveMaxRange/MinDistance); writes m_pickedPoint.Position + m_pickDistance
    void  OnArrived() override;                          // [27] 0x18330EAEC  arm fail-cooldown from [23] then Complete(1) success -- no on-site action

    S_DogPoint m_pickedPoint;   // +0xE8  sizeof 0x38. Second S_DogPoint embed (parent's +0x88 embed is unused: UsesRequestTarget false)
    float      m_pickDistance;  // +0x120 written only by SelectDogPoint on success; ctor does NOT initialize it -- reads before a successful pick are undefined
    uint8_t    _pad124[4];
};
static_assert(sizeof(C_FunMoveDogObjective) == 0x128, "C_FunMoveDogObjective must be 0x128");
static_assert(offsetof(C_FunMoveDogObjective, m_pickedPoint) == 0xE8, "m_pickedPoint at +0xE8");
static_assert(offsetof(C_FunMoveDogObjective, m_pickDistance) == 0x120, "m_pickDistance at +0x120");

// ComputePointScore [19] 0x180624E10: hub+0x238 velocity len2 <= 0.0075 => "still". If master
// location==Real and a front-point probe (0x180625604, set UNVERIFIED) says the picked dest is
// NOT behind master: re-pick via [26]. Else if dest is behind master: score=20.0 flat, band=0.
// If m_bound: yielding extra when (!still && dist2(master,NPC)>FunMoveYieldingMasterDistance^2)
// OR (m_pickDistance*0.5)^2 > dist2(NPC,dest). Score = 10.0 (still) or dword_1854D7398 (moving,
// UNVERIFIED runtime value, .data unloaded) -- packs the yielding bool into S_ObjectiveScore's
// m_band HIGH byte (out+5), not a separate field.
// SelectDogPoint [26] sample-origin quirk: for master location==LastValidPosition, the computed
// forward/behind offset is discarded -- origin is hub position ONLY (no velocity term either).

}  // namespace wh::xgenaimodule::activitysystem
