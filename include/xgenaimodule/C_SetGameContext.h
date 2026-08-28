#pragma once

#include <cstddef>

#include "C_ScriptContextBaseEffect.h"
#include "S_GameScriptContext.h"

namespace wh::xgenaimodule {

class C_SetGameContext
    : public C_ScriptContextBaseEffect<S_GameScriptContext> {
public:
    C_SetGameContext();                                                      // 0x1811563D4
    ~C_SetGameContext() override;                                            // [0] 0x181406ED4
    RTTR_ENABLE(C_ScriptContextBaseEffect<S_GameScriptContext>)              // [5..7], vtable 0x183FDCAC0
    void unk_47(bool enabled, void* context) override;                       // [47] 0x180C96AB0
};

static_assert(sizeof(C_SetGameContext) == 0xD8,
              "C_SetGameContext size mismatch");

} // namespace wh::xgenaimodule
