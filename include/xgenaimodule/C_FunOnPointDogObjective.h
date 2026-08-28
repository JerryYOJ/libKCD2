#pragma once
#include "C_FunOnTargetBaseDogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_FunOnPointDogObjective : C_FunOnTargetBaseDogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0xF0. 29 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_FunOnPointDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183D25998, COL 0x1840DD048 offset 0, CHD 0x184564EB0 nbase=5 (single inheritance).
// No standalone ctor -- inlined in pack ctor 0x1809F5960 at pack+0x190: parent ctor
// 0x18062646C(this,ctx), *(this+0xE8)=2 (m_action=sniff default), stamp this vtable.
// Dtor 0x18330A8F4. Pack embed C_DogObjectivePack+0x190.
//
// "Do a fun action on a world point" leaf -- drink or sniff at a C_DogPointManager POI.
// Requires a request position (UsesRequestTarget inherited true). ComputeScore
// periodically (FunOnTargetPointUpdateTimeout) re-picks via AcquirePoint, which
// translates the picked S_DogPoint::Type into m_action (0=drink, 2=sniff; 1 is a
// cooldown-veto value never actually stored; 3/4 fall through to Complete(0) in
// PlayPointAnim -- no anim wired for WaterTub/MerchantCounter point kinds).

namespace wh::xgenaimodule::activitysystem {

class C_FunOnPointDogObjective : public C_FunOnTargetBaseDogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FunOnPointDogObjective;

    E_DogObjective::Type GetType() const override;  // [17] 0x181AA6AF0  return 0x11 (FunOnPoint)
    bool  TryOccupyTarget() override;                // [20] 0x1817435F0  stamps C_DogPointManager+0x1A0 (NPC-keyed) and +0x1E0 (point-keyed); always returns 1
    float GetScoreRadius() const override;           // [22] 0x180395D80  FunOnPointMaxDistance cvar (dword_18492F340)
    float GetStopDistance() const override;           // [25] 0x1819E0F20  m_action==0 -> DrinkStopDistance; ==2 -> SniffStopDistance; else 1.0f. DOES feed the mover (xmm2 -> 0x1809F4AB0)
    S_DogPoint* SelectDogPoint() override;            // [26] 0x180623EE8  AcquirePoint: queries C_DogPointManager, translates point Type -> m_action; cooldown-veto (Type==1 miss) returns null w/o writing m_action
    void  OnArrived() override;                       // [27] 0x180396228  PlayPointAnim: expansion[10] "drink" (m_action==0) or expansion[20] "pointSniffing" (m_action==2); else Complete(0)

    uint8_t m_action;   // +0xE8  0=drink, 2=sniff (pack-ctor default). 1 never stored (AcquirePoint veto), 3/4 = no anim
    uint8_t _padE9[7];
};
static_assert(sizeof(C_FunOnPointDogObjective) == 0xF0, "C_FunOnPointDogObjective must be 0xF0");
static_assert(offsetof(C_FunOnPointDogObjective, m_action) == 0xE8, "m_action at +0xE8");

// ComputeScore [12] (inherited) +0xC8 gate: 0x180731070 returns READY on sentinel-or-expired;
// fail branch is the NOT-ready case (dossier's first-pass polarity was inverted, corrected here).
// GetFailCooldown [23] stays inherited default (0.0f) -- NOT unused: 0x18176E1DC arms +0xC8 from
// it on both the no-point BeginWork failure and the shared arrive-followup path.

}  // namespace wh::xgenaimodule::activitysystem
