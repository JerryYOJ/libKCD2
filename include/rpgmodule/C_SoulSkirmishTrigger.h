#pragma once
#include <cstddef>
#include <memory>
#include <unordered_map>
#include <vector>
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_SoulEffect.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "C_SkirmishSoulTriggerListener.h"
#include "I_Soul.h"

namespace wh::rpgmodule {

class C_SoulSkirmishTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_SoulEffect> {
public:
    C_SoulSkirmishTrigger();
    ~C_SoulSkirmishTrigger() override;                            // [0]
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<wh::conceptmodule::C_SoulEffect>) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                               // [27]
    void OnEffectActivate() override;                             // [43]
    void OnEffectDeactivate() override;                           // [44]
    void OnSoulRemoved(I_Soul* soul) override;                    // [48]
    std::vector<I_Soul*> GetAffectedSouls() const override;       // [49]

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<I_Soul*>> m_souls;                            // +0xB0
    wh::conceptmodule::C_TypedPortRef<I_Soul*> m_eventSoul;       // +0xF0
    wh::conceptmodule::C_TypedPortRef<I_Soul*> m_eventTargetSoul; // +0x130
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_soulJoined;               // +0x170
    std::unordered_map<
        I_Soul*,
        std::unique_ptr<C_SkirmishSoulTriggerListener>> m_listeners; // +0x1B0
};

static_assert(sizeof(wh::conceptmodule::C_EventNode<
                  wh::conceptmodule::C_SoulEffect>) == 0xB0,
              "C_SoulSkirmishTrigger base size mismatch");
static_assert(sizeof(C_SoulSkirmishTrigger) == 0x1F0,
              "C_SoulSkirmishTrigger size mismatch");
static_assert(offsetof(C_SoulSkirmishTrigger, m_souls) == 0xB0,
              "C_SoulSkirmishTrigger souls offset mismatch");
static_assert(offsetof(C_SoulSkirmishTrigger, m_soulJoined) == 0x170,
              "C_SoulSkirmishTrigger output offset mismatch");
static_assert(offsetof(C_SoulSkirmishTrigger, m_listeners) == 0x1B0,
              "C_SoulSkirmishTrigger listener map offset mismatch");

} // namespace wh::rpgmodule
