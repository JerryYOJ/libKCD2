#pragma once

#include <cstddef>
#include <cstdint>

#include "C_ChangeUnstanceActionBase.h"
#include "E_DataSource.h"

namespace wh::xgenaimodule::NPCState {

class C_ChangeUnstanceAction : public C_ChangeUnstanceActionBase {
public:
    ~C_ChangeUnstanceAction() override;
    RTTR_ENABLE(C_ChangeUnstanceActionBase)                                  // [24..26], vtable 0x183A2E8A8

    E_DataSource m_dataSource;                                               // +0x1A8 RTTR "DataSource"
    std::uint8_t m_padding1AC[4];                                            // +0x1AC
    std::uint8_t m_unstance[0x68];                                           // +0x1B0 RTTR "Unstance" entitymodule::S_Unstance
};

static_assert(offsetof(C_ChangeUnstanceAction, m_dataSource) == 0x1A8,
              "C_ChangeUnstanceAction::m_dataSource offset mismatch");
static_assert(offsetof(C_ChangeUnstanceAction, m_unstance) == 0x1B0,
              "C_ChangeUnstanceAction::m_unstance offset mismatch");
static_assert(sizeof(C_ChangeUnstanceAction) == 0x218,
              "C_ChangeUnstanceAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
