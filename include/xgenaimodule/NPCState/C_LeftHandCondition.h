#pragma once

#include <cstddef>
#include <cstdint>

#include "C_HandContentConditionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_LeftHandCondition : public C_HandContentConditionBase {
public:
    C_LeftHandCondition();                                               // 0x1816612FC
    ~C_LeftHandCondition() override;                                     // [0]
    I_Condition* unk_01() override;
    std::uint16_t unk_05() override;
    std::uint32_t unk_09() override;
    void unk_10(void* out, void* arg) override;
    RTTR_ENABLE(C_HandContentConditionBase)                              // [6..8], vtable 0x183A44FB8

    bool m_allowMissingIfLightSource;                                    // +0x40 RTTR "AllowMissingIfLightSource"
    std::uint8_t m_padding41[7];                                         // +0x41
};

static_assert(offsetof(C_LeftHandCondition, m_allowMissingIfLightSource) == 0x40,
              "C_LeftHandCondition::m_allowMissingIfLightSource offset mismatch");
static_assert(sizeof(C_LeftHandCondition) == 0x48,
              "C_LeftHandCondition size mismatch");

} // namespace wh::xgenaimodule::NPCState
