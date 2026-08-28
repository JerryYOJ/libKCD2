#pragma once
#include <cstddef>
#include <cstdint>
#include "C_EffectBase.h"
#include "E_ValidationMode.h"

namespace wh::xgenaimodule::NPCState {

class C_ChangeUnstanceEffect : public C_EffectBase {
public:
    ~C_ChangeUnstanceEffect() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    RTTR_ENABLE(C_EffectBase)
    std::uint32_t m_targetUnstance;                       // +0x10 RTTR "TargetUnstance"
    std::uint8_t _pad14[4];                               // +0x14
    CryStringT<char> m_fragment;                          // +0x18 RTTR "Fragment"
    CryStringT<char> m_tags;                              // +0x20 RTTR "Tags"
    E_ValidationMode::Type m_validationMode;              // +0x28 RTTR "ValidationMode"
    bool m_requiresExplicitActionRuntimeInit;             // +0x29 RTTR "RequiresExplicitActionRuntimeInit"
    std::uint8_t m_unknown2A[0xE];                        // +0x2A
};

static_assert(offsetof(C_ChangeUnstanceEffect, m_targetUnstance) == 0x10,
              "C_ChangeUnstanceEffect::m_targetUnstance offset mismatch");
static_assert(offsetof(C_ChangeUnstanceEffect, m_fragment) == 0x18,
              "C_ChangeUnstanceEffect::m_fragment offset mismatch");
static_assert(sizeof(C_ChangeUnstanceEffect) == 0x38,
              "C_ChangeUnstanceEffect size mismatch");

}  // namespace wh::xgenaimodule::NPCState
