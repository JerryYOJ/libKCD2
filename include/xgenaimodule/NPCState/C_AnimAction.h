#pragma once

#include <cstddef>
#include <cstdint>

#include "C_AnimActionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_AnimAction : public C_AnimActionBase {
public:
    ~C_AnimAction() override;
    RTTR_ENABLE(C_AnimActionBase)                                            // [24..26], vtable 0x183A70820

    std::uint8_t m_unknown1A0[0x50];                                         // +0x1A0
    bool m_requiresMovement;                                                 // +0x1F0 RTTR "RequiresMovement"
    std::uint8_t m_padding1F1[0x1F];                                         // +0x1F1
};

static_assert(offsetof(C_AnimAction, m_requiresMovement) == 0x1F0,
              "C_AnimAction::m_requiresMovement offset mismatch");
static_assert(sizeof(C_AnimAction) == 0x210,
              "C_AnimAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
