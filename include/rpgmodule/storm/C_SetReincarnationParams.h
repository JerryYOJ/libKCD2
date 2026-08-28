#pragma once
#include <cstddef>
#include <cstdint>
#include <boost/optional.hpp>
#include "../../rttr/rttr_enable.h"
#include "I_Operator.h"

namespace wh::rpgmodule::storm {

class C_SetReincarnationParams : public I_Operator {
public:
    ~C_SetReincarnationParams() override;
    void unk_01(C_Soul* soul, C_Rule* rule) override;
    bool unk_02() override;
    E_TaskClass unk_03() override;
    void DebugDraw(wh::C_DebugDraw& draw) const override;
    RTTR_ENABLE(I_Operator)
    boost::optional<bool> m_varyInventory;                // +0x08 RTTR "varyInventory"
    boost::optional<float> m_combatLevelCoef;             // +0x0C RTTR "combatLevelCoef"
};

static_assert(offsetof(C_SetReincarnationParams, m_varyInventory) == 0x08,
              "C_SetReincarnationParams::m_varyInventory offset mismatch");
static_assert(offsetof(C_SetReincarnationParams, m_combatLevelCoef) == 0x0C,
              "C_SetReincarnationParams::m_combatLevelCoef offset mismatch");
static_assert(sizeof(C_SetReincarnationParams) == 0x18,
              "C_SetReincarnationParams size mismatch");

}  // namespace wh::rpgmodule::storm
