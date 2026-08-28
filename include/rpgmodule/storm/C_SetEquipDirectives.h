#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"
#include "I_Operator.h"

namespace wh::rpgmodule::storm {

class C_SetEquipDirectives : public I_Operator {
public:
    ~C_SetEquipDirectives() override;
    void unk_01(C_Soul* soul, C_Rule* rule) override;
    bool unk_02() override;
    E_TaskClass unk_03() override;
    void DebugDraw(wh::C_DebugDraw& draw) const override;
    RTTR_ENABLE(I_Operator)
    bool m_onlyDefault;                                   // +0x08 RTTR "onlyDefault"
    bool m_undressToInventory;                            // +0x09 RTTR "undressToInventory"
    std::uint8_t _pad0A[6];                               // +0x0A
};

static_assert(offsetof(C_SetEquipDirectives, m_onlyDefault) == 0x08,
              "C_SetEquipDirectives::m_onlyDefault offset mismatch");
static_assert(sizeof(C_SetEquipDirectives) == 0x10,
              "C_SetEquipDirectives size mismatch");

}  // namespace wh::rpgmodule::storm
