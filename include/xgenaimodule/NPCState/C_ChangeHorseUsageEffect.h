#pragma once
#include <cstddef>
#include <cstdint>
#include "C_EffectBase.h"

namespace wh::xgenaimodule::NPCState {

class C_ChangeHorseUsageEffect : public C_EffectBase {
public:
    ~C_ChangeHorseUsageEffect() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    RTTR_ENABLE(C_EffectBase)
    bool m_removesHorseUsage;                             // +0x10 RTTR "RemovesHorseUsage"
    std::uint8_t m_unknown11[0x1F];                       // +0x11
};

static_assert(offsetof(C_ChangeHorseUsageEffect, m_removesHorseUsage) == 0x10,
              "C_ChangeHorseUsageEffect::m_removesHorseUsage offset mismatch");
static_assert(sizeof(C_ChangeHorseUsageEffect) == 0x30,
              "C_ChangeHorseUsageEffect size mismatch");

}  // namespace wh::xgenaimodule::NPCState
