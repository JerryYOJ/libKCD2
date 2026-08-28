#pragma once

#include <cstddef>
#include <cstdint>

#include "../../entitymodule/E_StanceCategory.h"
#include "C_CodeAction.h"
#include "E_DataSource.h"

namespace wh::xgenaimodule::NPCState {

class C_UseMinigameAction : public C_CodeAction {
public:
    ~C_UseMinigameAction() override;
    RTTR_ENABLE(C_CodeAction)                                                // [24..26], vtable 0x183C0CAE0

    wh::entitymodule::E_StanceCategory::Type m_fromStance;                   // +0xC0 RTTR "FromStance"
    E_DataSource m_dataSource;                                               // +0xC4 RTTR "DataSource"
    std::uint8_t m_unknownC8[0x20];                                          // +0xC8
};

static_assert(offsetof(C_UseMinigameAction, m_fromStance) == 0xC0,
              "C_UseMinigameAction::m_fromStance offset mismatch");
static_assert(offsetof(C_UseMinigameAction, m_dataSource) == 0xC4,
              "C_UseMinigameAction::m_dataSource offset mismatch");
static_assert(sizeof(C_UseMinigameAction) == 0xE8,
              "C_UseMinigameAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
