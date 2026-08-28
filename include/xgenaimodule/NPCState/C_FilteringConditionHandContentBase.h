#pragma once
#include <cstddef>
#include <cstdint>
#include "../E_HandType.h"
#include "C_FilteringConditionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_FilteringConditionHandContentBase : public C_FilteringConditionBase {
public:
    ~C_FilteringConditionHandContentBase() override;      // [0] 0x18138B4A0
    RTTR_ENABLE(C_FilteringConditionBase)                 // [4..6]
    bool unk_07() override;                               // [7] 0x1808F2198
    bool unk_08() override;                               // [8] 0x180759808
    virtual bool unk_09() = 0;                            // [9]
    wh::xgenaimodule::E_HandType::Type m_hand;            // +0x10 RTTR "Hand"
    std::uint8_t _pad14[4];                               // +0x14
};

static_assert(offsetof(C_FilteringConditionHandContentBase, m_hand) == 0x10,
              "C_FilteringConditionHandContentBase::m_hand offset mismatch");
static_assert(sizeof(C_FilteringConditionHandContentBase) == 0x18,
              "C_FilteringConditionHandContentBase size mismatch");

}  // namespace wh::xgenaimodule::NPCState
