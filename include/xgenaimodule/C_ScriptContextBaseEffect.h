#pragma once
#include <cstddef>
#include <cstdint>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "S_EntityScriptContext.h"
#include "S_GameScriptContext.h"
#include "S_RelationScriptContext.h"

namespace wh::xgenaimodule {

template <typename TContext>
class C_ScriptContextBaseEffect : public wh::conceptmodule::C_Effect {
public:
    ~C_ScriptContextBaseEffect() override;
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                    // [5..7]
    void OnEffectActivate() override;                           // [43]
    void OnEffectDeactivate() override;                         // [44]

    virtual bool unk_46();                                     // [46], true by default
    virtual void unk_47(bool enabled, void* context) = 0;       // [47], apply/remove resolved context
    virtual void unk_48();                                     // [48], pre-apply hook
    virtual void unk_49();                                     // [49], pre-remove hook

    wh::conceptmodule::C_TypedPortRef<TContext> m_context;      // +0x88
    void* m_contextEntry;                                      // +0xC8, borrowed database entry
    bool m_contextApplied;                                     // +0xD0
    std::uint8_t m_paddingD1[7];                               // +0xD1
};

static_assert(offsetof(
                  C_ScriptContextBaseEffect<S_EntityScriptContext>, m_context) ==
                  0x88,
              "C_ScriptContextBaseEffect::m_context offset mismatch");
static_assert(offsetof(
                  C_ScriptContextBaseEffect<S_EntityScriptContext>,
                  m_contextEntry) == 0xC8,
              "C_ScriptContextBaseEffect::m_contextEntry offset mismatch");
static_assert(sizeof(C_ScriptContextBaseEffect<S_EntityScriptContext>) == 0xD8,
              "entity script-context effect size mismatch");
static_assert(sizeof(C_ScriptContextBaseEffect<S_GameScriptContext>) == 0xD8,
              "game script-context effect size mismatch");
static_assert(sizeof(C_ScriptContextBaseEffect<S_RelationScriptContext>) == 0xD8,
              "relation script-context effect size mismatch");

}  // namespace wh::xgenaimodule
