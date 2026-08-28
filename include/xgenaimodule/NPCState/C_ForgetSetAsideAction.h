#pragma once

#include <cstddef>
#include <cstdint>

#include "../E_HandType.h"
#include "C_CodeAction.h"

namespace wh::xgenaimodule::NPCState {

class C_ForgetSetAsideAction : public C_CodeAction {
public:
    ~C_ForgetSetAsideAction() override;
    RTTR_ENABLE(C_CodeAction)                                                // [24..26], vtable 0x183B3EE70

    wh::xgenaimodule::E_HandType::Type m_hand;                               // +0xC0 RTTR "Hand"
    std::uint8_t m_paddingC4[4];                                             // +0xC4
};

static_assert(offsetof(C_ForgetSetAsideAction, m_hand) == 0xC0,
              "C_ForgetSetAsideAction::m_hand offset mismatch");
static_assert(sizeof(C_ForgetSetAsideAction) == 0xC8,
              "C_ForgetSetAsideAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
