#pragma once
#include <memory>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "C_DogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_RunawayDogObjective : C_DogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0xB0. 19 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_RunawayDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183B1F490, COL 0x1840DD1D8 offset 0, CHD 0x184564E20 nbase=4 (single inheritance).
// ctor 0x18116C8F4(this, I_DogObjectiveContext*), dtor body 0x18116C884.
// Pack embed C_DogObjectivePack+0xAA8. E_DogObjective::Runaway = 11 (0xB).
//
// Leaves the player's side and paths away once the soul derived-stat Obe (45) becomes non-zero,
// while installing an empty C_RunawayStrategy (I_SkirmishTargetingStrategy whose two queries both
// return false) so the dog is not used as a skirmish targeting participant. Accept is inherited
// false -- the planner starts this purely by GetScore/ComputeScore, never via a request. FSM:
// 0 idle -> 1 hold-near-player -> 2 armed (waiting for Obe != 0) -> 3 fleeing.

namespace wh::xgenaimodule::activitysystem {

class C_RunawayStrategy;      // I_SkirmishTargetingStrategy leaf; no RE header yet (skirmish subsystem out of campaign scope)
class C_SkirmishEventHelper;  // rpgmodule leaf; no RE header yet

class C_RunawayDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_RunawayDogObjective;

    void  BeginWork() override;                                          // [8]  0x180392F30  hook wait-cb, alloc C_SkirmishEventHelper(type 2) around GetNPC()->vf+0xE0(), hold-or-arm by planner gate
    void  Tick() override;                                                 // [10] 0x180393838  FSM 1/2/3 -- see class comment
    void  unk_11() override;                                                // [11] 0x180393294  StopWork: unhook everything, clear NPC bit 2, reset FSM/hub flags
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override;        // [12] 0x181302990  GetNPC()->vf+0xE0()->vf+0x2C8(E_DerivedStat::Obe); 90.0/band1 if ==0 or m_bound, else -1.0
    bool  unk_13() override;                                                // [13] 0x18094E394  thunk: GetMaster() && master->vf+0x1B0(); shared impl with C_FetchDogObjective
    bool  unk_14() override;                                                 // [14] 0x18041A6A0  return true (parent returns false)
    void  Complete() override;                                              // [15] 0x1803931F0  phase-advance override; does NOT call the shared Complete helper (unlike parent)
    E_DogObjective::Type GetType() const override;                        // [17] 0x181A86DC0  return 0xB (Runaway)

    uint8_t     m_fsm;             // +0x78  0 idle, 1 hold-near-player, 2 armed, 3 fleeing
    uint8_t     _pad79[3];         // +0x79
    Vec3        m_moveDest;        // +0x7C
    Vec3        m_holdPos;         // +0x88
    bool        m_npcFlag2;        // +0x94  mirrors GetNPC()->vf+95(value,2) (C_NPC bitset bit 2); name INFERRED
    bool        m_pathPending;     // +0x95  guards repath while a move submit is in flight
    bool        m_holdNeedsUpdate; // +0x96
    bool        m_holdJustEntered; // +0x97
    std::shared_ptr<C_RunawayStrategy> m_strategy;        // +0x98  empty targeting-strategy leaf registered with the skirmish system
    C_SkirmishEventHelper*             m_skirmishHelper;  // +0xA8  owned via std::unique_ptr semantics at runtime (steal-assign / reset with default deleter); kept raw here, no RE header yet
};
static_assert(sizeof(C_RunawayDogObjective) == 0xB0, "C_RunawayDogObjective must be 0xB0");
static_assert(offsetof(C_RunawayDogObjective, m_moveDest) == 0x7C, "m_moveDest at +0x7C");
static_assert(offsetof(C_RunawayDogObjective, m_strategy) == 0x98, "m_strategy at +0x98");
static_assert(offsetof(C_RunawayDogObjective, m_skirmishHelper) == 0xA8, "m_skirmishHelper at +0xA8");

// Accept/Apply/CanStart stay inherited (Accept always false -- selection is score-only). GetScore's
// gate ([13] && [14]) is hard-true here since [14] is overridden to true, so ComputeScore always
// runs. Complete [15]'s extra register content some decompilations show as a second parameter is
// UNPROVEN as a real ABI arg (the only virtual caller passes none); declared here matching the
// base's void Complete() exactly. Tick's fsm==3 branch checks the shared planner-busy gate
// (I_ActivityObjectiveContext[0]()+0x118) before threat-clear/flee logic.

}  // namespace wh::xgenaimodule::activitysystem
