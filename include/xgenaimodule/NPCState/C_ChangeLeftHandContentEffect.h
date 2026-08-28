#pragma once
#include <cstddef>
#include <cstdint>
#include "C_ChangeHandContentEffectBase.h"

namespace wh::xgenaimodule::NPCState {

class C_ChangeLeftHandContentEffect : public C_ChangeHandContentEffectBase {
public:
    ~C_ChangeLeftHandContentEffect() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    bool unk_05() override;
    bool unk_09() override;
    RTTR_ENABLE(C_ChangeHandContentEffectBase)
    wh::xgenaimodule::E_HandType::Type unk_13() override;    // returns Left

    bool m_allowLightSourceForValidation;                   // +0x80 RTTR "AllowLightSourceForValidation"
    std::uint8_t m_unknown81[7];                            // +0x81
};

static_assert(offsetof(C_ChangeLeftHandContentEffect, m_allowLightSourceForValidation) == 0x80,
              "C_ChangeLeftHandContentEffect::m_allowLightSourceForValidation offset mismatch");
static_assert(sizeof(C_ChangeLeftHandContentEffect) == 0x88,
              "C_ChangeLeftHandContentEffect size mismatch");

}  // namespace wh::xgenaimodule::NPCState
