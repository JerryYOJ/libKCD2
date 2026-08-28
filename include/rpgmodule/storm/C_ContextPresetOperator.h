#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"
#include "I_Operator.h"
#include "operation/Add.h"
#include "operation/Remove.h"

namespace wh::rpgmodule::storm {

template <typename TOp>
class C_ContextPresetOperator : public I_Operator {
public:
    ~C_ContextPresetOperator() override;
    void unk_01(C_Soul* soul, C_Rule* rule) override;
    bool unk_02() override;
    E_TaskClass unk_03() override;
    void DebugDraw(wh::C_DebugDraw& draw) const override;
    RTTR_ENABLE(I_Operator)
    std::uint8_t m_unknown08[0x10];                       // +0x08 name accessor
};

static_assert(sizeof(C_ContextPresetOperator<operation::Add>) == 0x18,
              "C_ContextPresetOperator<Add> size mismatch");
static_assert(sizeof(C_ContextPresetOperator<operation::Remove>) == 0x18,
              "C_ContextPresetOperator<Remove> size mismatch");

}  // namespace wh::rpgmodule::storm
