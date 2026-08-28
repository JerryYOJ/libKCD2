#pragma once
#include <cstddef>
#include <cstdint>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "S_EntityScriptContextPreset.h"
#include "S_GameScriptContextPreset.h"
#include "S_RelationScriptContextPreset.h"

namespace wh::xgenaimodule {

template <typename TPreset>
class C_ScriptContextPresetBaseEffect : public wh::conceptmodule::C_Effect {
public:
    ~C_ScriptContextPresetBaseEffect() override;
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                    // [5..7]
    void OnEffectActivate() override;                           // [43]
    void OnEffectDeactivate() override;                         // [44]

    virtual bool unk_46();                                     // [46], true by default
    virtual void unk_47(bool enabled, void* context) = 0;       // [47], apply/remove resolved preset
    virtual void unk_48();                                     // [48], pre-apply hook
    virtual void unk_49();                                     // [49], pre-remove hook

    wh::conceptmodule::C_TypedPortRef<TPreset> m_preset;        // +0x88
    void* m_contextEntry;                                      // +0xC8, borrowed database entry
    bool m_contextApplied;                                     // +0xD0
    std::uint8_t m_paddingD1[7];                               // +0xD1
};

static_assert(offsetof(
                  C_ScriptContextPresetBaseEffect<S_EntityScriptContextPreset>,
                  m_preset) == 0x88,
              "C_ScriptContextPresetBaseEffect::m_preset offset mismatch");
static_assert(offsetof(
                  C_ScriptContextPresetBaseEffect<S_EntityScriptContextPreset>,
                  m_contextEntry) == 0xC8,
              "C_ScriptContextPresetBaseEffect::m_contextEntry offset mismatch");
static_assert(
    sizeof(C_ScriptContextPresetBaseEffect<S_EntityScriptContextPreset>) == 0xD8,
    "entity script-context preset effect size mismatch");
static_assert(
    sizeof(C_ScriptContextPresetBaseEffect<S_GameScriptContextPreset>) == 0xD8,
    "game script-context preset effect size mismatch");
static_assert(
    sizeof(C_ScriptContextPresetBaseEffect<S_RelationScriptContextPreset>) ==
        0xD8,
    "relation script-context preset effect size mismatch");

}  // namespace wh::xgenaimodule
