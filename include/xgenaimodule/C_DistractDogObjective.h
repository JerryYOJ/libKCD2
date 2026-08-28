#pragma once
#include "../CryEngine/CryCommon/TimeValue.h"
#include "../framework/C_ModelProperty.h"
#include "C_DogObjective.h"
#include "E_DistractDogState.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_DistractDogObjective : C_DogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0xA8. 19 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_DistractDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183B1F3A8, COL 0x1840DD8E0 offset 0, CHD 0x184562A18 nbase=4 (single inheritance).
// ctor 0x18116C7D4(this, I_DogObjectiveContext*), dtor 0x18116C7A4.
// Pack embed C_DogObjectivePack+0x3A0. E_DogObjective::Distract = 21 (0x15).
//
// Player command: wait, then bark to draw NPC attention; breaks off to flee a set distance if an
// enemy closes inside DogDistractFleeRadius. m_state is an embedded C_ModelProperty
// (COMPOSITION, not a second MI base -- its own COL has offset 0 but it is absent from this
// class's own CHD). ComputeScore is a constant {7.0f, band 0} -- Distract is never auto-picked by
// score gradient, only ever requested explicitly.

namespace wh::xgenaimodule::activitysystem {

class C_DistractDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DistractDogObjective;

    bool  Accept(const S_DogObjectiveRequest*) override;             // [6]  0x183300464  return true; request unused (side effect only, entity-relation poke via GetNPC)
    void  BeginWork() override;                                        // [8]  0x183302050  hub cluster flag, EnterWait (arm DogDistractInitialWaitTime)
    void  Tick() override;                                              // [10] 0x183302E94  flee-gate check, then FSM switch on m_state (Wait/Bark/Flee)
    void  unk_11() override;                                            // [11] 0x183302534  Stop: cancel in-flight interaction if Bark/Flee, always clear bark channel + hub flag + disconnect callbacks
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override;    // [12] 0x181AA6850  always {7.0f, band 0}
    E_DogObjective::Type GetType() const override;                   // [17] 0x181A71890  return 0x15 (Distract = 21)

    using StateProperty = wh::shared::C_ModelProperty<
        E_DistractDogState::Type,
        wh::shared::traits::C_StaticDefaultValueTrait<E_DistractDogState::Type, E_DistractDogState::Wait>,
        wh::shared::traits::C_SignalWithNewValueTrait<E_DistractDogState::Type>,
        wh::shared::traits::C_DebugNoTrace,
        wh::shared::traits::C_NoSaveLoad,
        wh::shared::traits::C_OwnershipEmpty>;

    StateProperty m_state;     // +0x78  sizeof 0x28; value byte at +0x80, C_Signal at +0x88
    CTimeValue    m_phaseEnd;  // +0xA0  Wait/Bark phase deadline; sentinel -100000; armed from S_Constants (DogDistractInitialWaitTime / DogDistractBarkTime)
};
static_assert(sizeof(C_DistractDogObjective) == 0xA8, "C_DistractDogObjective must be 0xA8");
static_assert(offsetof(C_DistractDogObjective, m_state) == 0x78, "m_state at +0x78");
static_assert(offsetof(C_DistractDogObjective, m_phaseEnd) == 0xA0, "m_phaseEnd at +0xA0");
static_assert(sizeof(C_DistractDogObjective::StateProperty) == 0x28, "StateProperty must be 0x28");

// Flee radius/distance/bark/wait timings are RPG params (DogDistractFleeRadius,
// DogDistractFleeDistance, DogDistractBarkTime, DogDistractInitialWaitTime) read from
// wh::rpgmodule::S_Constants at runtime, not compiled-in constants -- not modeled as fields here.
// Do not confuse GetType (this class's identity, 21) with the FSM byte inside m_state (0/1/2) or
// with the unrelated 7-case debug-name switch at 0x183304A6C.

}  // namespace wh::xgenaimodule::activitysystem
