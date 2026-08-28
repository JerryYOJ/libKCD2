#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"

namespace wh::xgenaimodule {

class C_SchedulerLinkActivation : public wh::conceptmodule::C_Effect {
public:
    C_SchedulerLinkActivation();                                             // 0x1811AFCA4
    ~C_SchedulerLinkActivation() override;
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                                 // [5..7], vtable 0x183AEB7F0
    void OnEffectActivate() override;                                        // [43] 0x180BD7010
    void OnEffectDeactivate() override;                                      // [44] 0x180F807D0

    wh::conceptmodule::C_TypedPortRef<CryStringT<char>> m_linkTag;           // +0x88 RTTR "LinkTag"
    std::uint8_t m_unknownC8[8];                                             // +0xC8
};

static_assert(offsetof(C_SchedulerLinkActivation, m_linkTag) == 0x88,
              "C_SchedulerLinkActivation::m_linkTag offset mismatch");
static_assert(sizeof(C_SchedulerLinkActivation) == 0xD0,
              "C_SchedulerLinkActivation size mismatch");

} // namespace wh::xgenaimodule
