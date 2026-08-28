#pragma once

#include <cstddef>
#include <cstdint>

#include "../../entitymodule/E_StanceCategory.h"
#include "C_AnimActionBase.h"
#include "E_DataSource.h"

namespace wh::xgenaimodule::NPCState {

class C_ChangeStanceAction : public C_AnimActionBase {
public:
    ~C_ChangeStanceAction() override;
    RTTR_ENABLE(C_AnimActionBase)                                            // [24..26], vtable 0x183FF79E0

    E_DataSource m_dataSource;                                               // +0x1A0 RTTR "DataSource"
    wh::entitymodule::E_StanceCategory::Type m_fromStance;                   // +0x1A4 RTTR "FromStance"
    wh::entitymodule::E_StanceCategory::Type m_toStance;                     // +0x1A8 RTTR "ToStance"
    bool m_requiresEqualFromToObjects;                                       // +0x1AC RTTR "RequiresEqualFromToObjects"
    std::uint8_t m_unknown1AD[0x9B];                                         // +0x1AD
};

static_assert(offsetof(C_ChangeStanceAction, m_dataSource) == 0x1A0,
              "C_ChangeStanceAction::m_dataSource offset mismatch");
static_assert(offsetof(C_ChangeStanceAction, m_toStance) == 0x1A8,
              "C_ChangeStanceAction::m_toStance offset mismatch");
static_assert(sizeof(C_ChangeStanceAction) == 0x248,
              "C_ChangeStanceAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
