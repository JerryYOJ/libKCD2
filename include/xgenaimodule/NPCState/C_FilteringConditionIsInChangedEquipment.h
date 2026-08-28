#pragma once
#include <cstddef>
#include <cstdint>
#include "../E_HandType.h"
#include "C_FilteringConditionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_FilteringConditionIsInChangedEquipment : public C_FilteringConditionBase {
public:
    ~C_FilteringConditionIsInChangedEquipment() override;
    RTTR_ENABLE(C_FilteringConditionBase)
    bool unk_07() override;
    bool unk_08() override;
    wh::xgenaimodule::E_HandType::Type m_hand;            // +0x10 RTTR "Hand"
    std::uint8_t _pad14[4];                               // +0x14
};

static_assert(offsetof(C_FilteringConditionIsInChangedEquipment, m_hand) == 0x10,
              "C_FilteringConditionIsInChangedEquipment::m_hand offset mismatch");
static_assert(sizeof(C_FilteringConditionIsInChangedEquipment) == 0x18,
              "C_FilteringConditionIsInChangedEquipment size mismatch");

}  // namespace wh::xgenaimodule::NPCState
