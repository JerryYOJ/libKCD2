#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "C_ScriptContextPresetBaseEffect.h"
#include "S_EntityScriptContextPreset.h"

namespace wh::rpgmodule {
class I_Soul;
}

namespace wh::xgenaimodule {

class C_SetEntityContextPreset
    : public C_ScriptContextPresetBaseEffect<S_EntityScriptContextPreset> {
public:
    C_SetEntityContextPreset();                                              // 0x1810D1170
    ~C_SetEntityContextPreset() override;
    RTTR_ENABLE(C_ScriptContextPresetBaseEffect<
        S_EntityScriptContextPreset>)                                        // [5..7], vtable 0x183A72818
    bool unk_46() override;                                                  // [46] 0x180C9A1FC
    void unk_47(bool enabled, void* context) override;                       // [47] 0x1810433BC
    void unk_48() override;                                                  // [48] 0x1810438D0
    void unk_49() override;                                                  // [49] 0x181042E2C

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<wh::rpgmodule::I_Soul*>> m_souls;                        // +0xD8 RTTR "Souls"
    std::uint8_t m_unknown118[0x18];                                         // +0x118
};

static_assert(offsetof(C_SetEntityContextPreset, m_souls) == 0xD8,
              "C_SetEntityContextPreset::m_souls offset mismatch");
static_assert(sizeof(C_SetEntityContextPreset) == 0x130,
              "C_SetEntityContextPreset size mismatch");

} // namespace wh::xgenaimodule
