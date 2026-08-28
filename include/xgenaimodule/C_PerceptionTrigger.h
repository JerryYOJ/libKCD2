#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"

namespace wh::rpgmodule {
class I_Soul;
}

namespace wh::xgenaimodule {

class C_PerceptionTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect> {
public:
    ~C_PerceptionTrigger() override;                                         // [0] 0x1809676DC
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<
        wh::conceptmodule::C_Effect>)                                        // [5..7], vtable 0x183A71FA0
    void OnEffectActivate() override;                                        // [43] 0x180CC1F74
    void OnEffectDeactivate() override;                                      // [44] 0x180F66A64

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<wh::rpgmodule::I_Soul*>> m_perceivingSouls;              // +0xB0 RTTR "PerceivingSouls"
    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<wh::rpgmodule::I_Soul*>> m_perceptibleSouls;             // +0xF0 RTTR "PerceptibleSouls"
    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<CryStringT<char>>> m_perceptibleVolumeLabels;            // +0x130 RTTR "PerceptibleVolumeLabels"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onSeenShortCone;                     // +0x170 RTTR "OnSeenShortCone"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAllSeenShortCone;                  // +0x1B0 RTTR "OnAllSeenShortCone"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onSeenLongCone;                      // +0x1F0 RTTR "OnSeenLongCone"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAllSeenLongCone;                   // +0x230 RTTR "OnAllSeenLongCone"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onUnseen;                            // +0x270 RTTR "OnUnseen"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAllUnseen;                         // +0x2B0 RTTR "OnAllUnseen"
    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::I_Soul*> m_perceivingSoul;                            // +0x2F0 RTTR "PerceivingSoul"
    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::I_Soul*> m_perceptibleSoul;                           // +0x330 RTTR "PerceptibleSoul"
    std::uint8_t m_unknown370[0x40];                                         // +0x370
};

static_assert(offsetof(C_PerceptionTrigger, m_perceivingSouls) == 0xB0,
              "C_PerceptionTrigger::m_perceivingSouls offset mismatch");
static_assert(offsetof(C_PerceptionTrigger, m_perceptibleSoul) == 0x330,
              "C_PerceptionTrigger::m_perceptibleSoul offset mismatch");
static_assert(sizeof(C_PerceptionTrigger) == 0x3B0,
              "C_PerceptionTrigger size mismatch");

} // namespace wh::xgenaimodule
