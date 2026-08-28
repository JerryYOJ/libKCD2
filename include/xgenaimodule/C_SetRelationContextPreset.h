#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_TypedPortRef.h"
#include "C_LinkableObject.h"
#include "C_ScriptContextPresetBaseEffect.h"
#include "S_RelationScriptContextPreset.h"

namespace wh::xgenaimodule {

class C_SetRelationContextPreset
    : public C_ScriptContextPresetBaseEffect<S_RelationScriptContextPreset> {
public:
    C_SetRelationContextPreset();                                            // 0x180EC0220
    ~C_SetRelationContextPreset() override;
    RTTR_ENABLE(C_ScriptContextPresetBaseEffect<
        S_RelationScriptContextPreset>)                                      // [5..7], vtable 0x183B864D8
    bool unk_46() override;                                                  // [46] 0x183234984
    void unk_47(bool enabled, void* context) override;                       // [47] 0x1832354B4
    void unk_48() override;                                                  // [48] 0x1832332BC
    void unk_49() override;                                                  // [49] 0x1832332FC

    wh::conceptmodule::C_TypedPortRef<C_LinkableObject*> m_from;             // +0xD8 RTTR "From"
    wh::conceptmodule::C_TypedPortRef<C_LinkableObject*> m_to;               // +0x118 RTTR "To"
    std::uint8_t m_unknown158[0x10];                                         // +0x158
};

static_assert(offsetof(C_SetRelationContextPreset, m_from) == 0xD8,
              "C_SetRelationContextPreset::m_from offset mismatch");
static_assert(offsetof(C_SetRelationContextPreset, m_to) == 0x118,
              "C_SetRelationContextPreset::m_to offset mismatch");
static_assert(sizeof(C_SetRelationContextPreset) == 0x168,
              "C_SetRelationContextPreset size mismatch");

} // namespace wh::xgenaimodule
