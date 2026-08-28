#pragma once
#include <cstddef>
#include <cstdint>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "E_ActorIdleState.h"
#include "E_ActorMountState.h"
#include "E_ActorState.h"

namespace wh::rpgmodule { class I_Soul; }

namespace wh::entitymodule {

template <typename TState>
class C_ActorStateTrigger
    : public wh::conceptmodule::C_EventNode<
          wh::conceptmodule::C_Effect> {
public:
    C_ActorStateTrigger();
    ~C_ActorStateTrigger() override;
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<
        wh::conceptmodule::C_Effect>)                          // [5..7]
    void OnEffectActivate() override;                          // [43], bind soul and state listeners
    void OnEffectDeactivate() override;                        // [44], unbind state listeners

    virtual TState unk_47() = 0;                               // [47], watched policy state
    virtual void unk_48();                                     // [48], emit enter trigger
    virtual void unk_49();                                     // [49], emit leave trigger

    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::I_Soul*> m_soul;                        // +0xB0
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onEnter;                // +0xF0
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onLeave;                // +0x130
    bool m_stateListenerRegistered;                             // +0x170
    std::uint8_t m_padding171[7];                              // +0x171
    wh::rpgmodule::I_Soul* m_boundSoul;                         // +0x178
    std::uint32_t m_transitionState;                            // +0x180, 0 unknown / 1 matching / 2 nonmatching
    std::uint8_t m_padding184[4];                              // +0x184
};

static_assert(offsetof(
                  C_ActorStateTrigger<E_ActorState::Type>, m_soul) == 0xB0,
              "C_ActorStateTrigger::m_soul offset mismatch");
static_assert(offsetof(
                  C_ActorStateTrigger<E_ActorState::Type>, m_onEnter) == 0xF0,
              "C_ActorStateTrigger::m_onEnter offset mismatch");
static_assert(offsetof(
                  C_ActorStateTrigger<E_ActorState::Type>, m_onLeave) == 0x130,
              "C_ActorStateTrigger::m_onLeave offset mismatch");
static_assert(offsetof(
                  C_ActorStateTrigger<E_ActorState::Type>,
                  m_stateListenerRegistered) == 0x170,
              "C_ActorStateTrigger::m_stateListenerRegistered offset mismatch");
static_assert(offsetof(
                  C_ActorStateTrigger<E_ActorState::Type>, m_boundSoul) == 0x178,
              "C_ActorStateTrigger::m_boundSoul offset mismatch");
static_assert(offsetof(
                  C_ActorStateTrigger<E_ActorState::Type>, m_transitionState) == 0x180,
              "C_ActorStateTrigger::m_transitionState offset mismatch");
static_assert(sizeof(C_ActorStateTrigger<E_ActorState::Type>) == 0x188,
              "C_ActorStateTrigger<E_ActorState::Type> size mismatch");
static_assert(sizeof(C_ActorStateTrigger<E_ActorIdleState::Type>) == 0x188,
              "C_ActorStateTrigger<E_ActorIdleState::Type> size mismatch");
static_assert(sizeof(C_ActorStateTrigger<E_ActorMountState::Type>) == 0x188,
              "C_ActorStateTrigger<E_ActorMountState::Type> size mismatch");

}  // namespace wh::entitymodule
