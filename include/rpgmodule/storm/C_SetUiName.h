#pragma once
#include <cstddef>
#include "../../CryEngine/CryCommon/CryString.h"
#include "../../rttr/rttr_enable.h"
#include "I_Operator.h"

namespace wh::rpgmodule::storm {

class C_SetUiName : public I_Operator {
public:
    ~C_SetUiName() override;
    void unk_01(C_Soul* soul, C_Rule* rule) override;
    bool unk_02() override;
    E_TaskClass unk_03() override;
    void DebugDraw(wh::C_DebugDraw& draw) const override;
    RTTR_ENABLE(I_Operator)
    CryStringT<char> m_name;                              // +0x08 RTTR "name"
};

static_assert(sizeof(C_SetUiName) == 0x10, "C_SetUiName size mismatch");

}  // namespace wh::rpgmodule::storm
