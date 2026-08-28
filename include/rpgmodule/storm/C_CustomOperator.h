#pragma once
#include <cstddef>
#include <memory>
#include <vector>
#include "../../CryEngine/CryCommon/CryString.h"
#include "../../rttr/rttr_enable.h"
#include "I_Operator.h"

namespace wh::rpgmodule::storm {

class C_CustomOperator : public I_Operator {
public:
    ~C_CustomOperator() override;
    void unk_01(C_Soul* soul, C_Rule* rule) override;
    bool unk_02() override;
    E_TaskClass unk_03() override;
    void DebugDraw(wh::C_DebugDraw& draw) const override;
    RTTR_ENABLE(I_Operator)
    std::vector<std::shared_ptr<I_Operator>> m_operations; // +0x08 RTTR "operations"
    CryStringT<char> m_name;                              // +0x20 RTTR "name"
};

static_assert(offsetof(C_CustomOperator, m_operations) == 0x08,
              "C_CustomOperator::m_operations offset mismatch");
static_assert(offsetof(C_CustomOperator, m_name) == 0x20,
              "C_CustomOperator::m_name offset mismatch");
static_assert(sizeof(C_CustomOperator) == 0x28,
              "C_CustomOperator size mismatch");

}  // namespace wh::rpgmodule::storm
