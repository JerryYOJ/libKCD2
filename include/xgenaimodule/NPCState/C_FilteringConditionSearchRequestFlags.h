#pragma once
#include <cstddef>
#include <cstdint>
#include "C_FilteringConditionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_FilteringConditionSearchRequestFlags : public C_FilteringConditionBase {
public:
    ~C_FilteringConditionSearchRequestFlags() override;
    RTTR_ENABLE(C_FilteringConditionBase)
    bool unk_07() override;
    bool unk_08() override;
    std::uint8_t m_unknown10[8];                          // +0x10 RequiredFlags accessor
};

static_assert(sizeof(C_FilteringConditionSearchRequestFlags) == 0x18,
              "C_FilteringConditionSearchRequestFlags size mismatch");

}  // namespace wh::xgenaimodule::NPCState
