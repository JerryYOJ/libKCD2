#pragma once
#include <cstddef>
#include <cstdint>
#include "../../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../E_HandType.h"
#include "C_EffectBase.h"
#include "E_HumanHandHelperItemMode.h"
#include "E_ValidationMode.h"
#include "S_EffectObjectEventSource.h"
#include "S_EffectObjectSource.h"

namespace wh::xgenaimodule::NPCState {

class C_ChangeHandContentEffectBase : public C_EffectBase {
public:
    ~C_ChangeHandContentEffectBase() override;                // [0] 0x18067A97C
    bool unk_04() override;                                   // [4] 0x1808FC588
    bool unk_08() override;                                   // [8] 0x181663430
    RTTR_ENABLE(C_EffectBase)                                 // [10..12]
    virtual wh::xgenaimodule::E_HandType::Type unk_13() = 0; // [13]

    bool m_leavesEmpty;                                      // +0x10 RTTR "LeavesEmpty"
    E_ValidationMode::Type m_validationMode;                 // +0x11 RTTR "ValidationMode"
    std::uint8_t _pad12[6];                                  // +0x12
    S_EffectObjectSource m_linkRuntimeInitSource;            // +0x18 RTTR "LinkRuntimeInitSource"
    CryGUID m_expectedItemClass;                             // +0x38 RTTR "ExpectedItemClass"
    S_EffectObjectEventSource m_expectedItemClassEventSource; // +0x48 RTTR "ExpectedItemClassEventSource"
    std::uint8_t m_unknown60[0x1A];                          // +0x60
    E_HumanHandHelperItemMode::Type m_humanHandHelperItemMode; // +0x7A RTTR "HumanHandHelperItemMode"
    std::uint8_t m_unknown7B[5];                             // +0x7B
};

static_assert(offsetof(C_ChangeHandContentEffectBase, m_leavesEmpty) == 0x10,
              "C_ChangeHandContentEffectBase::m_leavesEmpty offset mismatch");
static_assert(offsetof(C_ChangeHandContentEffectBase, m_linkRuntimeInitSource) == 0x18,
              "C_ChangeHandContentEffectBase::m_linkRuntimeInitSource offset mismatch");
static_assert(offsetof(C_ChangeHandContentEffectBase, m_expectedItemClass) == 0x38,
              "C_ChangeHandContentEffectBase::m_expectedItemClass offset mismatch");
static_assert(offsetof(C_ChangeHandContentEffectBase, m_expectedItemClassEventSource) == 0x48,
              "C_ChangeHandContentEffectBase::m_expectedItemClassEventSource offset mismatch");
static_assert(offsetof(C_ChangeHandContentEffectBase, m_humanHandHelperItemMode) == 0x7A,
              "C_ChangeHandContentEffectBase::m_humanHandHelperItemMode offset mismatch");
static_assert(sizeof(C_ChangeHandContentEffectBase) == 0x80,
              "C_ChangeHandContentEffectBase size mismatch");

}  // namespace wh::xgenaimodule::NPCState
