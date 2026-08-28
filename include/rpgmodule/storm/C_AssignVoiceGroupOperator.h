#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"
#include "I_Operator.h"

namespace wh::rpgmodule::storm {

class C_AssignVoiceGroupOperator : public I_Operator {
public:
    ~C_AssignVoiceGroupOperator() override;
    void unk_01(C_Soul* soul, C_Rule* rule) override;
    bool unk_02() override;
    E_TaskClass unk_03() override;
    void DebugDraw(wh::C_DebugDraw& draw) const override;
    RTTR_ENABLE(I_Operator)
    std::uint8_t m_unknown08[8];                          // +0x08 name accessor
};

static_assert(sizeof(C_AssignVoiceGroupOperator) == 0x10,
              "C_AssignVoiceGroupOperator size mismatch");

}  // namespace wh::rpgmodule::storm
