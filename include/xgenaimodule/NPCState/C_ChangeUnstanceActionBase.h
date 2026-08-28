#pragma once

#include <cstddef>
#include <cstdint>

#include "C_AnimActionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_ChangeUnstanceActionBase : public C_AnimActionBase {
public:
    ~C_ChangeUnstanceActionBase() override;
    RTTR_ENABLE(C_AnimActionBase)                                            // [24..26], vtable 0x183A2E640

    bool m_requiresRuntimeDataInitFromRequest;                               // +0x1A0 RTTR "RequiresRuntimeDataInitFromRequest"
    bool m_useUrgencyTag;                                                    // +0x1A1 RTTR "UseUrgencyTag"
    std::uint8_t m_padding1A2[6];                                            // +0x1A2
};

static_assert(
    offsetof(C_ChangeUnstanceActionBase, m_requiresRuntimeDataInitFromRequest) ==
        0x1A0,
    "C_ChangeUnstanceActionBase::m_requiresRuntimeDataInitFromRequest offset mismatch");
static_assert(sizeof(C_ChangeUnstanceActionBase) == 0x1A8,
              "C_ChangeUnstanceActionBase size mismatch");

} // namespace wh::xgenaimodule::NPCState
