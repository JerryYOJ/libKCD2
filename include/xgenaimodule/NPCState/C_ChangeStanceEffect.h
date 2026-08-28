#pragma once
#include <cstddef>
#include <cstdint>
#include "../../entitymodule/E_StanceCategory.h"
#include "C_EffectBase.h"

namespace wh::xgenaimodule::NPCState {

class C_ChangeStanceEffect : public C_EffectBase {
public:
    ~C_ChangeStanceEffect() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    RTTR_ENABLE(C_EffectBase)
    wh::entitymodule::E_StanceCategory::Type m_targetStance; // +0x10 RTTR "TargetStance"
    bool m_requiresExplicitActionRuntimeInit;             // +0x14 RTTR "RequiresExplicitActionRuntimeInit"
    std::uint8_t m_unknown15[0x1B];                       // +0x15
};

static_assert(offsetof(C_ChangeStanceEffect, m_targetStance) == 0x10,
              "C_ChangeStanceEffect::m_targetStance offset mismatch");
static_assert(sizeof(C_ChangeStanceEffect) == 0x30,
              "C_ChangeStanceEffect size mismatch");

}  // namespace wh::xgenaimodule::NPCState
