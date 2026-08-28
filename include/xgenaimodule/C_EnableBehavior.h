#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "C_SmartEntity.h"
#include "I_InjectionExternalDataProvider.h"

namespace wh::rpgmodule {
class I_Soul;
}

namespace wh::xgenaimodule {

class C_EnableBehavior
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>,
      public I_InjectionExternalDataProvider {
public:
    ~C_EnableBehavior() override;
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<
        wh::conceptmodule::C_Effect>)                                        // [5..7], vtable 0x183BC0A38
    void OnEffectActivate() override;                                        // [43] 0x180BD6B84
    void OnEffectDeactivate() override;                                      // [44] 0x180BD65C0
    void IedpVf0() override;                                                 // +0xB0 [0] 0x180BD8C4C
    void IedpVf1() override;                                                 // +0xB0 [1] 0x180618E90
    void IedpVf2() override;                                                 // +0xB0 [2] 0x183235540

    wh::conceptmodule::C_TypedPortRef<CryStringT<char>> m_behavior;          // +0xB8 RTTR "Behavior"
    wh::conceptmodule::C_TypedPortRef<C_SmartEntity*> m_smartEntity;         // +0xF8 RTTR "SmartEntity"
    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<wh::rpgmodule::I_Soul*>> m_npc;                          // +0x138 RTTR "NPC"
    wh::conceptmodule::C_TypedPortRef<bool> m_forceKick;                     // +0x178 RTTR "ForceKick"
    std::uint8_t m_unknown1B8[0x50];                                         // +0x1B8 accessor EventSet/Signature
};

static_assert(offsetof(C_EnableBehavior, m_behavior) == 0xB8,
              "C_EnableBehavior::m_behavior offset mismatch");
static_assert(offsetof(C_EnableBehavior, m_forceKick) == 0x178,
              "C_EnableBehavior::m_forceKick offset mismatch");
static_assert(sizeof(C_EnableBehavior) == 0x208,
              "C_EnableBehavior size mismatch");

} // namespace wh::xgenaimodule
