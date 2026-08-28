#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_TypedPortRef.h"
#include "C_LinkableObject.h"
#include "C_ScriptContextBaseEffect.h"
#include "S_RelationScriptContext.h"

namespace wh::xgenaimodule {

class C_SetRelationContext
    : public C_ScriptContextBaseEffect<S_RelationScriptContext> {
public:
    C_SetRelationContext();                                                  // 0x181132914
    ~C_SetRelationContext() override;
    RTTR_ENABLE(C_ScriptContextBaseEffect<S_RelationScriptContext>)          // [5..7], vtable 0x183A75170
    bool unk_46() override;                                                  // [46] 0x1810451AC
    void unk_47(bool enabled, void* context) override;                       // [47] 0x1810451F8
    void unk_48() override;                                                  // [48] 0x18104516C
    void unk_49() override;                                                  // [49] 0x18104512C

    wh::conceptmodule::C_TypedPortRef<C_LinkableObject*> m_from;             // +0xD8 RTTR "From"
    wh::conceptmodule::C_TypedPortRef<C_LinkableObject*> m_to;               // +0x118 RTTR "To"
    std::uint8_t m_unknown158[0x10];                                         // +0x158
};

static_assert(offsetof(C_SetRelationContext, m_from) == 0xD8,
              "C_SetRelationContext::m_from offset mismatch");
static_assert(offsetof(C_SetRelationContext, m_to) == 0x118,
              "C_SetRelationContext::m_to offset mismatch");
static_assert(sizeof(C_SetRelationContext) == 0x168,
              "C_SetRelationContext size mismatch");

} // namespace wh::xgenaimodule
