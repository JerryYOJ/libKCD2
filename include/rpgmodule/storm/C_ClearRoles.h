#pragma once
#include <cstddef>
#include "../../rttr/rttr_enable.h"
#include "I_Operator.h"

namespace wh::rpgmodule::storm {

class C_ClearRoles : public I_Operator {
public:
    ~C_ClearRoles() override;
    void unk_01(C_Soul* soul, C_Rule* rule) override;
    bool unk_02() override;
    E_TaskClass unk_03() override;
    void DebugDraw(wh::C_DebugDraw& draw) const override;
    RTTR_ENABLE(I_Operator)
};

static_assert(sizeof(C_ClearRoles) == 0x08, "C_ClearRoles size mismatch");

}  // namespace wh::rpgmodule::storm
