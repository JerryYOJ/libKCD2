#pragma once
#include <cstddef>
#include <vector>
#include "conceptmodule/C_ConceptPath.h"
#include "conceptmodule/C_Node.h"
#include "conceptmodule/C_TypedArrayPortRef.h"
#include "conceptmodule/C_TypedPortRef.h"
#include "conceptmodule/S_Trigger.h"

namespace wh::conceptmodule::Haste {

class C_HasteTrigger : public C_Node {
public:
    C_HasteTrigger();                                      // 0x1806B32E8
    ~C_HasteTrigger() override;                            // [0] 0x1809682A0
    RTTR_ENABLE(C_Node)                                    // [5..7]
    void EnumerateNodeVariants(
        definition::NodeDefinitionSink sink,
        bool allVariants) override;                        // [27] 0x18268E63C

    C_TypedPortRef<bool> m_isActive;                       // +0x40 RTTR "IsActive", In
    C_TypedArrayPortRef<std::vector<CryStringT<char>>>
        m_consoleCommands;                                 // +0x80 RTTR "ConsoleCommands", In
    C_TypedArrayPortRef<std::vector<C_ConceptPath>>
        m_prerequisites;                                   // +0xC0 RTTR "Prerequisites", In
    C_TypedPortRef<S_Trigger> m_onTrigger;                 // +0x100 RTTR "OnTrigger", Out
    C_TypedPortRef<bool> m_isHidden;                       // +0x140 RTTR "IsHidden", In
};

static_assert(offsetof(C_HasteTrigger, m_isActive) == 0x40,
              "C_HasteTrigger::m_isActive offset mismatch");
static_assert(offsetof(C_HasteTrigger, m_consoleCommands) == 0x80,
              "C_HasteTrigger::m_consoleCommands offset mismatch");
static_assert(offsetof(C_HasteTrigger, m_prerequisites) == 0xC0,
              "C_HasteTrigger::m_prerequisites offset mismatch");
static_assert(offsetof(C_HasteTrigger, m_onTrigger) == 0x100,
              "C_HasteTrigger::m_onTrigger offset mismatch");
static_assert(offsetof(C_HasteTrigger, m_isHidden) == 0x140,
              "C_HasteTrigger::m_isHidden offset mismatch");
static_assert(sizeof(C_HasteTrigger) == 0x180,
              "C_HasteTrigger size mismatch");

}  // namespace wh::conceptmodule::Haste
