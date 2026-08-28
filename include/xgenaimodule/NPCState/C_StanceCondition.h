#pragma once
#include <cstddef>
#include <cstdint>
#include "../../entitymodule/E_StanceCategory.h"
#include "E_DataSource.h"
#include "I_Condition.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::C_StanceCondition : I_Condition
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x20, 9-slot vtable.
// -----------------------------------------------

namespace wh::xgenaimodule::NPCState {

class C_StanceCondition : public I_Condition {
public:
    ~C_StanceCondition() override;
    I_Condition* unk_01() override;
    bool unk_02(void* arg) override;
    bool unk_03(void* arg) override;
    bool unk_04(void* arg) override;
    std::uint16_t unk_05() override;
    RTTR_ENABLE(I_Condition)
    wh::entitymodule::E_StanceCategory::Type m_requiredStance; // +0x08 RTTR "RequiredStance"
    E_DataSource m_dataSource;                            // +0x0C RTTR "DataSource"
    bool m_compareDataSourceObject;                       // +0x10 RTTR "CompareDataSourceObject"
    std::uint8_t _pad11[0xF];                             // +0x11
};

static_assert(offsetof(C_StanceCondition, m_requiredStance) == 0x08,
              "C_StanceCondition::m_requiredStance offset mismatch");
static_assert(offsetof(C_StanceCondition, m_dataSource) == 0x0C,
              "C_StanceCondition::m_dataSource offset mismatch");
static_assert(offsetof(C_StanceCondition, m_compareDataSourceObject) == 0x10,
              "C_StanceCondition::m_compareDataSourceObject offset mismatch");
static_assert(sizeof(C_StanceCondition) == 0x20,
              "C_StanceCondition size mismatch");

}  // namespace wh::xgenaimodule::NPCState
