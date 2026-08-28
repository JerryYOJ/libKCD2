#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "C_ScriptContextBaseEffect.h"
#include "S_EntityScriptContext.h"

namespace wh::rpgmodule {
class I_Soul;
}

namespace wh::xgenaimodule {

class C_SetEntityContext
    : public C_ScriptContextBaseEffect<S_EntityScriptContext> {
public:
    C_SetEntityContext();                                                    // 0x18166403C
    ~C_SetEntityContext() override;
    RTTR_ENABLE(C_ScriptContextBaseEffect<S_EntityScriptContext>)            // [5..7], vtable 0x183A73738
    bool unk_46() override;                                                  // [46] 0x180C9A1FC
    void unk_47(bool enabled, void* context) override;                       // [47] 0x180C98D10
    void unk_48() override;                                                  // [48] 0x180C98CA4
    void unk_49() override;                                                  // [49] 0x180C989B0

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<wh::rpgmodule::I_Soul*>> m_souls;                        // +0xD8 RTTR "Souls"
    std::uint8_t m_unknown118[0x18];                                         // +0x118
};

static_assert(offsetof(C_SetEntityContext, m_souls) == 0xD8,
              "C_SetEntityContext::m_souls offset mismatch");
static_assert(sizeof(C_SetEntityContext) == 0x130,
              "C_SetEntityContext size mismatch");

} // namespace wh::xgenaimodule
