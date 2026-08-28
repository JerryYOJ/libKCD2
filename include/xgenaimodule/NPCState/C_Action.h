#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "../../CryEngine/CryCommon/CryString.h"
#include "../../entitymodule/E_Urgency.h"
#include "../../rttr/rttr_enable.h"
#include "I_Condition.h"
#include "I_Effect.h"
#include "I_FilteringCondition.h"

namespace wh::xgenaimodule::NPCState {

class C_Action {
public:
    virtual ~C_Action();                                                 // [0]
    RTTR_ENABLE()                                                        // [24..26], vtable 0x183A2E0C0

    CryStringT<char> m_name;                                             // +0x08 RTTR "Name"
    wh::entitymodule::E_Urgency::Type m_urgency;                         // +0x10 RTTR "Urgency"
    std::int32_t m_priority;                                             // +0x14 RTTR "Priority"
    std::uint8_t m_padding18[8];                                         // +0x18
    std::vector<std::shared_ptr<I_Condition>> m_conditions;              // +0x20 RTTR "Conditions"
    std::vector<std::shared_ptr<I_Effect>> m_effects;                    // +0x38 RTTR "Effects"
    std::vector<std::shared_ptr<I_FilteringCondition>> m_filteringConditions; // +0x50 RTTR "FilteringConditions"
    std::uint8_t m_unknown68[0x28];                                      // +0x68 includes accessor-backed DisabledForUrgencies
};

static_assert(offsetof(C_Action, m_name) == 0x08,
              "NPCState::C_Action::m_name offset mismatch");
static_assert(offsetof(C_Action, m_urgency) == 0x10,
              "NPCState::C_Action::m_urgency offset mismatch");
static_assert(offsetof(C_Action, m_priority) == 0x14,
              "NPCState::C_Action::m_priority offset mismatch");
static_assert(offsetof(C_Action, m_conditions) == 0x20,
              "NPCState::C_Action::m_conditions offset mismatch");
static_assert(offsetof(C_Action, m_effects) == 0x38,
              "NPCState::C_Action::m_effects offset mismatch");
static_assert(offsetof(C_Action, m_filteringConditions) == 0x50,
              "NPCState::C_Action::m_filteringConditions offset mismatch");
static_assert(sizeof(C_Action) == 0x90,
              "NPCState::C_Action size mismatch");

} // namespace wh::xgenaimodule::NPCState
