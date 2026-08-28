#pragma once

#include <cstddef>
#include <cstdint>

#include "C_CodeAction.h"
#include "E_DataSource.h"

namespace wh::xgenaimodule::NPCState {

class C_ChangeCrouchAction : public C_CodeAction {
public:
    ~C_ChangeCrouchAction() override;
    RTTR_ENABLE(C_CodeAction)                                                // [24..26], vtable 0x183B3ED28

    E_DataSource m_dataSource;                                               // +0xC0 RTTR "DataSource"
    std::uint8_t m_paddingC4[0xC];                                           // +0xC4
};

static_assert(offsetof(C_ChangeCrouchAction, m_dataSource) == 0xC0,
              "C_ChangeCrouchAction::m_dataSource offset mismatch");
static_assert(sizeof(C_ChangeCrouchAction) == 0xD0,
              "C_ChangeCrouchAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
