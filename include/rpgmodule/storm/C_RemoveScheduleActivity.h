#pragma once
#include <cstddef>
#include "../../CryEngine/CryCommon/CryString.h"
#include "../../rttr/rttr_enable.h"
#include "I_Operator.h"

namespace wh::rpgmodule::storm {

class C_RemoveScheduleActivity : public I_Operator {
public:
    ~C_RemoveScheduleActivity() override;
    void unk_01(C_Soul* soul, C_Rule* rule) override;
    bool unk_02() override;
    E_TaskClass unk_03() override;
    void DebugDraw(wh::C_DebugDraw& draw) const override;
    RTTR_ENABLE(I_Operator)
    CryStringT<char> m_activity;                          // +0x08 RTTR "activity"
};

static_assert(sizeof(C_RemoveScheduleActivity) == 0x10,
              "C_RemoveScheduleActivity size mismatch");

}  // namespace wh::rpgmodule::storm
