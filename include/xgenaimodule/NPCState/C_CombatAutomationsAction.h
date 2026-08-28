#pragma once

#include <cstddef>
#include <cstdint>

#include "C_SuccessAction.h"
#include "E_DataSource.h"

namespace wh::xgenaimodule::NPCState {

class C_CombatAutomationsAction : public C_SuccessAction {
public:
    ~C_CombatAutomationsAction() override;
    RTTR_ENABLE(C_SuccessAction)                                             // [24..26], vtable 0x183B3F970

    E_DataSource m_dataSource;                                               // +0xC0 RTTR "DataSource"
    std::uint8_t m_paddingC4[4];                                             // +0xC4
};

static_assert(offsetof(C_CombatAutomationsAction, m_dataSource) == 0xC0,
              "C_CombatAutomationsAction::m_dataSource offset mismatch");
static_assert(sizeof(C_CombatAutomationsAction) == 0xC8,
              "C_CombatAutomationsAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
