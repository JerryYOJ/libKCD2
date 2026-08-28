#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../framework/C_LocalizedString.h"
#include "E_RandomEventOptionAction.h"

namespace wh::playermodule {

struct S_RandomEventOptionResultAction {
    wh::framework::C_LocalizedString m_message;             // +0x00 RTTR "Message"
    E_RandomEventOptionAction::Type m_action;               // +0x10 RTTR "Action"
    std::uint8_t _pad11[7];                                 // +0x11
    std::vector<E_RandomEventOptionAction::Type> m_additionalActions; // +0x18 accessor backing "AdditionalActions"
};

static_assert(offsetof(S_RandomEventOptionResultAction, m_message) == 0x00,
              "S_RandomEventOptionResultAction::m_message offset mismatch");
static_assert(offsetof(S_RandomEventOptionResultAction, m_action) == 0x10,
              "S_RandomEventOptionResultAction::m_action offset mismatch");
static_assert(offsetof(S_RandomEventOptionResultAction, m_additionalActions) == 0x18,
              "S_RandomEventOptionResultAction::m_additionalActions offset mismatch");
static_assert(sizeof(S_RandomEventOptionResultAction) == 0x30,
              "S_RandomEventOptionResultAction size mismatch");

}  // namespace wh::playermodule
