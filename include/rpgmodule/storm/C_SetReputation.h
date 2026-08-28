#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"
#include "I_Operator.h"

namespace wh::rpgmodule::storm {

class C_SetReputation : public I_Operator {
public:
    ~C_SetReputation() override;
    void unk_01(C_Soul* soul, C_Rule* rule) override;
    bool unk_02() override;
    E_TaskClass unk_03() override;
    void DebugDraw(wh::C_DebugDraw& draw) const override;
    RTTR_ENABLE(I_Operator)
    float m_reputation;                                   // +0x08 RTTR "reputation"
    std::uint8_t _pad0C[4];                               // +0x0C
};

static_assert(sizeof(C_SetReputation) == 0x10, "C_SetReputation size mismatch");

}  // namespace wh::rpgmodule::storm
