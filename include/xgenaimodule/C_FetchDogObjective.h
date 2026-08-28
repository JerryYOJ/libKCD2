#pragma once
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "C_DogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_FetchDogObjective : C_DogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0x98. 19 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_FetchDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183C42220, COL 0x1840DD980 offset 0, CHD 0x184562A60 nbase=4 (single inheritance).
// ctor 0x181950420(this, I_DogObjectiveContext*), dtor 0x18330006C.
// Pack embed C_DogObjectivePack+0xA10. E_DogObjective::Fetch = 9.
//
// Player-dog fetch: walk to a resolvable target entity, face it, pick it up, carry it back to the
// master, deliver/stash. Accept/Apply resolve a WUID (request or auto-picked from the companion
// hub) to a Cry EntityId. FSM is driven by m_phase across BeginWork/Tick/callback pairs; unk_11
// ([11], EndWork) is the shared teardown, called by the Complete helper (0x1809F62F4) whenever
// m_selfRunning, not only from an explicit stop request.

namespace wh::xgenaimodule::activitysystem {

class C_FetchDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FetchDogObjective;

    bool  Accept(const S_DogObjectiveRequest*) override;                 // [6]  0x1807291D0  m_hasTarget (+0x2A) && ResolveTargetEntityId(&request->m_target) != 0
    void  Apply(const S_DogObjectiveRequest*) override;                   // [7]  0x18330299C  ResolveTargetEntityId(&request->m_target) -> m_targetEntityId; m_fromRequest = true
    void  BeginWork() override;                                            // [8]  0x1833021F4  resolve target; near-master short-circuit; else face-or-move to it
    void  unk_09() override;                                                // [9]  0x1833027FC  AbortWork: cancel in-flight move, force StartDeliver(1)
    void  Tick() override;                                                  // [10] 0x18330303C  phase==1 near-master success poll; phase==4 receive-radius cancel / dest-drift repath
    void  unk_11() override;                                                // [11] 0x183302698  EndWork: unhook move/face/pickup callbacks, clear phase + target id, clear hub flags
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override;        // [12] 0x180395518  auto-pick if no target; scores -1.0 / 30.0(auto) / 60.0(request)
    bool  unk_13() override;                                                // [13] 0x18094E394  HasValidMaster: GetMaster() && master->vf+0x1B0(); shared impl with C_RunawayDogObjective
    E_DogObjective::Type GetType() const override;                        // [17] 0x181A9AD60  return 9 (Fetch)

    uint32_t m_phase;            // +0x78  0 idle, 1 move, 2 face, 3 pickup, 4 return, 5 deliver
    uint32_t m_targetEntityId;   // +0x7C  Cry EntityId (typedef unsigned int); resolved via IEntitySystem / WUID registry
    Vec3     m_returnDest;       // +0x80  cached master position for the homeward leg; repathed if drifted > 3m
    bool     m_repathLock;       // +0x8C  held around StartReturnToMaster to suppress the move-callback's deliver branch
    bool     m_fromRequest;      // +0x8D  true = player-commanded target; false = auto-picked (affects ComputeScore band)
    bool     m_aborting;         // +0x8E  set for the duration of AbortWork; move/pickup/face callbacks no-op while set
    bool     m_moveCbHooked;     // +0x8F
    bool     m_faceCbHooked;     // +0x90
    bool     m_pickupCbHooked;   // +0x91
    uint8_t  _pad92[6];          // +0x92
};
static_assert(sizeof(C_FetchDogObjective) == 0x98, "C_FetchDogObjective must be 0x98");
static_assert(offsetof(C_FetchDogObjective, m_returnDest) == 0x80, "m_returnDest at +0x80");
static_assert(offsetof(C_FetchDogObjective, m_moveCbHooked) == 0x8F, "m_moveCbHooked at +0x8F");

// unk_09/unk_11/unk_13 keep the C_ActivityObjective-declared spellings (source names UNVERIFIED);
// AbortWork/EndWork/HasValidMaster describe behavior only. Virtual Complete ([15], inherited) is
// always the FAIL path (CompleteWithCode(this,0)) -- success completes go directly through the
// shared helper 0x1809F62F4(this,1) from OnPickupFinished, never through the virtual. The pickup
// callback (hub+0x278) and the return-trigger callback (hub+0x2A8, TryStartReturn) are two SEPARATE
// subscribers, not one continuous sequence -- do not fuse them when reimplementing.

}  // namespace wh::xgenaimodule::activitysystem
