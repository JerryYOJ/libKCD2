#pragma once

#include <cstddef>

#include "C_ScriptContextPresetBaseEffect.h"
#include "S_GameScriptContextPreset.h"

namespace wh::xgenaimodule {

class C_SetGameContextPreset
    : public C_ScriptContextPresetBaseEffect<S_GameScriptContextPreset> {
public:
    C_SetGameContextPreset();                                                // 0x18145636C
    ~C_SetGameContextPreset() override;
    RTTR_ENABLE(C_ScriptContextPresetBaseEffect<
        S_GameScriptContextPreset>)                                          // [5..7], vtable 0x183FDCC58
    void unk_47(bool enabled, void* context) override;                       // [47] 0x183235468
};

static_assert(sizeof(C_SetGameContextPreset) == 0xD8,
              "C_SetGameContextPreset size mismatch");

} // namespace wh::xgenaimodule
