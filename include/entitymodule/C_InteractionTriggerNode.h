#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "E_InteractionType.h"
#include "I_RemovedEntityListener.h"

namespace wh::entitymodule {

class I_InteractionTrigger;
using C_InteractionTriggerNodeBase =
    wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>;

class C_InteractionTriggerNode
    : public C_InteractionTriggerNodeBase,
      public I_RemovedEntityListener {
public:
    C_InteractionTriggerNode();                                        // 0x18121E200
    ~C_InteractionTriggerNode() override;                              // [0] 0x180968C54
    RTTR_ENABLE(C_InteractionTriggerNodeBase)                           // [5..7], vtable 0x183B38D28
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                    // [27] 0x1829A91D4
    void OnEffectActivate() override;                                  // [43] 0x180DBFB6C
    void OnEffectDeactivate() override;                                // [44] 0x180DA66CC

    bool OnRemove(IEntity* entity) override;                            // +0xB0 [3] 0x18047F0FC
    const char* GetName() const override;                               // +0xB0 [7] 0x181A86D80

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<I_InteractionTrigger*>> m_interactors;              // +0xB8 RTTR "Interactors"
    wh::conceptmodule::C_TypedPortRef<E_InteractionType> m_type;       // +0xF8 RTTR "Type"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onInteraction;                  // +0x138 RTTR "OnInteraction"
    wh::conceptmodule::C_TypedPortRef<
        I_InteractionTrigger*> m_interactor;                            // +0x178 RTTR "Interactor"
    std::vector<I_InteractionTrigger*> m_resolvedInteractors;          // +0x1B8 sorted and deduplicated
    E_InteractionType m_interactionType;                               // +0x1D0 activation-time filter
    std::uint8_t m_padding1D4[4];                                      // +0x1D4
};

static_assert(offsetof(C_InteractionTriggerNode, m_interactors) == 0xB8,
              "C_InteractionTriggerNode::m_interactors offset mismatch");
static_assert(offsetof(C_InteractionTriggerNode, m_type) == 0xF8,
              "C_InteractionTriggerNode::m_type offset mismatch");
static_assert(offsetof(C_InteractionTriggerNode, m_onInteraction) == 0x138,
              "C_InteractionTriggerNode::m_onInteraction offset mismatch");
static_assert(offsetof(C_InteractionTriggerNode, m_interactor) == 0x178,
              "C_InteractionTriggerNode::m_interactor offset mismatch");
static_assert(offsetof(C_InteractionTriggerNode, m_resolvedInteractors) == 0x1B8,
              "C_InteractionTriggerNode::m_resolvedInteractors offset mismatch");
static_assert(offsetof(C_InteractionTriggerNode, m_interactionType) == 0x1D0,
              "C_InteractionTriggerNode::m_interactionType offset mismatch");
static_assert(sizeof(C_InteractionTriggerNode) == 0x1D8,
              "C_InteractionTriggerNode size mismatch");

} // namespace wh::entitymodule
