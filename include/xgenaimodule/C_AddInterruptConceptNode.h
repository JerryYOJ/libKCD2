#pragma once

#include <cstddef>

#include "../conceptmodule/C_Node.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "../entitymodule/E_Urgency.h"
#include "C_SmartEntity.h"
#include "scheduler/E_Aliveness.h"

namespace wh::rpgmodule {
class I_Soul;
}

namespace wh::xgenaimodule {

class C_AddInterruptConceptNode : public wh::conceptmodule::C_Node {
public:
    ~C_AddInterruptConceptNode() override;                                   // [0] 0x1813937AC
    RTTR_ENABLE(wh::conceptmodule::C_Node)                                   // [5..7], vtable 0x183AEBAF0

    CryStringT<char> m_signature;                                            // +0x40 RTTR "Signature"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_activate;                            // +0x48 RTTR "Activate"
    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::I_Soul*> m_npc;                                       // +0x88 RTTR "NPC"
    wh::conceptmodule::C_TypedPortRef<CryStringT<char>> m_behavior;          // +0xC8 RTTR "Behavior"
    wh::conceptmodule::C_TypedPortRef<C_SmartEntity*> m_smartEntity;         // +0x108 RTTR "SmartEntity"
    wh::conceptmodule::C_TypedPortRef<unsigned char> m_priority;             // +0x148 RTTR "Priority"
    wh::conceptmodule::C_TypedPortRef<
        wh::entitymodule::E_Urgency::Type> m_urgency;                        // +0x188 RTTR "Urgency"
    wh::conceptmodule::C_TypedPortRef<
        scheduler::E_Aliveness::Type> m_aliveness;                           // +0x1C8 RTTR "Aliveness"
    wh::conceptmodule::C_TypedPortRef<bool> m_privileged;                    // +0x208 RTTR "Privileged"
};

static_assert(offsetof(C_AddInterruptConceptNode, m_signature) == 0x40,
              "C_AddInterruptConceptNode::m_signature offset mismatch");
static_assert(offsetof(C_AddInterruptConceptNode, m_activate) == 0x48,
              "C_AddInterruptConceptNode::m_activate offset mismatch");
static_assert(offsetof(C_AddInterruptConceptNode, m_privileged) == 0x208,
              "C_AddInterruptConceptNode::m_privileged offset mismatch");
static_assert(sizeof(C_AddInterruptConceptNode) == 0x248,
              "C_AddInterruptConceptNode size mismatch");

} // namespace wh::xgenaimodule
