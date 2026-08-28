#pragma once
#include "C_FunOnTargetBaseDogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_MarkDogObjective : C_FunOnTargetBaseDogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0xE8. 29 slots, 0 new. Adds ZERO own members.
// -----------------------------------------------
// RTTI .?AVC_MarkDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183D258A8, COL 0x1840DD110 offset 0, CHD 0x184564E98 nbase=5 (single inheritance).
// No standalone ctor -- inlined in pack ctor 0x1809F5960 at pack+0x18: parent ctor
// 0x18062646C(this,ctx) then stamp this vtable. Dtor 0x18330A974 (ICF-shared with parent).
// Pack embed C_DogObjectivePack+0x18.
//
// Territory-mark activity. Accept requires S_DogObjectiveRequest::m_hasPosition
// (UsesRequestTarget inherited true); on request-miss, FindPoint queries
// C_DogPointManager for a nearby S_DogPoint (MarkMinInterval-gated). On arrival,
// PerformAtPoint plays a dog-expansion mark action, then chains FunMove (15) via
// the shared arrive-followup helper.

namespace wh::xgenaimodule::activitysystem {

class C_MarkDogObjective : public C_FunOnTargetBaseDogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_MarkDogObjective;

    E_DogObjective::Type GetType() const override;  // [17] 0x18041A6A0  return 1 (Mark). ICF-shared return-1 stub
    bool  TryOccupyTarget() override;                // [20] 0x18330F118  C_DogPointManager occupancy stamp, type byte 1; always returns 1
    float GetScoreRadius() const override;           // [22] 0x180395D90  return 10.0f
    float GetFailCooldown() const override;          // [23] 0x181AA6AA0  MarkMinInterval cvar (dword_18492F368, default 60.0f)
    S_DogPoint* SelectDogPoint() override;            // [26] 0x1806240C4  query C_DogPointManager near dog facing +-45 deg jitter or NPC pos
    void  OnArrived() override;                       // [27] 0x18330EB78  dog-expansion mark action at the point (GetDogExpansion vf+0x40 -> vf+0x38)
    Vec3  GetApproachOffset() const override;          // [28] 0x18330B8EC  sret {fabs(x),0,0} from expansion vf+0x40->vf+0xF0
};
static_assert(sizeof(C_MarkDogObjective) == 0xE8, "C_MarkDogObjective must be 0xE8 (no own members)");

// ComputePointScore [19] (inherited): band 0 always -- 0x180395CCC(3)=20.0 is the near lerp
// endpoint, not the band; dx leftover=0 is stored as m_band. GetScoreRadius [22]=10.0 bounds it.
// Arrive-followup (shared helper 0x18176E148): arms MarkMinInterval cooldown, FindByType(FunMove=15),
// Accept+enqueue if possible, then Complete(1) regardless (both hit/miss succeed this objective).

}  // namespace wh::xgenaimodule::activitysystem
