#pragma once
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "C_DogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_TeleportDogObjective : C_DogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0x98. 19 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_TeleportDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183C42668, COL 0x1840DD278 offset 0, CHD 0x184564808 nbase=4 (single inheritance).
// ctor 0x1819516AC(this, I_DogObjectiveContext*), dtor 0x18330AB2C.
// Pack embed C_DogObjectivePack+0x13D0. E_DogObjective::Teleport = 24.
//
// One-shot relocate of the dog. Accept is true iff the request carries a world position or a
// target WUID; Apply resolves either into m_position/m_rotation (target path also copies the
// looked-up object's forward direction; falls back to the dog's own position/facing on a miss).
// BeginWork cancels any in-flight companion move (I_ActivityObjectiveContext::unk_01() hub+0x150,
// the same C_MoveActivityComponent cancel Fetch uses), then teleports the NPC via C_NPC[85] and
// sets facing via C_NPC[5]. Tick is inherited nullsub; BeginWork never emits m_onComplete, so the
// objective stays bound (score 60.0) until the planner externally Stops/Completes it. [13]/[14]
// are both forced true, so CanStart/scoring never veto on the actor-busy flag.

namespace wh::xgenaimodule::activitysystem {

class C_TeleportDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_TeleportDogObjective;

    bool  Accept(const S_DogObjectiveRequest*) override;                 // [6]  0x18330AC60  m_hasPosition || m_hasTarget
    void  Apply(const S_DogObjectiveRequest*) override;                   // [7]  0x18330D95C  target path: WUID lookup pos+forward; else position path: request position (+ optional direction)
    void  BeginWork() override;                                            // [8]  0x18330CF64  cancel in-flight move, one-shot NPC teleport + set rotation
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override;       // [12] 0x18330B34C  60.0 if m_bound else -1.0
    bool  unk_14() override;                                               // [14] 0x18041A6A0  return true (CanScoreWhileBusy, proposed name)
    E_DogObjective::Type GetType() const override;                       // [17] 0x181A71860  return 0x18 (Teleport)

    Vec3 m_position;    // +0x78  dest; zero-initialized, written by Apply
    Quat m_rotation;    // +0x84  facing; identity (0,0,0,1) until Apply
    uint8_t _pad94[4];  // +0x94
};
static_assert(sizeof(C_TeleportDogObjective) == 0x98, "C_TeleportDogObjective must be 0x98");
static_assert(offsetof(C_TeleportDogObjective, m_position) == 0x78, "m_position at +0x78");
static_assert(offsetof(C_TeleportDogObjective, m_rotation) == 0x84, "m_rotation at +0x84");

// unk_14 keeps the C_ActivityObjective-declared spelling (source name UNVERIFIED);
// CanScoreWhileBusy describes behavior only. m_hasTarget with an invalid/miss WUID and no
// m_hasPosition still passes Accept, but Apply then writes neither field, so BeginWork
// teleports to the ctor-default (0,0,0) + identity facing -- do not assume Accept implies a
// meaningful destination was resolved.

}  // namespace wh::xgenaimodule::activitysystem
