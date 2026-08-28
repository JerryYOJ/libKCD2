#pragma once
#include <cstddef>
#include <cstdint>
#include "E_DataSource.h"
#include "I_FilteringCondition.h"

namespace wh::xgenaimodule::NPCState {

class C_FilteringConditionBase : public I_FilteringCondition {
public:
    ~C_FilteringConditionBase() override;                 // [0] 0x18336C1B4
    bool unk_02() override;                               // [2] 0x1808F2174 calls [7], honors Negate
    bool unk_03() override;                               // [3] 0x1807597E4 calls [8], honors Negate
    RTTR_ENABLE(I_FilteringCondition)                     // [4..6]
    virtual bool unk_07() = 0;                            // [7] vtable+0x38
    virtual bool unk_08() = 0;                            // [8] vtable+0x40
    E_DataSource m_dataSource;                            // +0x08 RTTR "DataSource"
    bool m_negate;                                        // +0x0C RTTR "Negate"
    std::uint8_t _pad0D[3];                               // +0x0D
};

static_assert(offsetof(C_FilteringConditionBase, m_dataSource) == 0x08,
              "C_FilteringConditionBase::m_dataSource offset mismatch");
static_assert(offsetof(C_FilteringConditionBase, m_negate) == 0x0C,
              "C_FilteringConditionBase::m_negate offset mismatch");
static_assert(sizeof(C_FilteringConditionBase) == 0x10,
              "C_FilteringConditionBase size mismatch");

}  // namespace wh::xgenaimodule::NPCState
