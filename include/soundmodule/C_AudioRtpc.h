#pragma once
#include <cstddef>
#include <cstdint>
#include "../conceptmodule/C_Effect.h"
#include "../xgenaimodule/C_LinkableObject.h"
#include "S_SkaldAtlRtpcId.h"

namespace wh::soundmodule {

class C_AudioRtpc : public wh::conceptmodule::C_Effect {
public:
    ~C_AudioRtpc() override;                                // [0] 0x1816EF540
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                   // [27] 0x182F04780
    void OnExecute(wh::conceptmodule::S_NodeExecuteContext const& ctx) override; // [33] 0x182F04354
    void OnEffectActivate() override;                        // [43] 0x182F049E8
    void OnEffectDeactivate() override;                      // [44] 0x182F049F8

    wh::conceptmodule::C_TypedPortRef<S_SkaldAtlRtpcId> m_atlRtpcName; // +0x88
    wh::conceptmodule::C_TypedPortRef<wh::xgenaimodule::C_LinkableObject*> m_linkableObject; // +0xC8
    wh::conceptmodule::C_TypedPortRef<float> m_valueActive;  // +0x108
    wh::conceptmodule::C_TypedPortRef<float> m_valueInactive;// +0x148
    bool m_propagateActiveValue;                             // +0x188 activation writer / OnExecute reader
    std::uint8_t m_unknown189[7];                           // +0x189 unreflected
};

static_assert(offsetof(C_AudioRtpc, m_atlRtpcName) == 0x88,
              "C_AudioRtpc::m_atlRtpcName offset mismatch");
static_assert(offsetof(C_AudioRtpc, m_linkableObject) == 0xC8,
              "C_AudioRtpc::m_linkableObject offset mismatch");
static_assert(offsetof(C_AudioRtpc, m_valueActive) == 0x108,
              "C_AudioRtpc::m_valueActive offset mismatch");
static_assert(offsetof(C_AudioRtpc, m_valueInactive) == 0x148,
              "C_AudioRtpc::m_valueInactive offset mismatch");
static_assert(offsetof(C_AudioRtpc, m_propagateActiveValue) == 0x188,
              "C_AudioRtpc::m_propagateActiveValue offset mismatch");
static_assert(sizeof(C_AudioRtpc) == 0x190,
              "C_AudioRtpc size mismatch");

}  // namespace wh::soundmodule
