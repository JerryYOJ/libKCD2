#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../framework/C_LocalizedString.h"

namespace wh::playermodule {

class C_DisableActionEffect : public wh::conceptmodule::C_Effect {
public:
    C_DisableActionEffect();
    ~C_DisableActionEffect() override;                           // [0] 0x18173A08C
    RTTR_ENABLE(wh::conceptmodule::C_Effect) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27] 0x182DE0014
    void OnEffectActivate() override;                           // [43] 0x182DE0FC4
    void OnEffectDeactivate() override;                         // [44] 0x182DE17B8

    wh::conceptmodule::C_TypedArrayPortRef<
        CryStringT<char>> m_actionMap;                          // +0x88
    wh::conceptmodule::C_TypedArrayPortRef<
        CryStringT<char>> m_action;                             // +0xC8
    wh::conceptmodule::C_TypedArrayPortRef<
        wh::framework::C_LocalizedString> m_disableReason;      // +0x108
    CryStringT<char> m_resolvedActionMap;                       // +0x148
    CryStringT<char> m_resolvedAction;                          // +0x150
    wh::framework::C_LocalizedString m_resolvedDisableReason;   // +0x158
    bool m_actionDisabled;                                      // +0x168
    bool m_reasonApplied;                                       // +0x169
    std::uint8_t m_padding16A[6];                              // +0x16A
};

static_assert(sizeof(C_DisableActionEffect) == 0x170,
              "C_DisableActionEffect size mismatch");
static_assert(offsetof(C_DisableActionEffect, m_actionMap) == 0x88,
              "C_DisableActionEffect action-map offset mismatch");
static_assert(offsetof(C_DisableActionEffect, m_resolvedActionMap) == 0x148,
              "C_DisableActionEffect resolved action-map offset mismatch");
static_assert(offsetof(C_DisableActionEffect, m_resolvedDisableReason) == 0x158,
              "C_DisableActionEffect resolved reason offset mismatch");
static_assert(offsetof(C_DisableActionEffect, m_actionDisabled) == 0x168,
              "C_DisableActionEffect state offset mismatch");

} // namespace wh::playermodule
