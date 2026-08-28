#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"

namespace wh::xgenaimodule {

class C_PerceptibleVolumeEffect : public wh::conceptmodule::C_Effect {
public:
    ~C_PerceptibleVolumeEffect() override;                                   // [0] 0x1815DDA0C
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                                 // [5..7], vtable 0x183AEA718
    void OnEffectActivate() override;                                        // [43] 0x1832346FC
    void OnEffectDeactivate() override;                                      // [44] 0x183234A28

    wh::conceptmodule::C_TypedPortRef<Vec3> m_position;                      // +0x88 RTTR "Position"
    wh::conceptmodule::C_TypedPortRef<CryStringT<char>> m_label;             // +0xC8 RTTR "Label"
    wh::conceptmodule::C_TypedPortRef<float> m_radius;                       // +0x108 RTTR "Radius"
    wh::conceptmodule::C_TypedPortRef<float> m_height;                       // +0x148 RTTR "Height"
    wh::conceptmodule::C_TypedPortRef<float> m_conspicuousness;              // +0x188 RTTR "Conspicuousness"
    wh::conceptmodule::C_TypedPortRef<float> m_visibility;                   // +0x1C8 RTTR "Visibility"
    std::uint8_t m_unknown208[8];                                            // +0x208
};

static_assert(offsetof(C_PerceptibleVolumeEffect, m_position) == 0x88,
              "C_PerceptibleVolumeEffect::m_position offset mismatch");
static_assert(offsetof(C_PerceptibleVolumeEffect, m_visibility) == 0x1C8,
              "C_PerceptibleVolumeEffect::m_visibility offset mismatch");
static_assert(sizeof(C_PerceptibleVolumeEffect) == 0x210,
              "C_PerceptibleVolumeEffect size mismatch");

} // namespace wh::xgenaimodule
