#pragma once
#include <cstddef>
#include <cstdint>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/E_Operator.h"
#include "../conceptmodule/S_Trigger.h"
#include "E_SoulCounter.h"
#include "E_SoulDerivedStat.h"
#include "E_SoulStat.h"
#include "E_SoulState.h"

namespace wh::rpgmodule {

class I_Soul;

template <typename TProperty>
class C_SoulNumericPropertyTrigger : public wh::conceptmodule::C_Effect {
public:
    C_SoulNumericPropertyTrigger();
    ~C_SoulNumericPropertyTrigger() override;
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                    // [5..7]
    void OnEffectActivate() override;                           // [43], resolve and subscribe
    void OnEffectDeactivate() override;                         // [44], unsubscribe and clear state

    wh::conceptmodule::C_TypedPortRef<I_Soul*> m_soul;          // +0x88
    wh::conceptmodule::C_TypedPortRef<TProperty> m_property;    // +0xC8
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::E_Operator> m_operator;              // +0x108
    wh::conceptmodule::C_TypedPortRef<float> m_value;           // +0x148
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onMatch;                // +0x188
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onUnmatch;              // +0x1C8
    bool m_listenerRegistered;                                 // +0x208
    std::uint8_t m_padding209[7];                              // +0x209
    I_Soul* m_boundSoul;                                       // +0x210
    wh::conceptmodule::E_Operator m_resolvedOperator;           // +0x218
    float m_resolvedValue;                                     // +0x21C
    std::uint32_t m_matchState;                                // +0x220, 0 unknown / 1 match / 2 unmatch
    std::uint32_t m_padding224;                                // +0x224
};

static_assert(offsetof(
                  C_SoulNumericPropertyTrigger<E_SoulCounter>, m_soul) == 0x88,
              "C_SoulNumericPropertyTrigger::m_soul offset mismatch");
static_assert(offsetof(
                  C_SoulNumericPropertyTrigger<E_SoulCounter>, m_property) ==
                  0xC8,
              "C_SoulNumericPropertyTrigger::m_property offset mismatch");
static_assert(offsetof(
                  C_SoulNumericPropertyTrigger<E_SoulCounter>, m_operator) ==
                  0x108,
              "C_SoulNumericPropertyTrigger::m_operator offset mismatch");
static_assert(offsetof(
                  C_SoulNumericPropertyTrigger<E_SoulCounter>, m_onMatch) ==
                  0x188,
              "C_SoulNumericPropertyTrigger::m_onMatch offset mismatch");
static_assert(offsetof(
                  C_SoulNumericPropertyTrigger<E_SoulCounter>,
                  m_listenerRegistered) == 0x208,
              "C_SoulNumericPropertyTrigger::m_listenerRegistered offset mismatch");
static_assert(offsetof(
                  C_SoulNumericPropertyTrigger<E_SoulCounter>, m_boundSoul) ==
                  0x210,
              "C_SoulNumericPropertyTrigger::m_boundSoul offset mismatch");
static_assert(offsetof(
                  C_SoulNumericPropertyTrigger<E_SoulCounter>, m_matchState) ==
                  0x220,
              "C_SoulNumericPropertyTrigger::m_matchState offset mismatch");
static_assert(sizeof(C_SoulNumericPropertyTrigger<E_SoulCounter>) == 0x228,
              "counter soul-property trigger size mismatch");
static_assert(sizeof(C_SoulNumericPropertyTrigger<E_SoulDerivedStat>) == 0x228,
              "derived-stat soul-property trigger size mismatch");
static_assert(sizeof(C_SoulNumericPropertyTrigger<E_SoulStat>) == 0x228,
              "stat soul-property trigger size mismatch");
static_assert(sizeof(C_SoulNumericPropertyTrigger<E_SoulState>) == 0x228,
              "state soul-property trigger size mismatch");

}  // namespace wh::rpgmodule
