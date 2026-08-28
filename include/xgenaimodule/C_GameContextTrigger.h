#pragma once

#include <cstddef>

#include "C_ScriptContextBaseTrigger.h"
#include "S_GameScriptContext.h"

namespace wh::xgenaimodule {

class C_GameContextTrigger
    : public C_ScriptContextBaseTrigger<S_GameScriptContext> {
public:
    C_GameContextTrigger();                                                  // 0x181157264
    ~C_GameContextTrigger() override;                                        // [0] 0x1817304A4
    RTTR_ENABLE(C_ScriptContextBaseTrigger<S_GameScriptContext>)             // [5..7], vtable 0x183B41C10
    bool unk_47() override;                                                  // [47] 0x180C97530
    void unk_48() override;                                                  // [48] 0x180C97570
    void unk_49() override;                                                  // [49] 0x180C96A78
};

static_assert(sizeof(C_GameContextTrigger) == 0x188,
              "C_GameContextTrigger size mismatch");

} // namespace wh::xgenaimodule
