#pragma once
#include <cstddef>
#include "C_EffectBase.h"

namespace wh::xgenaimodule::NPCState {

class C_ChangeCombatAutomationsEffect : public C_EffectBase {
public:
    ~C_ChangeCombatAutomationsEffect() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    RTTR_ENABLE(C_EffectBase)
};

static_assert(sizeof(C_ChangeCombatAutomationsEffect) == 0x10,
              "C_ChangeCombatAutomationsEffect size mismatch");

}  // namespace wh::xgenaimodule::NPCState
