#pragma once
#include <cstddef>
#include <cstdint>
#include "C_FilteringConditionHandContentBase.h"

namespace wh::xgenaimodule::NPCState {

class C_FilteringConditionRequiresOtherHandEmpty : public C_FilteringConditionHandContentBase {
public:
    ~C_FilteringConditionRequiresOtherHandEmpty() override;
    RTTR_ENABLE(C_FilteringConditionHandContentBase)
    bool unk_09() override;
    bool m_isPicking;                                     // +0x18 RTTR "IsPicking"
    std::uint8_t _pad19[7];                               // +0x19
};

static_assert(offsetof(C_FilteringConditionRequiresOtherHandEmpty, m_isPicking) == 0x18,
              "C_FilteringConditionRequiresOtherHandEmpty::m_isPicking offset mismatch");
static_assert(sizeof(C_FilteringConditionRequiresOtherHandEmpty) == 0x20,
              "C_FilteringConditionRequiresOtherHandEmpty size mismatch");

}  // namespace wh::xgenaimodule::NPCState
