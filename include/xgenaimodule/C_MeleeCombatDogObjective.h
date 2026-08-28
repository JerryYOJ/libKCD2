#pragma once
#include <memory>
#include "../framework/WUID.h"
#include "C_DogObjective.h"
#include "C_NPCProperty.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_MeleeCombatDogObjective : C_DogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0xF0. 19 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_MeleeCombatDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183A82278, COL 0x1840DD138 offset 0, CHD 0x184564E68 nbase=4 (single inheritance).
// Dedicated ctor 0x180BCA464(this, I_DogObjectiveContext*), deleting dtor 0x18330A9E8.
// Pack embed C_DogObjectivePack+0x920. E_DogObjective::MeleeCombat = 8.
//
// Player-commanded or auto-scored dog melee assist. m_targetNpc (+0x88) is a real C_NPCProperty
// member (composition, not MI -- absent from this class's own CHD); it auto-binds/unbinds the
// live NPC target and is what combat callbacks actually read, distinct from the WUID at m_target
// which only latches the initial Accept/Apply/auto-pick target. Combat is entirely callback-driven
// (Tick is a nullsub): BeginWork hooks the NPC's combat-state and action-end signals plus a
// master<->target pair-combat event; any of the three routes into the shared Complete helper.
// PickStrategy selects m_strategy (commanded) vs m_aggressiveStrategy (auto-pick) by m_fromRequest.

namespace wh::xgenaimodule::activitysystem {

class C_MeleeCombatStrategy;            // I_SkirmishTargetingStrategy leaf; no RE header yet (skirmish subsystem out of campaign scope)
class C_MeleeCombatAggressiveStrategy;  // : C_MeleeCombatStrategy; no RE header yet

class C_MeleeCombatDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_MeleeCombatDogObjective;

    bool  Accept(const S_DogObjectiveRequest*) override;             // [6]  0x18072A678  m_hasTarget && target != GetNPC()'s own WUID && C_SkirmishManager accepts under m_strategy
    void  Apply(const S_DogObjectiveRequest*) override;                // [7]  0x18330D7AC  m_target = request->m_target, m_fromRequest = true, play VO "dog_comp_combat_attack_command"
    void  BeginWork() override;                                          // [8]  0x18330C864  re-run skirmish gate; on pass hook combat-state/action-end/pair-combat signals, start combat session
    void  unk_11() override;                                              // [11] 0x18330D1D8  StopWork: inverse of BeginWork -- unhook all three signals, clear m_targetNpc, SetCombatMode(0)
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override;      // [12] 0x18330B054  bound: fixed band-6 score; else auto-pick via skirmish+aggressive strategy, distance-lerp band6->band2
    E_DogObjective::Type GetType() const override;                     // [17] 0x181A8AD10  return 8 (MeleeCombat)

    wh::framework::WUID m_target;           // +0x78  latched request/auto-pick target; invalid sentinel qword_18533A2A8; NOT the live combat target (see m_targetNpc)
    bool                  m_fromRequest;      // +0x80  true = player-commanded (uses m_strategy); false = auto-picked (uses m_aggressiveStrategy)
    uint8_t                _pad81[7];         // +0x81
    C_NPCProperty            m_targetNpc;      // +0x88  sizeof 0x40; live combat target, filled by the NPC's current-target-changed callback
    bool                      m_combatStateHooked; // +0xC8
    bool                       m_pairCombatHooked;  // +0xC9
    bool                        m_actionHooked;       // +0xCA
    uint8_t                      m_combatMode;          // +0xCB  values 0/1/2 (source enum name UNVERIFIED); sole writer SetCombatMode
    uint8_t                       _padCC[4];             // +0xCC
    std::shared_ptr<C_MeleeCombatStrategy>           m_strategy;           // +0xD0  commanded-target skirmish filter
    std::shared_ptr<C_MeleeCombatAggressiveStrategy> m_aggressiveStrategy; // +0xE0  auto-pick skirmish filter
};
static_assert(sizeof(C_MeleeCombatDogObjective) == 0xF0, "C_MeleeCombatDogObjective must be 0xF0");
static_assert(offsetof(C_MeleeCombatDogObjective, m_targetNpc) == 0x88, "m_targetNpc at +0x88");
static_assert(offsetof(C_MeleeCombatDogObjective, m_combatMode) == 0xCB, "m_combatMode at +0xCB");
static_assert(offsetof(C_MeleeCombatDogObjective, m_strategy) == 0xD0, "m_strategy at +0xD0");
static_assert(offsetof(C_MeleeCombatDogObjective, m_aggressiveStrategy) == 0xE0, "m_aggressiveStrategy at +0xE0");

// ComputeScore always writes S_ObjectiveScore::m_band = 0 on every path -- "band-6"/"band-2" in
// the class comment are 0x180395CCC() score-TABLE KEYS (6->50.0, 2->10.0, 0->-1.0), not the
// stored band field; do not set m_band to 6/2 when reimplementing. GetType [17]'s stub is
// ICF-shared with unrelated vtables; binding is this class's own vtable slot. C_SkirmishManager,
// I_SkirmishTargetingStrategy, and both strategy leaves are RTTI-identified in the dossier but
// deliberately not composed into headers this pass (separate skirmish subsystem, same scoping
// rationale as C_DogCompanionContext).

}  // namespace wh::xgenaimodule::activitysystem
