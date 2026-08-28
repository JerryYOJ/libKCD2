#pragma once
#include <cstddef>
#include <cstdint>
#include "../framework/C_LocalizedString.h"
#include "../rpgmodule/E_RandomEventOption.h"
#include "S_RandomEventOptionResultAction.h"

namespace wh::playermodule {

struct S_RandomEventOption {
    S_RandomEventOption();
    ~S_RandomEventOption();

    CryStringT<char> m_name;                                  // +0x00
    wh::rpgmodule::E_RandomEventOption::Type m_chanceFormula; // +0x08
    std::uint8_t m_padding09[7];                              // +0x09
    CryStringT<char> m_tagPoint;                              // +0x10
    wh::framework::C_LocalizedString m_label;                 // +0x18
    S_RandomEventOptionResultAction m_successAction;          // +0x28
    S_RandomEventOptionResultAction m_failAction;             // +0x58
};

static_assert(offsetof(S_RandomEventOption, m_chanceFormula) == 0x08,
              "S_RandomEventOption chance-formula offset mismatch");
static_assert(offsetof(S_RandomEventOption, m_tagPoint) == 0x10,
              "S_RandomEventOption tag-point offset mismatch");
static_assert(offsetof(S_RandomEventOption, m_label) == 0x18,
              "S_RandomEventOption label offset mismatch");
static_assert(offsetof(S_RandomEventOption, m_successAction) == 0x28,
              "S_RandomEventOption success-action offset mismatch");
static_assert(offsetof(S_RandomEventOption, m_failAction) == 0x58,
              "S_RandomEventOption fail-action offset mismatch");
static_assert(sizeof(S_RandomEventOption) == 0x88,
              "S_RandomEventOption size mismatch");

} // namespace wh::playermodule
