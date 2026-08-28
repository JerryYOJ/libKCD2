#pragma once

#include <cstddef>
#include <cstdint>

#include "../E_HandType.h"
#include "C_AnimActionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_ItemHandlingAction : public C_AnimActionBase {
public:
    ~C_ItemHandlingAction() override;
    RTTR_ENABLE(C_AnimActionBase)                                            // [24..26], vtable 0x183B5BBE8

    wh::xgenaimodule::E_HandType::Type m_hand;                               // +0x1A0 RTTR "Hand"
    std::uint8_t m_padding1A4[0x14];                                         // +0x1A4
};

static_assert(offsetof(C_ItemHandlingAction, m_hand) == 0x1A0,
              "C_ItemHandlingAction::m_hand offset mismatch");
static_assert(sizeof(C_ItemHandlingAction) == 0x1B8,
              "C_ItemHandlingAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
