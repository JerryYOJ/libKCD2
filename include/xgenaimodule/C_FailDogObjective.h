#pragma once
#include "../CryEngine/CryCommon/TimeValue.h"
#include "C_DogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_FailDogObjective : C_DogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0x80. 19 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_FailDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183D155C0, COL 0x1840DD958 offset 0, CHD 0x184562BE0 nbase=4 (single inheritance).
// No standalone ctor -- inlined in pack ctor 0x1809F5960 at pack+0xD58: C_DogObjective
// ctor 0x1806265D8, stamp this vtable, sentinel-init the own CTimeValue. Dtor 0x183300038.
// Pack embed C_DogObjectivePack+0xD58.
//
// One-shot "couldn't do that" beat -- NOT the FindByType miss target (that is
// C_WaitDogObjective at pack+0x4F8, GetType 0). ComputeScore is a constant -1.0,
// so the planner never picks Fail by score; the proven hardcoded producer is
// C_SearchItemDogObjective's abort paths (synchro-fail / out-of-area / sniff-miss),
// which explicitly FindByType(0xD) and force-enqueue it.

namespace wh::xgenaimodule::activitysystem {

class C_FailDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FailDogObjective;

    bool  Accept(const S_DogObjectiveRequest*) override;  // [6]  0x18041A6A0  return true (parent C_ActivityObjective returns false); request ignored, Apply stays the inherited no-op
    void  BeginWork() override;                             // [8]  0x183302190  play companion FMOD event "dog_comp_impossible_tired" (event id 0x21) on the dog actor, arm 1.0s m_timeout (no jitter)
    void  Tick() override;                                   // [10] 0x183303010  when m_timeout is armed-and-due: Complete via shared helper with emit code 1
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override; // [12] 0x18330097C  always {score=-1.0f, band=0} -- never planner-picked by score
    E_DogObjective::Type GetType() const override;          // [17] 0x181A86DD0  return 0xD (Fail = 13)

    CTimeValue m_timeout;  // +0x78  sentinel -100000; pack ctor primes it, BeginWork arms now+1.0s
};
static_assert(sizeof(C_FailDogObjective) == 0x80, "C_FailDogObjective must be 0x80");
static_assert(offsetof(C_FailDogObjective, m_timeout) == 0x78, "m_timeout at +0x78");

// GetType [17]'s 3-byte stub is ICF-shared with unrelated non-dog vtables (e.g. C_ForgeBuilder
// slot 0); binding is this class's own vtable SLOT, not the byte pattern.
// unk_9/unk_11/unk_13/unk_14/unk_18 all stay the inherited C_ActivityObjective/C_DogObjective
// defaults -- Fail overrides only the five slots above.

}  // namespace wh::xgenaimodule::activitysystem
