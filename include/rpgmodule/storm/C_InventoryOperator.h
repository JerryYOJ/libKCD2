#pragma once
#include <cstddef>
#include "../../CryEngine/CryCommon/CryString.h"
#include "../../rttr/rttr_enable.h"
#include "I_Operator.h"

namespace wh::rpgmodule::storm {

class C_InventoryOperator : public I_Operator {
public:
    ~C_InventoryOperator() override;
    void unk_01(C_Soul* soul, C_Rule* rule) override;
    bool unk_02() override;
    E_TaskClass unk_03() override;
    void DebugDraw(wh::C_DebugDraw& draw) const override;
    RTTR_ENABLE(I_Operator)
    virtual void unk_08(C_Soul* soul, C_Rule* rule) = 0;  // [8] 9-slot vtable
    CryStringT<char> m_preset;                            // +0x08 RTTR "preset"
};

static_assert(offsetof(C_InventoryOperator, m_preset) == 0x08,
              "C_InventoryOperator::m_preset offset mismatch");
static_assert(sizeof(C_InventoryOperator) == 0x10,
              "C_InventoryOperator size mismatch");

}  // namespace wh::rpgmodule::storm
