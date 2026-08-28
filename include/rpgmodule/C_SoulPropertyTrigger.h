#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <utility>
#include <vector>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_StateProxy.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../questmodule/S_Tracker.h"
#include "E_SoulProperty.h"
#include "I_Soul.h"

namespace wh::rpgmodule {

class C_SoulPropertyTrigger
    : public wh::conceptmodule::C_StateProxy<
          wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>> {
public:
    struct S_WatchedSoul {
        C_SoulPropertyTrigger* m_trigger;                        // +0x00
        I_Soul* m_soul;                                          // +0x08
    };

    C_SoulPropertyTrigger();
    ~C_SoulPropertyTrigger() override;                           // [0]
    RTTR_ENABLE(wh::conceptmodule::C_StateProxy<wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>>) // [5..7]
    rttr::variant GetPortValue(
        const _smart_ptr<wh::conceptmodule::I_Port>& port) override; // [12]
    void OnEffectActivate() override;                            // [43]
    void OnEffectDeactivate() override;                          // [44]
    virtual void OnAggregateStateChanged(
        bool allMatching,
        bool noneMatching) = 0;                                  // [47]
    virtual void OnSoulStateChanged(
        I_Soul* soul,
        bool matching) = 0;                                      // [48]

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<I_Soul*>> m_souls;                           // +0xB8
    wh::conceptmodule::C_TypedPortRef<I_Soul*> m_soul;           // +0xF8
    wh::conceptmodule::C_TypedPortRef<
        wh::questmodule::S_Tracker> m_tracker;                    // +0x138
    std::vector<std::pair<E_SoulProperty::Type, float>>
        m_propertyRequirements;                                  // +0x178
    std::vector<I_Soul*> m_watchedSouls;                         // +0x190
    std::vector<std::unique_ptr<S_WatchedSoul>> m_watchers;      // +0x1A8
    std::uint32_t m_matchingSoulCount;                           // +0x1C0
    bool m_emitOnExec;                                           // +0x1C4
    std::uint8_t m_padding1C5[3];                               // +0x1C5
};

static_assert(sizeof(C_SoulPropertyTrigger::S_WatchedSoul) == 0x10,
              "C_SoulPropertyTrigger watcher size mismatch");
static_assert(sizeof(wh::conceptmodule::C_StateProxy<
                  wh::conceptmodule::C_EventNode<
                      wh::conceptmodule::C_Effect>>) == 0xB8,
              "C_SoulPropertyTrigger base size mismatch");
static_assert(sizeof(C_SoulPropertyTrigger) == 0x1C8,
              "C_SoulPropertyTrigger size mismatch");
static_assert(offsetof(C_SoulPropertyTrigger, m_souls) == 0xB8,
              "C_SoulPropertyTrigger souls offset mismatch");
static_assert(offsetof(C_SoulPropertyTrigger, m_soul) == 0xF8,
              "C_SoulPropertyTrigger soul offset mismatch");
static_assert(offsetof(C_SoulPropertyTrigger, m_tracker) == 0x138,
              "C_SoulPropertyTrigger tracker offset mismatch");
static_assert(offsetof(C_SoulPropertyTrigger, m_propertyRequirements) == 0x178,
              "C_SoulPropertyTrigger requirements offset mismatch");
static_assert(offsetof(C_SoulPropertyTrigger, m_watchedSouls) == 0x190,
              "C_SoulPropertyTrigger watched-souls offset mismatch");
static_assert(offsetof(C_SoulPropertyTrigger, m_watchers) == 0x1A8,
              "C_SoulPropertyTrigger watchers offset mismatch");
static_assert(offsetof(C_SoulPropertyTrigger, m_matchingSoulCount) == 0x1C0,
              "C_SoulPropertyTrigger current-count offset mismatch");

} // namespace wh::rpgmodule
