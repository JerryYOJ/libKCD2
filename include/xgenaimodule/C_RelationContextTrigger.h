#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "C_LinkableObject.h"
#include "C_ScriptContextBaseTrigger.h"
#include "S_RelationScriptContext.h"

namespace wh::xgenaimodule {

class C_RelationContextTrigger
    : public C_ScriptContextBaseTrigger<S_RelationScriptContext> {
public:
    C_RelationContextTrigger();                                              // 0x1811314F8
    ~C_RelationContextTrigger() override;
    RTTR_ENABLE(C_ScriptContextBaseTrigger<S_RelationScriptContext>)         // [5..7], vtable 0x183A75EB8
    bool unk_47() override;                                                  // [47] 0x183282B74
    void unk_48() override;                                                  // [48] 0x183283180
    void unk_49() override;                                                  // [49] 0x183283CA8

    wh::conceptmodule::C_TypedArrayPortRef<C_LinkableObject*> m_from;        // +0x188 RTTR "From"
    wh::conceptmodule::C_TypedArrayPortRef<C_LinkableObject*> m_to;          // +0x1C8 RTTR "To"
    std::uint8_t m_unknown208[0x10];                                         // +0x208
};

static_assert(offsetof(C_RelationContextTrigger, m_from) == 0x188,
              "C_RelationContextTrigger::m_from offset mismatch");
static_assert(offsetof(C_RelationContextTrigger, m_to) == 0x1C8,
              "C_RelationContextTrigger::m_to offset mismatch");
static_assert(sizeof(C_RelationContextTrigger) == 0x218,
              "C_RelationContextTrigger size mismatch");

} // namespace wh::xgenaimodule
