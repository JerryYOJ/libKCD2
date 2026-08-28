#pragma once
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "C_DogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_MoveDogObjective : C_DogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0x88. 19 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_MoveDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183C438E0, COL 0x1840DD160 offset 0, CHD 0x1845647C0 nbase=4 (single inheritance).
// ctor 0x18197988C(this, I_DogObjectiveContext*), dtor 0x18330AA1C.
// Pack embed C_DogObjectivePack+0xDD8. E_DogObjective::Move = 14.
//
// Plain go-to-a-point objective. Accept is true iff the request carries a world position or a
// resolvable target WUID; Apply copies the resulting Vec3 into m_dest. BeginWork issues a move
// (mode 4) toward m_dest and Connects an arrive callback; Tick is a nullsub -- completion is
// driven entirely by that callback (or StopIfRunning), never by polling. Virtual Complete [15]
// is deliberately a nullsub: every real finish path (arrive / StopIfRunning / BeginWork-fail)
// calls the shared CompleteInternal helper (0x1809F62F4) directly instead.

namespace wh::xgenaimodule::activitysystem {

class C_MoveDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_MoveDogObjective;

    bool  Accept(const S_DogObjectiveRequest*) override;                   // [6]  0x18330AC00  m_hasPosition || (m_hasTarget && WUID lookup hits)
    void  Apply(const S_DogObjectiveRequest*) override;                     // [7]  0x18330D7FC  copy dest from request position or looked-up object's world pos
    void  BeginWork() override;                                             // [8]  0x18330CBA4  far-nav flag, issue move mode 4, Connect arrive cb, hub wiggle/mood writes
    void  unk_11() override;                                                 // [11] 0x18330D378  EndWork: restore far-nav flag, disconnect arrive cb if hooked
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override;         // [12] 0x18330B2EC  30.0 if m_bound else -1.0
    bool  unk_14() override;                                                 // [14] 0x18041A6A0  return true (CanScoreWhileBusy)
    void  Complete() override;                                               // [15] 0x1803B6E80  nullsub -- does NOT call CompleteInternal; arrive/StopIfRunning/BeginWork-fail call 0x1809F62F4 directly
    E_DogObjective::Type GetType() const override;                         // [17] 0x181AA6B10  return 0xE (Move)

    Vec3    m_dest;               // +0x78
    bool    m_arrivedCbHooked;    // +0x84  name INFERRED
    uint8_t _pad85[3];            // +0x85
};
static_assert(sizeof(C_MoveDogObjective) == 0x88, "C_MoveDogObjective must be 0x88");
static_assert(offsetof(C_MoveDogObjective, m_dest) == 0x78, "m_dest at +0x78");

// unk_11/unk_14 keep the C_ActivityObjective-declared spellings (source names UNVERIFIED);
// EndWork/CanScoreWhileBusy describe behavior only. CanStart reduces to a 1-arg Accept() call
// since [13] and [14] are both forced true, so the shared start/score gate (0x180730F54) is
// always open regardless of the planner-busy flag.

}  // namespace wh::xgenaimodule::activitysystem
