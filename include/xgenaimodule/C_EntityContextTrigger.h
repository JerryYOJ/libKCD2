#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "C_ScriptContextBaseTrigger.h"
#include "S_EntityScriptContext.h"

namespace wh::rpgmodule {
class I_Soul;
}

namespace wh::xgenaimodule {

class C_EntityContextTrigger
    : public C_ScriptContextBaseTrigger<S_EntityScriptContext> {
public:
    C_EntityContextTrigger();                                                // 0x18109C8E8
    ~C_EntityContextTrigger() override;                                      // [0] 0x180967CF4
    RTTR_ENABLE(C_ScriptContextBaseTrigger<S_EntityScriptContext>)           // [5..7], vtable 0x183A72DB0
    bool unk_47() override;                                                  // [47] 0x180C9879C
    void unk_48() override;                                                  // [48] 0x180C986D8
    void unk_49() override;                                                  // [49] 0x180C96CDC

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<wh::rpgmodule::I_Soul*>> m_souls;                        // +0x188 RTTR "Souls"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAllContextAdded;                   // +0x1C8 RTTR "OnAllContextAdded"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAllContextRemoved;                 // +0x208 RTTR "OnAllContextRemoved"
    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::I_Soul*> m_soul;                                      // +0x248 RTTR "Soul"
    std::uint8_t m_unknown288[0x18];                                         // +0x288
};

static_assert(offsetof(C_EntityContextTrigger, m_souls) == 0x188,
              "C_EntityContextTrigger::m_souls offset mismatch");
static_assert(offsetof(C_EntityContextTrigger, m_onAllContextAdded) == 0x1C8,
              "C_EntityContextTrigger::m_onAllContextAdded offset mismatch");
static_assert(offsetof(C_EntityContextTrigger, m_onAllContextRemoved) == 0x208,
              "C_EntityContextTrigger::m_onAllContextRemoved offset mismatch");
static_assert(offsetof(C_EntityContextTrigger, m_soul) == 0x248,
              "C_EntityContextTrigger::m_soul offset mismatch");
static_assert(sizeof(C_EntityContextTrigger) == 0x2A0,
              "C_EntityContextTrigger size mismatch");

} // namespace wh::xgenaimodule
