#pragma once
#include <cstddef>
#include <cstdint>
#include "../../CryEngine/CryCommon/CryString.h"
#include "../../rttr/rttr_enable.h"
#include "I_Operator.h"

namespace wh::rpgmodule::storm {

class C_AddScheduleItemOperator : public I_Operator {
public:
    ~C_AddScheduleItemOperator() override;
    void unk_01(C_Soul* soul, C_Rule* rule) override;
    bool unk_02() override;
    E_TaskClass unk_03() override;
    void DebugDraw(wh::C_DebugDraw& draw) const override;
    RTTR_ENABLE(I_Operator)
    std::uint8_t m_unknown08[8];                          // +0x08 start/scatter accessors
    CryStringT<char> m_activity;                          // +0x10 RTTR "activity"
    std::uint8_t m_unknown18[8];                          // +0x18
};

static_assert(offsetof(C_AddScheduleItemOperator, m_activity) == 0x10,
              "C_AddScheduleItemOperator::m_activity offset mismatch");
static_assert(sizeof(C_AddScheduleItemOperator) == 0x20,
              "C_AddScheduleItemOperator size mismatch");

}  // namespace wh::rpgmodule::storm
