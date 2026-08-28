#pragma once
#include "C_PlayerSynchroAnimBaseDogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_PetDogObjective : C_PlayerSynchroAnimBaseDogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0xB8 (adds no own fields). 27 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_PetDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183D25A88, COL 0x1840DD188 offset 0, CHD 0x1845647F0 nbase=5 (single inheritance).
// ctor inlined in pack ctor (parent ctor 0x18192C680 then vtable install; no dedicated ctor).
// Pack embed C_DogObjectivePack+0x1318. E_DogObjective::Pet = 22.
//
// Player-initiated "come here and be petted" objective. No S_DogObjectiveRequest payload
// (Accept/Apply are inherited from the synchro base: always-true / no-op); idle ComputeScore
// is -1.0 (inherited), so the planner never picks this by score -- it is enqueued directly by
// the RTTR-bound method wh::xgenaimodule::activitysystem::PetDog (0x183303548), which submits
// type 0x16 with an empty request via 0x182A01A70. BeginWork enables synchro locomotion, builds
// a "petting" slaved-anim request via [19], and either starts that anim or moves into range;
// this leaf's only addition on top of the synchro base is: after parent BeginWork, if the master
// is the registered player NPC, it fires a player-side cue (enum 9) through the player's Actor.

namespace wh::xgenaimodule::activitysystem {

class C_PetDogObjective : public C_PlayerSynchroAnimBaseDogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PetDogObjective;

    void  BeginWork() override;                                     // [8]  0x18330CCF4  parent BeginWork, then if GetMaster() is the registered player NPC, fire player-side cue enum 9
    void  unk_19() override;                                         // [19] 0x18330B550  GetSynchroAnimRequest: sret shared_ptr<S_ActionSlavedAnimRequestImpl<S_ActionSlavedAnimRequest>> for the "petting" action-type id
    void  unk_20() override;                                         // [20] 0x18330E918  EnableSynchroLocomotion: companion-hub lane writes (same function pointer as C_SearchItemDogObjective)
    void  unk_21() override;                                         // [21] 0x18330E8D4  DisableSynchroLocomotion: undoes two of the three lanes [20] sets (same function pointer as C_SearchItemDogObjective)
    E_DogObjective::Type GetType() const override;                  // [17] 0x181A71880  return 0x16 (Pet)

    // No own members -- layout is exactly the synchro parent (sizeof 0xB8).
};
static_assert(sizeof(C_PetDogObjective) == 0xB8, "C_PetDogObjective adds no leaf fields");

// unk_19/unk_20/unk_21 keep the parent's placeholder void() spellings (the base declares them
// pure with an unresolved concrete signature); GetSynchroAnimRequest/EnableSynchroLocomotion/
// DisableSynchroLocomotion describe behavior only. The slaved-anim request types
// (S_ActionSlavedAnimRequest / S_ActionSlavedAnimRequestImpl<T>) have no RE header yet --
// out of scope for this pass. GetType[17] is still pure at the synchro-base level (inherited
// from C_DogObjective), so every leaf including this one must implement it directly.

}  // namespace wh::xgenaimodule::activitysystem
