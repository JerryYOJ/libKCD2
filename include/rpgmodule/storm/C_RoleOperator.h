#pragma once
#include <cstddef>
#include "../S_RoleId.h"
#include "../../rttr/rttr_enable.h"
#include "I_Operator.h"
#include "operation/Add.h"
#include "operation/Remove.h"

namespace wh::rpgmodule::storm {

template <typename TOp>
class C_RoleOperator : public I_Operator {
public:
    ~C_RoleOperator() override;
    void unk_01(C_Soul* soul, C_Rule* rule) override;
    bool unk_02() override;
    E_TaskClass unk_03() override;
    void DebugDraw(wh::C_DebugDraw& draw) const override;
    RTTR_ENABLE(I_Operator)
    wh::rpgmodule::S_RoleId m_name;                       // +0x08 RTTR "name"
};

static_assert(offsetof(C_RoleOperator<operation::Add>, m_name) == 0x08,
              "C_RoleOperator::m_name offset mismatch");
static_assert(sizeof(C_RoleOperator<operation::Add>) == 0x10,
              "C_RoleOperator<Add> size mismatch");
static_assert(sizeof(C_RoleOperator<operation::Remove>) == 0x10,
              "C_RoleOperator<Remove> size mismatch");

}  // namespace wh::rpgmodule::storm
