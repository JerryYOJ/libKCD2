#pragma once
#include <cstddef>
#include <cstdint>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "../game/I_ContextChangeCallback.h"
#include "S_EntityScriptContext.h"
#include "S_GameScriptContext.h"
#include "S_RelationScriptContext.h"

namespace wh::xgenaimodule {

template <typename TContext>
class C_ScriptContextBaseTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>,
      public wh::game::I_ContextChangeCallback {
public:
    ~C_ScriptContextBaseTrigger() override;
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<
        wh::conceptmodule::C_Effect>)                          // [5..7]
    void OnEffectActivate() override;                           // [43]
    void OnEffectDeactivate() override;                         // [44]

    void OnContextAdded() override;                             // secondary [0], emit +0xF8
    void OnContextRemoved() override;                           // secondary [1], emit +0x138

    virtual bool unk_47() = 0;                                 // primary [47], context is active
    virtual void unk_48() = 0;                                 // primary [48], activate policy
    virtual void unk_49() = 0;                                 // primary [49], deactivate policy

    wh::conceptmodule::C_TypedPortRef<TContext> m_context;      // +0xB8
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onContextAdded;         // +0xF8
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onContextRemoved;       // +0x138
    void* m_contextEntry;                                      // +0x178, borrowed database entry
    bool m_contextActive;                                      // +0x180
    std::uint8_t m_padding181[7];                              // +0x181
};

static_assert(offsetof(
                  C_ScriptContextBaseTrigger<S_EntityScriptContext>, m_context) ==
                  0xB8,
              "C_ScriptContextBaseTrigger::m_context offset mismatch");
static_assert(offsetof(
                  C_ScriptContextBaseTrigger<S_EntityScriptContext>,
                  m_onContextAdded) == 0xF8,
              "C_ScriptContextBaseTrigger::m_onContextAdded offset mismatch");
static_assert(offsetof(
                  C_ScriptContextBaseTrigger<S_EntityScriptContext>,
                  m_onContextRemoved) == 0x138,
              "C_ScriptContextBaseTrigger::m_onContextRemoved offset mismatch");
static_assert(offsetof(
                  C_ScriptContextBaseTrigger<S_EntityScriptContext>,
                  m_contextEntry) == 0x178,
              "C_ScriptContextBaseTrigger::m_contextEntry offset mismatch");
static_assert(sizeof(C_ScriptContextBaseTrigger<S_EntityScriptContext>) == 0x188,
              "entity script-context trigger size mismatch");
static_assert(sizeof(C_ScriptContextBaseTrigger<S_GameScriptContext>) == 0x188,
              "game script-context trigger size mismatch");
static_assert(sizeof(C_ScriptContextBaseTrigger<S_RelationScriptContext>) == 0x188,
              "relation script-context trigger size mismatch");

}  // namespace wh::xgenaimodule
