#pragma once
#include <memory>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/TimeValue.h"
#include "C_DogObjective.h"
#include "C_NPCWatch.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_HuntDogObjective : C_DogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0x110. 19 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_HuntDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183A82318, COL 0x1840DD0E8 offset 0, CHD 0x184564E38 nbase=4 (single inheritance).
// ctor 0x180BC9ED4(this, I_DogObjectiveContext*), dtor body 0x18116CAC0.
// Pack embed C_DogObjectivePack+0xC48. E_DogObjective::Hunt = 10.
//
// Prey-chase / skirmish dog objective; does not move the dog itself except in the post-kill
// wait-for-master phase. Accept resolves a WUID to a prey I_NPC via C_NPCManager and gates
// through C_SkirmishManager + m_strategy. BeginWork starts a skirmish session against the prey
// (I_ActivityObjectiveContext[1]()+0x218), watches the prey (m_prey), and registers a MaxHuntSpeed
// clamp on the dog's own locomotion. FSM (m_fsm): 0 idle -> 1 hunting (skirmish/combat runs
// outside this class) -> 2 fetch-phase (prey stopped moving, C_NPCWatch reports a "downed" byte)
// -> 3 Fetch objective queued -> 4 wait-for-master (Fetch declined/exhausted).

namespace wh::xgenaimodule::activitysystem {

class C_HuntStrategy;  // I_SkirmishTargetingStrategy leaf; no RE header yet (skirmish subsystem out of campaign scope)

class C_HuntDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_HuntDogObjective;

    void  StopIfRunning() override;                                       // [4]  0x1819DF388  parent body, then sentinel m_waitMasterTimeout
    bool  Accept(const S_DogObjectiveRequest*) override;                    // [6]  0x180728DE0  m_hasTarget && C_NPCManager Find(request->m_target) accepted by AcceptPrey
    void  Apply(const S_DogObjectiveRequest*) override;                      // [7]  0x18330D764  same Find + AcceptPrey; stores prey's EntityId into m_preyEntityId
    void  BeginWork() override;                                              // [8]  0x18330C738  resolve prey, start skirmish session, hook watch/capacity/speed callbacks
    void  Tick() override;                                                    // [10] 0x18330E138  fsm==2 fetch-phase polling; fsm==4 wait-for-master distance/timeout
    void  unk_11() override;                                                  // [11] 0x18330D0B8  StopWork: unhook speed/watch/capacity callbacks, reset fsm/prey/timers/hub flags
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override;          // [12] 0x18330AEBC  m_bound: fixed 50.0; else distance lerp gated by the hub HuntPeriod cooldown
    bool  unk_13() override;                                                 // [13] 0x18330ABA4  extra CanStart gate: true unless GetMaster() exists and both a capability check and a soul flag(0x3C) fail
    E_DogObjective::Type GetType() const override;                         // [17] 0x181A99DB0  return 10 (Hunt)

    uint32_t    m_preyEntityId;          // +0x78  Cry EntityId; 0 = none
    uint8_t     m_fsm;                   // +0x7C  0 idle, 1 hunting, 2 fetch-phase, 3 fetch-queued, 4 wait-master
    uint8_t     _pad7D[3];               // +0x7D
    CTimeValue  m_waitMasterTimeout;     // +0x80  HuntWaitForMasterTimeout; armed on entering fsm 4
    CTimeValue  m_fetchRetryTimeout;     // +0x88  2s retry window before giving up on the Fetch handoff
    CTimeValue  m_unk90;                 // +0x90  sentinel-only in every method scanned; role UNVERIFIED (no start-timer writer found)
    C_NPCWatch  m_prey;                  // +0x98  sizeof 0x50; watch signals feed OnPreyPtrCleared / OnPreyWatchByte
    Vec3        m_preyLastPos;           // +0xE8  stability check for "prey stopped moving" (fetch-phase gate)
    uint32_t    m_speedHookId;           // +0xF4  MaxHuntSpeed clamp registration id; invalid 0xFFFFFFFF
    bool        m_npcComponentHooked;    // +0xF8
    bool        m_controller218Hooked;   // +0xF9
    bool        m_moveToPreyActive;      // +0xFA  wait-for-master phase move-to-prey in flight
    bool        m_huntedMarker;          // +0xFB  drives the prey's "hare_hunted" actor action while true
    uint8_t     _padFC[4];               // +0xFC
    std::shared_ptr<C_HuntStrategy> m_strategy;  // +0x100  skirmish targeting-strategy leaf passed into the session/AcceptPrey gate
};
static_assert(sizeof(C_HuntDogObjective) == 0x110, "C_HuntDogObjective must be 0x110");
static_assert(offsetof(C_HuntDogObjective, m_waitMasterTimeout) == 0x80, "m_waitMasterTimeout at +0x80");
static_assert(offsetof(C_HuntDogObjective, m_prey) == 0x98, "m_prey at +0x98");
static_assert(offsetof(C_HuntDogObjective, m_speedHookId) == 0xF4, "m_speedHookId at +0xF4");
static_assert(offsetof(C_HuntDogObjective, m_strategy) == 0x100, "m_strategy at +0x100");

// unk_13's name and predicate are behavior-described, not RTTI-proven (master vf+0x1B0 / soul
// vf+0x358(0x3C) meaning UNVERIFIED). Complete [15] stays INHERITED (not overridden) -- Hunt never
// changes its always-fail-code-0 behavior; every success/hand-off path in this class calls the
// shared helper 0x1809F62F4 directly with an explicit code. The hub HuntPeriod/HuntMaximumCapacity
// cooldown that gates ComputeScore is written by a separate registered callback
// (OnHuntCapacityEvent, hub+0x330/+0x338/+0x328), not by anything in this class's own Tick.

}  // namespace wh::xgenaimodule::activitysystem
