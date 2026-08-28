#pragma once
#include <cstddef>
#include <vector>
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_SoulEffect.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "I_Soul.h"
#include "S_BuffDefinitionAITag.h"

namespace wh::rpgmodule {

class C_BuffTagTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_SoulEffect> {
public:
    C_BuffTagTrigger();
    ~C_BuffTagTrigger() override;                                 // [0]
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
    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<S_BuffDefinitionAITag>> m_buffTags;           // +0xF0
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAdded;                  // +0x130
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onRemoved;                // +0x170
    wh::conceptmodule::C_TypedArrayPortRef<I_Soul*> m_soul;      // +0x1B0
    wh::conceptmodule::C_TypedArrayPortRef<
        S_BuffDefinitionAITag> m_buffTag;                         // +0x1F0
    std::vector<I_Soul*> m_watchedSouls;                          // +0x230
    std::vector<S_BuffDefinitionAITag> m_watchedBuffTags;        // +0x248
};

static_assert(sizeof(C_BuffTagTrigger) == 0x260,
              "C_BuffTagTrigger size mismatch");
static_assert(offsetof(C_BuffTagTrigger, m_souls) == 0xB0,
              "C_BuffTagTrigger souls offset mismatch");
static_assert(offsetof(C_BuffTagTrigger, m_soul) == 0x1B0,
              "C_BuffTagTrigger event soul offset mismatch");
static_assert(offsetof(C_BuffTagTrigger, m_watchedSouls) == 0x230,
              "C_BuffTagTrigger watched souls offset mismatch");
static_assert(offsetof(C_BuffTagTrigger, m_watchedBuffTags) == 0x248,
              "C_BuffTagTrigger watched tags offset mismatch");

} // namespace wh::rpgmodule
