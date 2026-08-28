#pragma once
#include <cstddef>
#include <cstdint>
#include "C_FilteringConditionHandContentBase.h"

namespace wh::xgenaimodule::NPCState {

class C_FilteringConditionIsLightSource : public C_FilteringConditionHandContentBase {
public:
    ~C_FilteringConditionIsLightSource() override;
    RTTR_ENABLE(C_FilteringConditionHandContentBase)
    bool unk_09() override;
    bool m_requiresWeapon;                                // +0x18 RTTR "RequiresWeapon"
    std::uint8_t _pad19[7];                               // +0x19
};

static_assert(offsetof(C_FilteringConditionIsLightSource, m_requiresWeapon) == 0x18,
              "C_FilteringConditionIsLightSource::m_requiresWeapon offset mismatch");
static_assert(sizeof(C_FilteringConditionIsLightSource) == 0x20,
              "C_FilteringConditionIsLightSource size mismatch");

}  // namespace wh::xgenaimodule::NPCState
