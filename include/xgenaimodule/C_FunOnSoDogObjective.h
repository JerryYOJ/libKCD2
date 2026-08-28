#pragma once
#include "C_FunOnTargetBaseDogObjective.h"
#include "I_BehaviorReservationHost.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_FunOnSoDogObjective
//   : public C_FunOnTargetBaseDogObjective, public wh::xgenaimodule::I_BehaviorReservationHost
// (KCD2 WHGame.dll 1.5.6). sizeof 0x108. THE ONE GENUINE MI LEAF in this pack.
// -----------------------------------------------
// RTTI .?AVC_FunOnSoDogObjective@activitysystem@xgenaimodule@wh@@
// Primary vtable 0x183D15430 (29 slots, 0 new vs parent), COL 0x1840DD070 offset 0.
// Secondary vtable 0x183D15418 (I_BehaviorReservationHost, 2 slots), COL 0x1840DD098
// offset 0xE8=232 -- CHD attr=1 (true MI), nbase=6, last base mdisp=0xE8.
// ctor 0x1819C5D4C(this, I_DogObjectiveContext*), dtor 0x18330A934.
// Pack embed C_DogObjectivePack+0xF88.
//
// "Play on a smart-object dog-point" -- extends the go-to-point base with SO
// reservation (I_BehaviorReservationHost lets the reservation system cancel this
// objective through the +0xE8 subobject pointer) and plays one of two expansion
// actions on arrival. SelectDogPoint filters to Guid!=0 (SO-linked) points only;
// the picked point's Type is remapped (sub_180624374, NOT a verbatim copy) into
// m_behaviorType. OnArrived only builds an action for m_behaviorType 3
// (CounterSniffing) or 4 (WaterTubDrinking) -- 0/1/2 fail-Complete on arrival even
// if occupy succeeded.

namespace wh::xgenaimodule::activitysystem {

class C_FunOnSoDogObjective
    : public C_FunOnTargetBaseDogObjective,
      public wh::xgenaimodule::I_BehaviorReservationHost {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FunOnSoDogObjective;

    void  unk_11() override;                          // [11] 0x18330D03C  OnStop: parent OnStop, then if m_pSmartObject: unreserve (NPC WUID, m_behaviorId, m_reservationToken), clear point/SO/ids
    E_DogObjective::Type GetType() const override;    // [17] 0x181AA6B00  return 0x10 (FunOnSo)
    void  unk_18() override;                           // [18] 0x18330B800  GetTargetRef: if phase==2 && m_behaviorType==3: {tag=2, WUID from Guid}; else {tag=0, invalid WUID}
    bool  TryOccupyTarget() override;                   // [20] 0x18330EFEC  resolve point Guid->WUID->C_SmartObject via FindByWuid; reserve behavior named by E_DogPointType stringer; store SO/id/token
    float GetScoreRadius() const override;               // [22] 0x180395D70  return dword_18492F358 = 10.0f
    S_DogPoint* SelectDogPoint() override;                // [26] 0x180623FDC  C_DogPointManager query filtered to Guid!=0; remaps picked Type -> m_behaviorType (NOT verbatim)
    void  OnArrived() override;                           // [27] 0x18330EB0C  m_behaviorType==3/4 -> dog-expansion slot [21]/[22] action, started on (I_ActivityObjectiveContext[1] result)+0x18; else Complete(0)
    Vec3  GetApproachOffset() const override;              // [28] 0x18330B84C  sret from same action factory's expansion vf+0xF0 (slot 30) if action built; else {0,0,0}

    // wh::xgenaimodule::I_BehaviorReservationHost (secondary vtable at +0xE8, 2 slots, no virtual dtor)
    void unk_00() override;  // [0] 0x18330AC70  this-adjustor (this-0xE8) -> C_ActivityObjective::StopIfRunning body 0x1809F4E08 (NOT the full FunOnTargetBase override chain)
    bool unk_01() override;  // [1] 0x180838AE0  return false

    E_DogPointType::Type m_behaviorType;    // +0xF0  NOT ctor-initialized -- only SelectDogPoint writes it. A request-only Start that never scored can occupy with a garbage byte
    uint8_t               _padF1[7];
    void*                 m_pSmartObject;   // +0xF8  wh::xgenaimodule::C_SmartObject*. 0 = none
    uint32_t              m_behaviorId;     // +0x100 sentinel -1 (dword_18492F370, loaded). XGenPublic::I_SmartEntity behavior id
    uint32_t              m_reservationToken; // +0x104 sentinel 0xFFFFFFFF. Reservation handle from the SO reserve call
};
static_assert(sizeof(C_FunOnSoDogObjective) == 0x108, "C_FunOnSoDogObjective must be 0x108");
static_assert(offsetof(C_FunOnSoDogObjective, m_behaviorType) == 0xF0, "m_behaviorType at +0xF0");
static_assert(offsetof(C_FunOnSoDogObjective, m_pSmartObject) == 0xF8, "m_pSmartObject at +0xF8");
static_assert(offsetof(C_FunOnSoDogObjective, m_behaviorId) == 0x100, "m_behaviorId at +0x100");
static_assert(offsetof(C_FunOnSoDogObjective, m_reservationToken) == 0x104, "m_reservationToken at +0x104");

// m_pSmartObject kept as void* (not wh::xgenaimodule::C_SmartObject*) -- that class has no RE
// header yet in this campaign; retype once C_SmartObject is composed.
// m_behaviorType remap table (SelectDogPoint, via sub_180624374, NOT verbatim from S_DogPoint::Type):
//   S_DogPoint::Type 0 Drink -> 0 Drink | 1 Mark -> 1 Mark or 2 TreeSniffing (cooldown-gated,
//   C_DogPointManager+0x1A0 vs 1200.0/600.0s windows) | 2 TreeSniffing -> 4 WaterTubDrinking |
//   3 CounterSniffing -> 3 CounterSniffing | miss -> 2 TreeSniffing (S_DogPoint* also nulled).

}  // namespace wh::xgenaimodule::activitysystem
