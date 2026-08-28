#pragma once
#include "../framework/WUID.h"
#include "C_DogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_FollowRiderDogObjective : C_DogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0x88. 19 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_FollowRiderDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183D16E28, COL 0x1840DCFF8 offset 0, CHD 0x184564E08 nbase=4 (single inheritance).
// No standalone ctor -- inlined in pack ctor 0x1809F5960 at pack+0x698 (calls C_DogObjective's
// ctor 0x1806265D8 directly -- NOT C_FollowDogObjective's ctor, despite the similar name). Dtor
// 0x18330A874. Pack embed C_DogObjectivePack+0x698.
//
// Mounted-heel dog objective: joins the dog into a C_FormationManager formation
// ("dogCompanion_followHeel_horse") behind the master's mount. Accept always true; Apply/Tick are
// no-ops -- BeginWork does all the work (formation lookup/create, join request, controller hook).
// ComputeScore yields when the dog exceeds MaxRiderFollowDistance from the master or a formation
// conflict is detected; join failure or formation release completes(0) via OnFormationReleased.

namespace wh::xgenaimodule::activitysystem {

class C_FollowRiderDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FollowRiderDogObjective;

    bool  Accept(const S_DogObjectiveRequest*) override;             // [6]  0x18041A6A0  return true; request unused
    void  BeginWork() override;                                        // [8]  0x1807D3418  formation lookup/create/join, hook controller + release callback
    void  unk_11() override;                                            // [11] 0x1807D3220  StopWork: unhook, leave formation, C_FormationManager destroy
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override;    // [12] 0x1807D382C  fail if formation conflict or distance > MaxRiderFollowDistance
    E_DogObjective::Type GetType() const override;                   // [17] 0x181A78EC0  return 6 (FollowRider)

    wh::framework::WUID m_formation;          // +0x78  tag Formation(0x11); invalid sentinel qword_18533A2A8
    bool                  m_controllerHooked;   // +0x80
    uint8_t                _pad81[7];           // +0x81
};
static_assert(sizeof(C_FollowRiderDogObjective) == 0x88, "C_FollowRiderDogObjective must be 0x88");
static_assert(offsetof(C_FollowRiderDogObjective, m_formation) == 0x78, "m_formation at +0x78");
static_assert(offsetof(C_FollowRiderDogObjective, m_controllerHooked) == 0x80, "m_controllerHooked at +0x80");

// BeginWork's join-request dword at request+0x20 stays 0 for this leaf (the request ctor's
// default write of 2 there is explicitly overwritten before the join call) -- do not assume 2.
// The activity-context follow-controller (I_ActivityObjectiveContext[1]()+0x190) is
// wh::xgenaimodule::activitysystem::C_FollowActivityComponent (MI: second vtable at +0x28 for
// I_ControlActivityComponentHandler) -- no RE header yet for that class; touched here only via
// vcalls, not as a typed member. GetMaster()'s exact derived type (player vs horse AI object) is
// UNVERIFIED beyond the C_AIObject spine (WUID at +8, vf[2] world position).

}  // namespace wh::xgenaimodule::activitysystem
