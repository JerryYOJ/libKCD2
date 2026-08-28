#pragma once
#include <cstddef>
#include <cstdint>
#include <optional>
#include "../../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../E_HandType.h"
#include "C_FilteringConditionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_FilteringConditionItemSetAside : public C_FilteringConditionBase {
public:
    ~C_FilteringConditionItemSetAside() override;
    RTTR_ENABLE(C_FilteringConditionBase)
    bool unk_07() override;
    bool unk_08() override;
    std::optional<wh::xgenaimodule::E_HandType::Type> m_hand; // +0x10 RTTR "Hand"
    CryGUID m_itemClassId;                                // +0x18 RTTR "ItemClassId"
    CryStringT<char> m_slotManipulationTag;               // +0x28 RTTR "SlotManipulationTag"
};

static_assert(offsetof(C_FilteringConditionItemSetAside, m_hand) == 0x10,
              "C_FilteringConditionItemSetAside::m_hand offset mismatch");
static_assert(offsetof(C_FilteringConditionItemSetAside, m_itemClassId) == 0x18,
              "C_FilteringConditionItemSetAside::m_itemClassId offset mismatch");
static_assert(sizeof(C_FilteringConditionItemSetAside) == 0x30,
              "C_FilteringConditionItemSetAside size mismatch");

}  // namespace wh::xgenaimodule::NPCState
