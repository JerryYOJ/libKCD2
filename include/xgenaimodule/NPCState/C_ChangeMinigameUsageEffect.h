#pragma once
#include <cstddef>
#include <cstdint>
#include "C_EffectBase.h"

namespace wh::xgenaimodule::NPCState {

class C_ChangeMinigameUsageEffect : public C_EffectBase {
public:
    ~C_ChangeMinigameUsageEffect() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    bool unk_04() override;
    bool unk_05() override;
    bool unk_08() override;
    bool unk_09() override;
    RTTR_ENABLE(C_EffectBase)

    std::uint8_t m_unknown10[0x18];                          // +0x10
};

static_assert(sizeof(C_ChangeMinigameUsageEffect) == 0x28,
              "C_ChangeMinigameUsageEffect size mismatch");

}  // namespace wh::xgenaimodule::NPCState
