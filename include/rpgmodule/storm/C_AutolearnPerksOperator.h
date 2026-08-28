#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"
#include "I_Operator.h"

namespace wh::rpgmodule::storm {

class C_AutolearnPerksOperator : public I_Operator {
public:
    ~C_AutolearnPerksOperator() override;
    void unk_01(C_Soul* soul, C_Rule* rule) override;
    bool unk_02() override;
    E_TaskClass unk_03() override;
    void DebugDraw(wh::C_DebugDraw& draw) const override;
    RTTR_ENABLE(I_Operator)
    float m_reliability;                                  // +0x08 RTTR "reliability"
    std::uint8_t _pad0C[4];                               // +0x0C
};

static_assert(offsetof(C_AutolearnPerksOperator, m_reliability) == 0x08,
              "C_AutolearnPerksOperator::m_reliability offset mismatch");
static_assert(sizeof(C_AutolearnPerksOperator) == 0x10,
              "C_AutolearnPerksOperator size mismatch");

}  // namespace wh::rpgmodule::storm
