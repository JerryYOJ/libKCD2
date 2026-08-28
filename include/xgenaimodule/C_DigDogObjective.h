#pragma once
#include "C_FunOnTargetBaseDogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_DigDogObjective : C_FunOnTargetBaseDogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0x120. 29 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_DigDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183D17090, COL 0x1840DD8B8 offset 0, CHD 0x184562A48 nbase=5 (single inheritance).
// ctor 0x1819D2F60(this, I_DogObjectiveContext*), dtor 0x1832FFEE0.
// Pack embed C_DogObjectivePack+0x280.
//
// Dig activity. Does NOT consume a request position (UsesRequestTarget overridden
// false) -- ComputeScore [12] never calls SelectDogPoint on this leaf (vf+0xC0
// false short-circuits straight to [19]); the pick instead happens lazily in
// inherited BeginWork via the null-check helper. On success, chains FunMove (15)
// via the shared arrive-followup helper.

namespace wh::xgenaimodule::activitysystem {

class C_DigDogObjective : public C_FunOnTargetBaseDogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DigDogObjective;

    bool  unk_13() override;                         // [13] 0x180627BB0  hub+0x290 C_ModelEnumProperty<E_DogMasterLocationState> != Undefined. Source name/enumerators UNVERIFIED; shared logic w/ FunMove
    E_DogObjective::Type GetType() const override;   // [17] 0x181A78EB0  return 3 (Dig)
    S_ObjectiveScore* ComputePointScore(S_ObjectiveScore* out) override; // [19] 0x180395B34  master-velocity score: len2(hub+0x238) vs DigMaxMasterVelocity^2, lerp band-2(10.0)->dword_1854D71E0
    float GetFailCooldown() const override;           // [23] 0x18176E2B0  DigMinInterval cvar (dword_18492F1F4, default 60.0f)
    bool  UsesRequestTarget() const override;          // [24] 0x180838AE0  return 0
    S_DogPoint* SelectDogPoint() override;             // [26] 0x180623BDC  origin from master pose (DigMaxRange offset, +-45deg yaw) or NPC pos; query kind byte 5 (not an E_DogPointType value); writes m_pickedPoint.Position only
    void  OnArrived() override;                        // [27] 0x1803961C4  StartDigAction: dog-expansion (type 2) vf[9] shared_ptr install onto activity-context action slot; fragment CRC "dig"

    wh::xgenaimodule::S_DogPoint m_pickedPoint;  // +0xE8  sizeof 0x38. [26] writes Position only; Direction/Type/Aux/Guid stay ctor defaults
};
static_assert(sizeof(C_DigDogObjective) == 0x120, "C_DigDogObjective must be 0x120");
static_assert(offsetof(C_DigDogObjective, m_pickedPoint) == 0xE8, "m_pickedPoint at +0xE8");

// GetStopDistance [25] stays inherited default (0.0f) -- return value DOES feed the mover
// (movaps xmm2,xmm0 -> 0x1809F4AB0), not a discarded no-op.
// CanStart (inherited 0x182095E20) does not reduce to just [13]: it is [6]&&0x180730F54, and
// 0x180730F54 still requires ([14] || !actor-busy) even when [13] passes.

}  // namespace wh::xgenaimodule::activitysystem
