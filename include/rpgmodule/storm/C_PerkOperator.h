#pragma once
#include <cstddef>
#include "../../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../../rttr/rttr_enable.h"
#include "I_Operator.h"
#include "operation/Add.h"
#include "operation/Remove.h"

namespace wh::rpgmodule::storm {

template <typename TOp>
class C_PerkOperator : public I_Operator {
public:
    ~C_PerkOperator() override;
    void unk_01(C_Soul* soul, C_Rule* rule) override;
    bool unk_02() override;
    E_TaskClass unk_03() override;
    void DebugDraw(wh::C_DebugDraw& draw) const override;
    RTTR_ENABLE(I_Operator)
    CryGUID m_id;                                         // +0x08 RTTR "ID"
};

static_assert(sizeof(C_PerkOperator<operation::Add>) == 0x18,
              "C_PerkOperator<Add> size mismatch");
static_assert(sizeof(C_PerkOperator<operation::Remove>) == 0x18,
              "C_PerkOperator<Remove> size mismatch");

}  // namespace wh::rpgmodule::storm
