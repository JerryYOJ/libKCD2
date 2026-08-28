#pragma once

#include <cstddef>
#include <cstdint>

#include "C_AnimActionBase.h"
#include "E_DataSource.h"

namespace wh::xgenaimodule::NPCState {

class C_StashManipulationAction : public C_AnimActionBase {
public:
    ~C_StashManipulationAction() override;
    RTTR_ENABLE(C_AnimActionBase)                                            // [24..26], vtable 0x183A47CE0

    E_DataSource m_dataSource;                                               // +0x1A0 RTTR "DataSource"
    std::uint8_t m_padding1A4[0xC];                                          // +0x1A4
};

static_assert(offsetof(C_StashManipulationAction, m_dataSource) == 0x1A0,
              "C_StashManipulationAction::m_dataSource offset mismatch");
static_assert(sizeof(C_StashManipulationAction) == 0x1B0,
              "C_StashManipulationAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
