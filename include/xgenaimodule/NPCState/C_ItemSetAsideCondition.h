#pragma once
#include <cstddef>
#include <cstdint>
#include <optional>
#include "../../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../E_HandType.h"
#include "I_Condition.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::C_ItemSetAsideCondition : I_Condition
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x28, 9-slot vtable.
// -----------------------------------------------

namespace wh::xgenaimodule::NPCState {

class C_ItemSetAsideCondition : public I_Condition {
public:
    ~C_ItemSetAsideCondition() override;
    I_Condition* unk_01() override;
    bool unk_02(void* arg) override;
    bool unk_03(void* arg) override;
    bool unk_04(void* arg) override;
    std::uint16_t unk_05() override;
    RTTR_ENABLE(I_Condition)
    wh::xgenaimodule::E_HandType::Type m_hand;            // +0x08 RTTR "Hand"
    bool m_requiresSetAside;                              // +0x0C RTTR "RequiresSetAside"
    std::uint8_t _pad0D[3];                               // +0x0D
    std::optional<CryGUID> m_itemClassId;                 // +0x10 RTTR "ItemClassId"
};

static_assert(offsetof(C_ItemSetAsideCondition, m_hand) == 0x08,
              "C_ItemSetAsideCondition::m_hand offset mismatch");
static_assert(offsetof(C_ItemSetAsideCondition, m_requiresSetAside) == 0x0C,
              "C_ItemSetAsideCondition::m_requiresSetAside offset mismatch");
static_assert(offsetof(C_ItemSetAsideCondition, m_itemClassId) == 0x10,
              "C_ItemSetAsideCondition::m_itemClassId offset mismatch");
static_assert(sizeof(std::optional<CryGUID>) == 0x18,
              "std::optional<CryGUID> size mismatch");
static_assert(sizeof(C_ItemSetAsideCondition) == 0x28,
              "C_ItemSetAsideCondition size mismatch");

}  // namespace wh::xgenaimodule::NPCState
