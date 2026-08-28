#pragma once

#include <cstddef>
#include <cstdint>

#include "../E_HandType.h"
#include "C_CodeAction.h"

namespace wh::xgenaimodule::NPCState {

class C_ReturnDroppedQuestItemAction : public C_CodeAction {
public:
    ~C_ReturnDroppedQuestItemAction() override;
    RTTR_ENABLE(C_CodeAction)                                                // [24..26], vtable 0x183FFD7F8

    wh::xgenaimodule::E_HandType::Type m_hand;                               // +0xC0 RTTR "Hand"
    std::uint8_t m_paddingC4[0xC];                                           // +0xC4
};

static_assert(offsetof(C_ReturnDroppedQuestItemAction, m_hand) == 0xC0,
              "C_ReturnDroppedQuestItemAction::m_hand offset mismatch");
static_assert(sizeof(C_ReturnDroppedQuestItemAction) == 0xD0,
              "C_ReturnDroppedQuestItemAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
