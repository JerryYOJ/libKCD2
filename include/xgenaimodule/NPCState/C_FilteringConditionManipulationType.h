#pragma once
#include <cstddef>
#include <cstdint>
#include "C_FilteringConditionHandContentBase.h"

namespace wh::xgenaimodule::NPCState {

class C_FilteringConditionManipulationType : public C_FilteringConditionHandContentBase {
public:
    ~C_FilteringConditionManipulationType() override;
    RTTR_ENABLE(C_FilteringConditionHandContentBase)
    bool unk_09() override;
    std::int32_t m_manipulationType;                      // +0x18 RTTR "ManipulationType"
    std::uint8_t _pad1C[4];                               // +0x1C
};

static_assert(offsetof(C_FilteringConditionManipulationType, m_manipulationType) == 0x18,
              "C_FilteringConditionManipulationType::m_manipulationType offset mismatch");
static_assert(sizeof(C_FilteringConditionManipulationType) == 0x20,
              "C_FilteringConditionManipulationType size mismatch");

}  // namespace wh::xgenaimodule::NPCState
