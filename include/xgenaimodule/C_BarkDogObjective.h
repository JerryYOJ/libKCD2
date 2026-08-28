#pragma once
#include "../CryEngine/CryCommon/TimeValue.h"
#include "../framework/WUID.h"
#include "C_DogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_BarkDogObjective : C_DogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0x90. 19 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_BarkDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183C74110, COL 0x1840DD868 offset 0, CHD 0x184562A30 nbase=4 (single inheritance).
// No standalone ctor -- inlined in pack ctor 0x1809F5960 at pack+0x100. Dtor 0x1832FFE6C.
// Pack embed C_DogObjectivePack+0x100.
//
// Player-dog "bark at NPC" objective. Accept requires S_DogObjectiveRequest::m_hasTarget; Apply
// latches the target WUID. BeginWork faces the target then arms a BarkInterval cooldown; on
// turn-done it starts the bark component and sets mood/barking-mode context. ComputeScore scores
// -1 while the interval cooldown is still live; once expired, distance-lerps between
// BarkMinDistance (max priority) and BarkMaxDistance (negligible priority).
//
// No independent adversarial-verify pass completed for this leaf (infra errors, twice) -- RTTI /
// vtable / GetType were independently re-derived and confirmed by both cross-cutting audits
// (AUDIT2/AUDIT3) as a substitute; layout below is the dossier's own evidence, not re-audited.

namespace wh::xgenaimodule::activitysystem {

class C_BarkDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_BarkDogObjective;

    void  StopIfRunning() override;                                 // [4]  0x182096BC0  parent body 0x1809F4E08, then sentinel m_intervalDeadline
    bool  Accept(const S_DogObjectiveRequest*) override;             // [6]  0x181AA6840  return request->m_hasTarget (+0x2A byte)
    void  Apply(const S_DogObjectiveRequest*) override;               // [7]  0x181AA68B0  m_target = request->m_target (+0x18 qword)
    void  BeginWork() override;                                        // [8]  0x180394E3C  face target via C_TurnBodyActivityComponent, hook turn-done, arm BarkInterval
    void  unk_11() override;                                            // [11] 0x1819A7A60  EndWork: disconnect hooks, reset m_target, clear barking-mode context
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override;    // [12] 0x18094BA44  cooldown-gated distance lerp (BarkMinDistance..BarkMaxDistance)
    E_DogObjective::Type GetType() const override;                   // [17] 0x181A74A40  return 2 (Bark)

    wh::framework::WUID m_target;              // +0x78  invalid sentinel qword_18533A260
    CTimeValue           m_intervalDeadline;    // +0x80  BarkInterval cooldown; sentinel -100000; NOT cleared on natural success
    bool                  m_turnBodySubscribed;  // +0x88  guards Disconnect of the turn-done callback
    bool                  m_barkComponentSubscribed; // +0x89  guards Disconnect of the bark-component-done callback
    uint8_t               _pad8A[6];             // +0x8A
};
static_assert(sizeof(C_BarkDogObjective) == 0x90, "C_BarkDogObjective must be 0x90");
static_assert(offsetof(C_BarkDogObjective, m_intervalDeadline) == 0x80, "m_intervalDeadline at +0x80");
static_assert(offsetof(C_BarkDogObjective, m_turnBodySubscribed) == 0x88, "m_turnBodySubscribed at +0x88");

// GetType [17]'s stub is ICF-shared with unrelated vtables; binding is this class's own vtable
// slot, not the byte pattern. EndWork [11] does not restore mood context on natural completion --
// if OnTurnBodyDone set mood 2, it sticks after Complete (only StopIfRunning's abort path and the
// BarkingMode channel reset run; the mood setter is never called from EndWork).

}  // namespace wh::xgenaimodule::activitysystem
